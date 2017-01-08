//
// Created by lukasz on 07.01.17.
//

#include <sys/socket.h>
#include "Connection.h"
#include "JsonParser.h"

Connection::Connection(Socket *s) : sock(s) {

    threadId = std::thread(&Connection::run,this);

}
Connection::Connection(Socket *s , File *file) : sock(s)
{
    threadId = std::thread(&Connection::sendFile,this,file);
}

Connection::~Connection()
{
    threadId.join();
}

void Connection::sendFile(File*)
{
    const unsigned short BUFLEN = 512;
    char buf[BUFLEN];
    sock->Send(buf,BUFLEN);
//    sock->Send(MessageRequestFile());
}
void Connection::recieveFile()
{

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
            std::cout << "Odebrano wiadomosc RequestFile\n";
            break;
        }
        case(MessageType::myList):{
//            @TODO Odczytanie listy elementow i zapisanie do listy dostepnych wezlow
            std::cout << "Odebrano wiadomosc myList\n";
            break;
        }
        case(MessageType::requestList):{
//            @TODO Wysylanie listy powinno odbyc sie do zadanego wezla
            std::cout << "Odebrano wiadomosc requestList\n";
            break;
        }
        case (MessageType::bye):{

            break;
        }
    }
}