//
// Created by lukasz on 07.01.17.
//

#include <sys/socket.h>
#include <unistd.h>
#include "Connection.h"
#include "JsonParser.h"

Connection::Connection(LogContainer* l,Socket *s, vector<FileInfo> f):
        logContainer(l),
        sock(s),
        running(true)
{

}
Connection::Connection(LogContainer* l,Socket *s, string fname, unsigned long fsize):
        logContainer(l),
        sock(s),
        running(true)
{

}
Connection::Connection(LogContainer* l,Socket *s, FileManager *fm,FileInfoContainer* f) :
        logContainer(l),
        sock(s),
        running(true) ,
        fileManager(fm),
        fileInfoContainer(f)
{
    threadId = std::thread(&Connection::run,this);
//    threadId.detach();
}
Connection::Connection(LogContainer* l,Socket *s , FileDownload *file) :
        logContainer(l),
        sock(s), running(true)
{

    threadId = std::thread(&Connection::recieveFile,this,file);
//    threadId.detach();
}

Connection::Connection(LogContainer* l,Socket *s) :
        logContainer(l),
        sock(s),
        running(true)
{
    threadId = std::thread(&Connection::run,this);
//    threadId.detach();
}

Connection::~Connection()
{
    sendMessage(new MessageBye);
    threadId.join();
}

void Connection::sendFile(File* file, int offset)
{

    sock->Send(file->getFilePart(offset), Constants::File::partSize);

}

void Connection::sendMessage(Message *msg) {

    sock->Send(msg->toString().c_str(),512);
}

void Connection::recieveFile(FileDownload* file)
{
    Message *m;
    while (true)
    {
        long part = file->getPartToDownload();
        if (part!=-1)
        {
            sendMessage(new MessageRequestFile(Constants::Configuration::localhostAddress,file->getName(),file->getSize(),part));
            cout << "Wyslalem wiadomosc\n";
            char buf[Constants::File::partSize];

            m=receiveMessage();
            if (m->type!=MessageType::ok) break;
            sendMessage(new MessageOk());
            if (!receiveFilePart(file)) break;

//
//            int numberOfBytes;
//            if (Constants::File::partSize*(part+1) > file->getSize()) numberOfBytes = file->getSize()%Constants::File::partSize;
//            else numberOfBytes=Constants::File::partSize;
//            sock->Receive(buf,numberOfBytes);
//            cout << "Odebralem dane.\n";
//            file->saveFilePart(part,numberOfBytes,buf);
        }
        else break;
    }
    sendMessage(new MessageBye());
}
/**
 *
 */
void Connection::run()
{
    const unsigned short BUFLEN = Constants::File::partSize;
    char buf[BUFLEN];
    Message *m;
    while (true)
    {
        if (sock==NULL) return;
        if (!sock->Receive(buf,BUFLEN)) break;
        m = JsonParser::parse(buf);
        interpreteMessage(m);
    }
    delete m;
}

void Connection::interpreteMessage(Message *msg) {
    switch(msg->type)
    {
        case(MessageType::requestFile):{
//            @TODO akcja do TCPManagera by sprawdzil czy dany plik moze byc wyslany i nawiazal polaczenie z wezlem
            MessageRequestFile request = dynamic_cast<MessageRequestFile&>(*msg);
            File *file = fileManager->getFile(request.fileName, request.fileSize);
            if (file == nullptr) sendMessage(new MessageDenied());
            sendFile(file,request.offset);
            break;
        }
        case(MessageType::myList):{
//            @TODO Odczytanie listy elementow i zapisanie do listy dostepnych wezlow
            std::cout << "Odebrano wiadomosc myList\n";
            receiveFileInfo();

            break;
        }
        case(MessageType::denied): {
//            @TODO Dodanie wiadomosci do logu?

            running = false;
            break;
        }
        case (MessageType::bye):{
            running = false;
            break;
        }
    }
}

void Connection::testMethod() {

    for (int i=0;i<10;i++)
    {
        cout << "dzialam\n";
        this_thread::__sleep_for(chrono::seconds(2),chrono::nanoseconds(0));
    }
}

void Connection::sendVeto(string fname, unsigned long fsize)
{
    sendMessage(new MessageVeto(fname,fsize));
}
void Connection::sendMyList(vector<File>* vf)
{
    const unsigned short BUFLEN = Constants::File::partSize;
    char buf[BUFLEN];
    Message *m;
    unsigned long vsize = vf->size();
    string fileName;
    unsigned long fileSize;
    string hostName = Constants::Configuration::localhostAddress;
    bool locked;
    bool owner;
    for (unsigned long i =0 ; i < vsize ; ++i)
    {
        sendMessage(new MessageMyList());
        if (sock==NULL) return;
        if (!sock->Receive(buf,BUFLEN)) return;
        m = JsonParser::parse(buf);
        if (m->type!=MessageType::ok) return;
        fileName = (*vf)[i].getName();
        fileSize = (*vf)[i].getSize();
        locked = (*vf)[i].isLocked();
        owner = (*vf)[i].isOwner();
        sendMessage(new MessageMyFile(fileName,fileSize,hostName,locked,owner));
        if (sock==NULL) return;
        if (!sock->Receive(buf,BUFLEN)) return;
        m = JsonParser::parse(buf);
        if (m->type!=MessageType::ok) return;
    }
    sendMessage(new MessageBye());
}

bool Connection::receiveFileInfo()
{
    sendMessage(new MessageOk);
    const unsigned short BUFLEN = Constants::File::partSize;
    char buf[BUFLEN];
    if (sock==NULL) return false;
    if (!sock->Receive(buf,BUFLEN)) return false;
    Message *m = JsonParser::parse(buf);

}
bool Connection::receiveFilePart(FileDownload*)
{


}
bool Connection::sendFilePart(File *)
{

}
Message* Connection::receiveMessage()
{

}