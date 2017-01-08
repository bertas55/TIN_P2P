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

UDPAdapter::UDPAdapter(MessageContainer *container, WcisloSocket *_socket,bool broadcastEnable,bool *exit) :
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
        sendMessage(MessageBye());
        cout << "Sender destruction.\n";
    }
    else {
        cout << "Listener destruction.\n";
    }
    delete socket;
    UDPThread.join();
    cout << "[3]";

}

void UDPAdapter::listen() {
    const int BUFLEN = 512;
    int recv_len;
    struct sockaddr_in si_other;
    socklen_t slen = sizeof(si_other);
    char buf[BUFLEN];
    while (!(*exitFlag))
    {
        socket->Receive(buf,BUFLEN);
        serverMessageContainer->put(JsonParser::parse(buf));
        this_thread::__sleep_for(chrono::seconds(2),chrono::nanoseconds(0));
    }
    cout <<"Listend end.\n";


}

void UDPAdapter::send() {

    while(!(*exitFlag))
    {
        Message msg;
        try {
            msg = serverMessageContainer->get();
            sendMessage(msg);
        } catch(NoElementsException e) {
//            cout << "No message in container. Going to sleep for 2 seconds.\n";
            this_thread::__sleep_for(chrono::seconds(2),chrono::nanoseconds(0));
            continue;
        }

    }
    cout <<"Send end.\n";

}

void UDPAdapter::sendMessage(Message msg) {
    const int BUFLEN = 512;
    char buf[BUFLEN];
    strncpy(buf,msg.toString().c_str(),sizeof(buf));
    socket->Send(buf,BUFLEN);
}

void UDPAdapter::run() {
    //socket->Bind();
}