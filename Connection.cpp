//
// Created by lukasz on 07.01.17.
//

#include <sys/socket.h>
#include <stdlib.h>
#include "Connection.h"
#include "JsonParser.h"
#include "Exceptions.h"

Connection::Connection(LogContainer* l,Socket *s, vector<FileInfo> f):
        logContainer(l),
        sock(s),
        running(true)
{
    threadId = std::thread(&Connection::sendMyList,this,f);
}
Connection::Connection(LogContainer* l,Socket *s, string fname, unsigned long fsize):
        logContainer(l),
        sock(s),
        running(true)
{
    threadId = std::thread(&Connection::sendVeto,this,fname,fsize);
}
Connection::Connection(LogContainer* l,Socket *s, FileManager *fm,FileInfoContainer* f) :
        logContainer(l),
        sock(s),
        running(true) ,
        fileManager(fm),
        fileInfoContainer(f)
{
    threadId = std::thread(&Connection::run,this);
}
Connection::Connection(LogContainer* l,Socket *s , FileDownload *file) :
        logContainer(l),
        sock(s), running(true)
{

    threadId = std::thread(&Connection::recieveFile,this,file);

}


Connection::~Connection()
{
    sendMessage(new MessageBye);
    threadId.join();
    delete sock;
}

void Connection::sendMessage(Message *msg) {

    sock->Send(msg->toString().c_str(),msg->toString().length());
    delete msg;
}

void Connection::recieveFile(FileDownload* file)
{
    Message *msg;
    int attempt = 0;
    while (true)
    {
        long part = file->getPartToDownload();
        if (part!=-1)
        {
            sendMessage(new MessageRequestFile(Constants::Configuration::localhostAddress,file->getName(),file->getSize(),part));
            char buf[Constants::File::partSize];

            msg=receiveMessage();
            if (msg != NULL && msg->type!=MessageType::checksumPart)
            {
                file->addPartToDownload(part);
                break;
            }
            sendMessage(new MessageOk());
            MessageChecksum m = dynamic_cast<MessageChecksum&>(*msg);
            if (!receiveFilePart(file,part,m.checksum)) {
                file->addPartToDownload(part);
                break;
            }
            logContainer->put(Log(LogType::DownloadFileProgres, file->getName(),"", file->getSize()));
        }
        else break;
    }
    sendMessage(new MessageBye());
    file->seedDisconected();
}
/**
 *
 */
void Connection::run()
{
    const unsigned short BUFLEN = Constants::File::partSize;
    char buf[BUFLEN];
    Message *m;
    while (running)
    {
        if (sock==NULL) return;
        if (!sock->Receive(buf,BUFLEN)) break;
        m = JsonParser::parse(buf);
        interpreteMessage(m);
        delete m;
    }
}
/**
 * Funkcja interpretujaca otrzymana wiadomosc. Na podstawie typu wiadomosci okresla dalsze akcje
 * @param msg - wiadomosc
 */
void Connection::interpreteMessage(Message *msg) {
    switch(msg->type)
    {
        case(MessageType::requestFile):{
//            @TODO akcja do TCPManagera by sprawdzil czy dany plik moze byc wyslany i nawiazal polaczenie z wezlem
            MessageRequestFile m = dynamic_cast<MessageRequestFile&>(*msg);
            if(!sendFilePart(m.fileName,m.fileSize,m.offset)) running = false;
            break;
        }
        case(MessageType::myList):{
//            @TODO Odczytanie listy elementow i zapisanie do listy dostepnych wezlow
            std::cout << "Odebrano wiadomosc myList\n";
            if (!receiveFileInfo()) running = false;

            break;
        }
        case(MessageType::veto):
        {
            MessageVeto m = dynamic_cast<MessageVeto&>(*msg);
            if (fileManager->removeFile(m.fileName,m.fileSize)) logContainer->put(Log(LogType::FileVeto, m.fileName,"", m.fileSize));
            running = false;
            break;

        }
        case(MessageType::denied): {
            running = false;
            break;
        }
        case (MessageType::bye):{
            running = false;
            break;
        }
    }
}

void Connection::sendVeto(string fname, unsigned long fsize)
{
    sendMessage(new MessageVeto(fname,fsize));
}
/**
 * Przesylanie informacji o zasobach dostepnych na maszyni.
 * @param vf - wskaznik na wektor plikow, przechowujacy posiadane pliki
 */
