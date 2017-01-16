//
// Created by lukasz on 05.01.17.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include "UDPAdapter.h"
#include "ServerInterface.h"
#include "Exceptions.h"
#include "JsonParser.h"

UDPAdapter::UDPAdapter(MessageContainer *container, UDPSocket *_socket,bool broadcastEnable,bool *exit) :
        serverMessageContainer(container),
        socket(_socket),
        broadcaster(broadcastEnable),
        exitFlag(exit)
{
    if (broadcaster){
        UDPThread = std::thread(&UDPAdapter::send, this);
    }
    else
    {
        UDPThread = std::thread(&UDPAdapter::listen, this);
    }

}
UDPAdapter::~UDPAdapter() {

    if (broadcaster){
        sendMessage(new MessageBye());
    }
    else {
    }
    delete socket;
    UDPThread.join();

}

void UDPAdapter::listen() {
    const int BUFLEN = 512;
    int recv_len;
    struct sockaddr_in si_other;
    socklen_t slen = sizeof(si_other);
    char buf[BUFLEN];
    char* address;
    while (!(*exitFlag))
    {
        address= socket->Receive(buf,BUFLEN);
        try {
            Message *m = JsonParser::parse(buf);
            m->hostName = string(address);
            serverMessageContainer->put(m);
        } catch (JsonParsingException e)
        {
            e.what();
        } catch (UnknownMessageException e)
        {
            e.what();
        }
    }
}

void UDPAdapter::send() {

    while(!(*exitFlag))
    {
        Message *msg;
        try {
            msg = serverMessageContainer->get();
            sendMessage(msg);
        } catch(NoElementsException e) {
            this_thread::__sleep_for(chrono::seconds(1),chrono::nanoseconds(0));
            continue;
        }

    }
}

void UDPAdapter::sendMessage(Message *msg) {
    const int BUFLEN = 512;
    char buf[BUFLEN];
    strncpy(buf,msg->toString().c_str(),sizeof(buf));
    socket->Send(buf,strlen(buf));
}

void UDPAdapter::closeSocket() {
    socket->Terminate();
}