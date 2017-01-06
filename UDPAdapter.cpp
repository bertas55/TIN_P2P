//
// Created by lukasz on 05.01.17.
//

#include "UDPAdapter.h"

UDPAdapter::UDPAdapter(MessageContainer *container, WcisloSocket *_socket) : serverMessageContainer(container), socket(_socket)
{

}
UDPAdapter::~UDPAdapter() {
    delete socket;

}

void UDPAdapter::listen() {

}

void UDPAdapter::send() {

}