void Connection::sendMyList(vector<FileInfo> vf)
{
    const unsigned short BUFLEN =Constants::MessageTypes::maxMessageSize;
    char buf[BUFLEN];
    Message *m;
    unsigned long vsize = vf.size();
    string fileName;
    unsigned long fileSize;
    string hostName = Constants::Configuration::localhostAddress;
    bool locked;
    bool owner;
    for (unsigned long i =0 ; i < vsize ; ++i)
    {
        sendMessage(new MessageMyList());
        m = receiveMessage();
        if (m->type!=MessageType::ok) return;
        fileName = vf[i].name;
        fileSize = vf[i].size;
        locked = vf[i].blocked;
        owner = vf[i].owner;
        sendMessage(new MessageMyFile(fileName,fileSize,hostName,locked,owner));
        m = receiveMessage();
        if (m->type!=MessageType::ok) return;
    }
    sendMessage(new MessageBye());
}

bool Connection::receiveFileInfo()
{
    sendMessage(new MessageOk);
    const unsigned short BUFLEN = Constants::MessageTypes::maxMessageSize;
    char buf[BUFLEN];
    if (sock==NULL) return false;
    if (!sock->Receive(buf,BUFLEN)) return false;
    Message *msg = JsonParser::parse(buf);
    if (msg->type!=MessageType::myFile) return false;
    MessageMyFile m = dynamic_cast<MessageMyFile&>(*msg);
    fileInfoContainer->put(FileInfo(m.fileName,m.fileSize,m.locked,m.owner,m.hostName));
    logContainer->put(Log(LogType::FileAppeared,m.fileName,m.hostName,m.fileSize));
    return true;

}


bool Connection::receiveFilePart(FileDownload* file, unsigned int part, string checksum)
{
    unsigned long numberOfBytes;
    char buf[Constants::File::partSize];
    if (Constants::File::partSize*(part+1) > file->getSize()) numberOfBytes = file->getSize()%Constants::File::partSize;
    else numberOfBytes=Constants::File::partSize;
    sock->Receive(buf,numberOfBytes);
    cout << "Odebralem part nr " << part << endl;
    Data data(buf,stoul(checksum),numberOfBytes);
    try{
        file->saveFilePart(part,numberOfBytes,&data);
    }catch (OutOfRangeException e)
    {
        e.what();
        logContainer->put(Log(LogType::DownloadFileError, file->getName(),e.what() ,file->getSize()));
        return false;
    }catch (LoadingFileException e){
        e.what();
        logContainer->put(Log(LogType::DownloadFileError, file->getName(),e.what() ,file->getSize()));
        return false;
    }catch (ChecksumException e){
        e.what();
        logContainer->put(Log(LogType::DownloadFileError, file->getName(),e.what() ,file->getSize()));
        return false;
    }
    logContainer->put(Log(LogType::DownloadFileProgres, file->getName(),"", file->getSize()));
    return true;

}

bool Connection::sendFilePart(string fileName, unsigned long fileSize, unsigned int offset)
{
    bool success = false;
    File *file = fileManager->getFile(fileName, fileSize);
    if (file == nullptr || file->isLocked()) sendMessage(new MessageDenied());
    else {
        Data data = file->getFilePart(offset);
        sendMessage(new MessageChecksum(std::to_string(data.checksum)));
        Message *m = receiveMessage();
        if (m == NULL) cout << "Suposed to be MessageOk, but message is NULL\n";
        else if (m->type==MessageType::ok) {
            int i = sizeof(data.data);
            sock->Send(data.data, data.size);
            success = true;
        }
    }
    return success;
}

//@TODO wywala sie na message Hello
Message* Connection::receiveMessage()
{
    const unsigned short BUFLEN = Constants::MessageTypes::maxMessageSize;
    char buf[BUFLEN];
    if (sock==NULL) return nullptr;
    if (!sock->Receive(buf,BUFLEN)) return nullptr;
    Message *msg;
    try {
        msg = JsonParser::parse(buf);
    } catch(UnknownMessageException e)
    {
        e.what();
        msg = nullptr;
    }catch(JsonParsingException e)
    {
        e.what();
        msg = nullptr;
    }
    if (msg==NULL) msg = receiveMessage();
    return msg;
}

void Connection::shutdown()
{
    sock->Terminate();
}