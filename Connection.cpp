//
// Created by lukasz on 07.01.17.
//

#include <sys/socket.h>
#include "Connection.h"

Connection::Connection(Socket *s) : sock(s) {

//    threadId = std::thread(&Connection::sendFile,this);

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
}
void Connection::recieveFile()
{

}
