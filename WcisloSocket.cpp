//
// Created by lukasz on 05.01.17.
//
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include "WcisloSocket.h"
#include <cstring>
#include <arpa/inet.h>
#include "Constants.h"

WcisloSocket::WcisloSocket(int _descriptor) : Socket(_descriptor)
{
    broadcastEnable = 0;
}
WcisloSocket::~WcisloSocket()
{
    if(!closed)
    {
        Close();
    }
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

    broadcastAddr.sin_family = AF_INET;
    broadcastAddr.sin_port = htons(Constants::Configuration::port);
    broadcastAddr.sin_addr.s_addr = inet_addr(Constants::Configuration::broadcastIP);
    return bind(descriptor,reinterpret_cast<sockaddr*>(&broadcastAddr),sizeof(broadcastAddr))==0;
/* Add other code, sockaddr, sendto() etc. */
}

bool WcisloSocket::setBroadcastListerner() {
    struct sockaddr_in broadcastAddr;
    broadcastAddr.sin_family = AF_INET;
    broadcastAddr.sin_port = htons(Constants::Configuration::port);
    broadcastAddr.sin_addr.s_addr = inet_addr(Constants::Configuration::broadcastIP);
    return bind(descriptor,reinterpret_cast<sockaddr*>(&broadcastAddr),sizeof(broadcastAddr))==0;
}

long WcisloSocket::Send(const char* bytes, unsigned long numberOfBytes)
{
    struct sockaddr_in si_other;
    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(Constants::Configuration::port);

    if (inet_aton(Constants::Configuration::broadcastIP , &si_other.sin_addr) == 0)
    {
        fprintf(stderr, "inet_aton() failed\n");
    }
    int s, i;
    socklen_t slen = sizeof(si_other);
    std::cout << sendto(descriptor,bytes,numberOfBytes,0,(struct sockaddr *) &si_other, slen);
//    sendto(s, message, strlen(message) , 0 , (struct sockaddr *) &si_other, slen
}

//@TODO hostname niech zapisuje do wskznika (+1 arguemnt)
long WcisloSocket::Receive(char* bytes, unsigned long numberOfBytes)
{
    struct sockaddr_in si_other;
    int s, i;
    socklen_t slen = sizeof(si_other);
    if (recvfrom(descriptor, bytes, numberOfBytes, 0, (struct sockaddr *) &si_other, &slen) == -1)
    {
        printf("JAKIESTAM DIE;");
    }
    printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));

    printf("Data: %s\n" , bytes);
}