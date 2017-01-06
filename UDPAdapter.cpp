//
// Created by lukasz on 05.01.17.
//

#include "UDPAdapter.h"
#include "ServerInterface.h"

UDPAdapter::UDPAdapter(MessageContainer *container, WcisloSocket *_socket,bool broadcastEnable) :
        serverMessageContainer(container),
        socket(_socket),
        broadcaster(broadcastEnable)
{
    if (broadcaster){
        socket->setBroadcast();
    }
    else
    {

        socket->setBroadcastListerner();
    }

}
UDPAdapter::~UDPAdapter() {
    delete socket;

}

void UDPAdapter::listen() {

}

void UDPAdapter::send() {

}

void UDPAdapter::run() {
    //socket->Bind();
}