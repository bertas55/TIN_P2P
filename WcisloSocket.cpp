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
    broadcastEnable = 0;
}
WcisloSocket::~WcisloSocket()
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

bool WcisloSocket::setBroadcast() {
    broadcastEnable=1;
    int ret=setsockopt(descriptor, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable));
    struct sockaddr_in broadcastAddr;

    unsigned short port = 8888;
    std::string addressIP = "192.168.0.255";

    broadcastAddr.sin_family = AF_INET;
    broadcastAddr.sin_port = htons(port);
    broadcastAddr.sin_addr.s_addr = inet_addr(addressIP.c_str());
    return bind(descriptor,reinterpret_cast<sockaddr*>(&broadcastAddr),sizeof(broadcastAddr))==0;
/* Add other code, sockaddr, sendto() etc. */
}

bool WcisloSocket::setBroadcastListerner() {
    struct sockaddr_in broadcastAddr;
    unsigned short port = 8888;
    std::string addressIP = "192.168.0.255";
    broadcastAddr.sin_family = AF_INET;
    broadcastAddr.sin_port = htons(port);
    broadcastAddr.sin_addr.s_addr = inet_addr(addressIP.c_str());
    return bind(descriptor,reinterpret_cast<sockaddr*>(&broadcastAddr),sizeof(broadcastAddr))==0;
}