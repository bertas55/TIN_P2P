//
// Created by lukasz on 05.01.17.
//

#include "SocketCreator.h"
#include "Constants.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>

using namespace std;
SocketCreator::SocketCreator()
{}

Socket* SocketCreator::CreateSocket(void)
{
    int descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if(descriptor < 0)
    {
        return nullptr;
    }
    return new Socket(descriptor);
}

Socket* SocketCreator::CreateSocket(const string &address, unsigned short port, bool connect)
{
    Socket* s = CreateSocket();
    if(s == nullptr)
    {
        return nullptr;
    }
    if(connect)
    {
        if(!s->Connect(address, port))
        {
            delete s;
            s = nullptr;
        }
    }
    else
    {
        if(!s->Bind(address, port))
        {
            delete s;
            s = nullptr;
        }
    }
    return s;

}

WcisloSocket* SocketCreator::CreateServerSocket(void)
{
    //
    int descriptor = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    const int BUFLEN = 512;
    struct sockaddr_in si_me, si_other;
    int s , recv_len;
    socklen_t slen = sizeof(si_other);
    char buf[BUFLEN];
    //create a UDP socket
    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
//        die("socket");
    }
    // zero out the structure
    memset((char *) &si_me, 0, sizeof(si_me));

    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(8888);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);

    //bind socket to port
    if( bind(s , (struct sockaddr*)&si_me, sizeof(si_me) ) == -1)
    {
    }
    return new WcisloSocket(descriptor);
}

WcisloSocket* SocketCreator::CreateServerSocket(unsigned short port)
{
    WcisloSocket* s = CreateServerSocket();
    if(s == nullptr)
    {
        return nullptr;
    }
    if(!s->Bind(port))
    {
        delete s;
        s = nullptr;
        return nullptr;
    }
    if(!s->Listen())
    {
        delete s;
        s = nullptr;
    }
    return s;
}

WcisloSocket* SocketCreator::broadcasterSocket(void)
{
    struct sockaddr_in si_me, si_other;
    const int BUFLEN = 512;
    int s , recv_len;
    socklen_t slen = sizeof(si_other);
    char buf[BUFLEN];
    //create a UDP socket
    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
//        die("socket");
    }

    // zero out the structure
    memset((char *) &si_me, 0, sizeof(si_me));

    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(8888);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);

    //bind socket to port
    if( bind(s , (struct sockaddr*)&si_me, sizeof(si_me) ) == -1)
    {
//        die("bind");
    }
    return new WcisloSocket(s);
}
WcisloSocket* SocketCreator::broadcasterSenderSocket(void)
{
    struct sockaddr_in si_other;
    int s, i;
    const int BUFLEN = 512;
    socklen_t slen = sizeof(si_other);
    char buf[BUFLEN];


    if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
//        die("socket");
    }
    int broadcastEnable=1;
    int ret=setsockopt(s, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable));
    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(8888);

    if (inet_aton("192.168.0.255" , &si_other.sin_addr) == 0)
    {
        fprintf(stderr, "inet_aton() failed\n");
    }

    return new WcisloSocket(s);
}


Socket* SocketCreator::createTCPListener()
{
    int sock, length;
    struct sockaddr_in server;
    int msgsock;
    char buf[1024];
    int rval;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
//        @TODO Socket creationException
        perror("opening stream socket");
    }
    Socket *s = new Socket(sock);
    s->Bind(Constants::Configuration::TCPort);
    s->Listen();
    return s;

}