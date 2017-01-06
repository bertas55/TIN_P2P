//
// Created by lukasz on 05.01.17.
//

#include "ServerThread.h"
#include <iostream>
ServerThread::ServerThread()
{

    UDPBroadcaster = new UDPAdapter(&outputMessage,SocketCreator::CreateServerSocket());
    UDPReciver = new UDPAdapter(&inputMessages,SocketCreator::CreateServerSocket());
    threadId = std::thread(run());
}
ServerThread::~ServerThread()
{
    delete UDPBroadcaster;
    delete UDPReciver;
    threadId.join();
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
        checkForMessages();


    }

}

void ServerThread::broadcastMessage(Message msg) {
    outputMessage.put(msg);
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