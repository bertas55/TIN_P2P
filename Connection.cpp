//
// Created by lukasz on 07.01.17.
//

#include <sys/socket.h>
#include <unistd.h>
#include "Connection.h"
#include "JsonParser.h"

Connection::Connection(Socket *s, FileManager *fm) :
        sock(s),
        running(true) ,
        fileManager(fm)
{
//    threadId = std::thread(&Connection::run,this);
//    threadId.detach();
}
Connection::Connection(Socket *s , FileDownload *file) : sock(s), running(true)
{

    threadId = std::thread(&Connection::testMethod,this);
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
    while (true)
    {
        long part = file->getPartToDownload();
        if (part!=-1)
        {
            sendMessage(new MessageRequestFile("ZXCZX",file->getName(),file->getSize(),part));
            cout << "Wyslalem wiadomosc\n";
            char buf[Constants::File::partSize];

            int numberOfBytes;
            if (Constants::File::partSize*(part+1) > file->getSize()) numberOfBytes = file->getSize()%Constants::File::partSize;
            else numberOfBytes=Constants::File::partSize;
            sock->Receive(buf,numberOfBytes);
            cout << "Odebralem dane.\n";
            file->saveFilePart(part,numberOfBytes,buf);
        }
        else break;
//        hostName niepotrzebny? Download manager, ktory mowi ktora czesc?
//        Pobieranie koejnych numerkow z kontenera, w przypadku niepowodzenia odlozenie?
//        sendMessage(MessageRequestFile( ,file->getName() ,file->getSize(),));
        this_thread::__sleep_for(chrono::seconds(2),chrono::nanoseconds(0));
    }
}
/**
 *
 */
void Connection::run()
{
    const unsigned short BUFLEN = 512;
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
            sendFile(file,request.offset);
            break;
        }
        case(MessageType::myList):{
//            @TODO Odczytanie listy elementow i zapisanie do listy dostepnych wezlow
            std::cout << "Odebrano wiadomosc myList\n";
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