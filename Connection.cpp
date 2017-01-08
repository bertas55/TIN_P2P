//
// Created by lukasz on 07.01.17.
//

#include <sys/socket.h>
#include "Connection.h"
#include "JsonParser.h"

Connection::Connection(Socket *s, FileManager *fm) :
        sock(s),
        running(true) ,
        fileManager(fm)
{
    threadId = std::thread(&Connection::run,this);
}
Connection::Connection(Socket *s , FileDownload *file) : sock(s), running(true)
{
    threadId = std::thread(&Connection::recieveFile,this,file);
}

Connection::~Connection()
{
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
            sock->Receive(buf,Constants::File::partSize);
            file->saveFilePart(part,sizeof(buf),buf);
        }
        else break;
//        hostName niepotrzebny? Download manager, ktory mowi ktora czesc?
//        Pobieranie koejnych numerkow z kontenera, w przypadku niepowodzenia odlozenie?
//        sendMessage(MessageRequestFile( ,file->getName() ,file->getSize(),));
    }
}
/**
 *
 */
void Connection::run()
{
    const unsigned short BUFLEN = 512;
    char buf[BUFLEN];
    while (true)
    {
        sock->Receive(buf,BUFLEN);
        Message *m = JsonParser::parse(buf);
        interpreteMessage(m);
    }
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