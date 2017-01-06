//
// Created by lukasz on 05.01.17.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include "UDPAdapter.h"
#include "ServerInterface.h"
#include "Exceptions.h"

UDPAdapter::UDPAdapter(MessageContainer *container, WcisloSocket *_socket,bool broadcastEnable) :
        serverMessageContainer(container),
        socket(_socket),
        broadcaster(broadcastEnable)
{
    if (broadcaster){
//        socket->setBroadcast();
        UDPThread = std::thread(&UDPAdapter::send, this);
    }
    else
    {
//        socket->setBroadcastListerner();
        UDPThread = std::thread(&UDPAdapter::listen, this);
    }

}
UDPAdapter::~UDPAdapter() {
    delete socket;
    UDPThread.join();

}

void UDPAdapter::listen() {
    const int BUFLEN = 512;
    int recv_len;
    struct sockaddr_in si_other;
    socklen_t slen = sizeof(si_other);
    char buf[BUFLEN];
    while (true)
    {
        socket->Receive(buf,BUFLEN);
        this_thread::__sleep_for(chrono::seconds(2),chrono::nanoseconds(0));
        cout << buf << endl;
    }



}

void UDPAdapter::send() {
    const int BUFLEN = 512;
    char buf[BUFLEN] = "CHUJ W DUPE POLICJI";
    while(true)
    {
//        Message msg;
//        try {
//            msg = serverMessageContainer->get();
//        } catch(NoElementsException e) {
//            cout << "Chuj w send\n";
//        }

        socket->Send(buf,BUFLEN);
        this_thread::__sleep_for(chrono::seconds(2),chrono::nanoseconds(0));
    }

}

void UDPAdapter::run() {
    //socket->Bind();
}