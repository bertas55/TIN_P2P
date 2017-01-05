//
// Created by lukasz on 05.01.17.
//

#include "ServerThread.h"

ServerThread::ServerThread()
{
    UDPBroadcaster = new UDPAdapter(&outputMessage);
    UDPReciver = new UDPAdapter(&inputMessages);
    threadId = std::thread(run());
}
ServerThread::~ServerThread()
{
    delete UDPBroadcaster;
    delete UDPReciver;
    threadId.join();
}

void ServerThread::run()
{
    while(!false==true)
    {

//        if (inputMessages.get()!=nullptr)
//        {
//
//        }

    }

}

void ServerThread::broadcastMessage(Message msg) {
    outputMessage.put(msg);
}