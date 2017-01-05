//
// Created by lukasz on 05.01.17.
//
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include "WcisloSocket.h"

WcisloSocket::WcisloSocket(int _descriptor) : Socket(_descriptor)
{

}
bool WcisloSocket::Bind(unsigned short port)
{
    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;
    return bind(descriptor, reinterpret_cast<sockaddr*>(&server), sizeof(server)) == 0;
}

bool WcisloSocket::Listen(void)
{
    return listen(descriptor, SOMAXCONN) == 0;
}

Socket* WcisloSocket::Accept(void)
{
    int socketDescriptor = accept(descriptor, nullptr, nullptr);
    if(socketDescriptor == -1)
    {
        return nullptr;
    }
    return new Socket(socketDescriptor);
}