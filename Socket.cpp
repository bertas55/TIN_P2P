//
// Created by Lukasz Niedzwiedz on 05.01.17.
//

#include "Socket.h"
#include "Exceptions.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

Socket::Socket(int _descriptor)
{
    descriptor = _descriptor;
    closed = false;
}

Socket::~Socket(void)
{
    if(!closed)
    {
        Close();
    }
}

bool Socket::Bind(const string &address, unsigned short port)
{
    sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_port = htons(port);
    if(inet_aton(address.c_str(), &client.sin_addr) == 0)
    {
        return false;
    }
    if(bind(descriptor, reinterpret_cast<sockaddr*>(&client), sizeof(client)) != 0)
    {
        return false;
    }
    return true;
}

bool Socket::Bind(unsigned short port)
{
    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;
    return (bind(descriptor, reinterpret_cast<sockaddr*>(&server), sizeof(server)) != 0);
}
bool Socket::Listen()
{
    return listen(descriptor, SOMAXCONN) == 0;
}
Socket* Socket::Accept() {
    int socketDescriptor = accept(descriptor, nullptr, nullptr);
    if(socketDescriptor == -1)
    {
        throw ConnectionException();
    }
    return new Socket(socketDescriptor);
}
bool Socket::Connect(const string &address, unsigned short port)
{
    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if(inet_aton(address.c_str(), &server.sin_addr) == 0)
    {
        return false;
    }
    if(connect(descriptor, reinterpret_cast<sockaddr*>(&server), sizeof(server)) != 0)
    {
        return false;
    }
    return true;
}

long Socket::Send(const char *bytes, unsigned long numberOfBytes)
{
    return write(descriptor, bytes, numberOfBytes);
}

long Socket::Receive(char *bytes, unsigned long numberOfBytes)
{
    return read(descriptor, bytes, numberOfBytes);
}

void Socket::Close(void)
{
    close(descriptor);
    closed = true;
}

void Socket::Terminate() {
    shutdown(descriptor,SHUT_RD);
    Close();
}