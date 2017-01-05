//
// Created by lukasz on 05.01.17.
//

#include "SocketCreator.h"
#include <sys/socket.h>

using namespace std;

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
    int descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if(descriptor < 0)
    {
        return nullptr;
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