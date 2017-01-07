//
// Created by lukasz on 05.01.17.
//

#include "ServerThread.h"
#include "Exceptions.h"
#include <iostream>
ServerThread::ServerThread()
{
    exitFlag = false;
    UDPBroadcaster = new UDPAdapter(outputMessage,SocketCreator::broadcasterSenderSocket(), true,&exitFlag);
    UDPReciver = new UDPAdapter(&inputMessages,SocketCreator::broadcasterSocket(), false,&exitFlag);
    threadId = std::thread(&ServerThread::run,this);
}
ServerThread::ServerThread(MessageContainer *container)
{
    exitFlag = false;
    outputMessage = container;
    UDPBroadcaster = new UDPAdapter(outputMessage,SocketCreator::broadcasterSenderSocket(), true,&exitFlag);
    UDPReciver = new UDPAdapter(&inputMessages,SocketCreator::broadcasterSocket(), false,&exitFlag);
    threadId = std::thread(&ServerThread::run,this);
}
ServerThread::~ServerThread()
{
    exitFlag = true;
    cout << "[0]ServerThreadDestruction\n";
    delete UDPBroadcaster;
    cout << "[0.5]ServerThreadDestruction\n";
    delete UDPReciver;
    cout << "[1]ServerThreadDestruction\n";
    threadId.join();
    cout << "[2]ServerThreadDestruction\n";
}
/*
 *     hello,
    handshake,
    requestFile,
    requestList,
    myList,
    newFile,
    veto,
    deleteFile
 */
void ServerThread::run()
{
    while((!false==true) || true)
    {
        try {
            checkForMessages();
        } catch(NoElementsException e)
        {
//            cout << "You don't have any message.\n";
            this_thread::__sleep_for(chrono::seconds(2),chrono::nanoseconds(0));
//            MessageHello msg;
//            outputMessage.put(msg);
        }



    }

}

void ServerThread::broadcastMessage(Message msg) {
    outputMessage->put(msg);
}

void ServerThread::checkForMessages() {
    switch(inputMessages.get().type)
    {
        case(MessageType::hello): {
            std::cout << "Odebrano wiadomosc Hello\n";
            break;
        }
        case(MessageType::handshake):{
            std::cout << "Odebrano wiadomosc Handshake\n";
            break;
        }
        case(MessageType::requestFile):{
            std::cout << "Odebrano wiadomosc RequestFile\n";
            break;
        }
        case(MessageType::myList):{
            std::cout << "Odebrano wiadomosc myList\n";
            break;
        }
        case(MessageType::requestList):{
            std::cout << "Odebrano wiadomosc requestList\n";
            break;
        }
        case(MessageType::veto):{
            std::cout << "Odebrano wiadomosc veto\n";
            break;
        }
        case(MessageType::newFile):{
            std::cout << "Odebrano wiadomosc newFile\n";
            break;
        }
        case(MessageType::deleteFile):{
            std::cout << "Odebrano wiadomosc deleteFile\n";
            break;
        }
        default:
        {
            std::cout << "Odebrano wiadomosc nieznanego typu\n";
            break;
        }
    }
}

void ServerThread::sendInitialMessage()
{
    broadcastMessage(MessageHello());
}
void ServerThread::sendExitMessage()
{
    broadcastMessage(MessageBye());
}