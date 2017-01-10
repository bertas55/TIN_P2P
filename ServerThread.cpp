//
// Created by lukasz on 05.01.17.
//

#include "ServerThread.h"
#include "Exceptions.h"
#include <iostream>
ServerThread::ServerThread()
{
    logContainer = new LogContainer();
    threadId = std::thread(&ServerThread::run,this);
    exitFlag = false;
    UDPBroadcaster = new UDPAdapter(&outputMessage,SocketCreator::broadcasterSenderSocket(), true,&exitFlag);
    UDPReciver = new UDPAdapter(&inputMessages,SocketCreator::broadcasterSocket(), false,&exitFlag);
    tcpManager = new TCPManager(fileManager,&fileInfoContainer,&exitFlag,&inputMessages,logContainer);

}
ServerThread::ServerThread(ActionContainer *container, FileManager *fm, LogContainer* l) :
        actionContainer(container),
        fileManager(fm),
        logContainer(l)
{
    exitFlag = false;
    UDPBroadcaster = new UDPAdapter(&outputMessage,SocketCreator::broadcasterSenderSocket(), true,&exitFlag);
    UDPReciver = new UDPAdapter(&inputMessages,SocketCreator::broadcasterSocket(), false,&exitFlag);
    tcpManager = new TCPManager(fileManager,&fileInfoContainer,&exitFlag,&inputMessages,logContainer);
    threadId = std::thread(&ServerThread::run,this);
}
ServerThread::~ServerThread()
{

    exitFlag = true;
    sendExitMessage();
    delete UDPBroadcaster;
    delete UDPReciver;
    delete tcpManager;
    threadId.detach();
}
/*
 * Glowna petla watku
 */
void ServerThread::run()
{
    while(!exitFlag)
    {
        try {
            checkForMessages();
        } catch(NoElementsException e)
        {
            this_thread::__sleep_for(chrono::seconds(2),chrono::nanoseconds(0));
        }
        try {
            checkForActions();
        }catch(NoElementsException e)
        {

        }

    }

}
/**
 * Wyslanie wiadomosci poprzez broadcast
 * @param msg
 */
void ServerThread::broadcastMessage(Message *msg) {
    outputMessage.put(msg);
}
/**
 * Sprawdzenie wiadomosci otrzymanych przez siec
 */
void ServerThread::checkForMessages() {

    Message *msg = inputMessages.get();
    switch(msg->type)
    {
        case(MessageType::ok): {
            std::cout << "Odebrano wiadomosc Hello\n";

            break;
        }
        case(MessageType::handshake):{
            std::cout << "Odebrano wiadomosc Handshake\n";
            break;
        }
        case(MessageType::requestFile):{
//            @TODO akcja do TCPManagera by sprawdzil czy dany plik moze byc wyslany i nawiazal polaczenie z wezlem

            std::cout << "Odebrano wiadomosc RequestFile\n";
            break;
        }
        case(MessageType::myList):{
//            @TODO Odczytanie listy elementow i zapisanie do listy dostepnych wezlow
            std::cout << "Odebrano wiadomosc myList\n";
            break;
        }
        case(MessageType::requestList):{
            tcpManager->sendMyList(msg->hostName);
            std::cout << "Odebrano wiadomosc requestList\n";
            break;
        }
        case(MessageType::veto):{
//            @TODO
            std::cout << "Odebrano wiadomosc veto\n";
            break;
        }
        case(MessageType::newFile):{
            std::cout << "Odebrano wiadomosc newFile\n";
//            @TODO sprawdzenie czy plik posiadamy, konstruktor MesseageVeto powinien moc podac nazwe i rozmiar pliku
            MessageNewFile msgNewFile = dynamic_cast<MessageNewFile&>(*msg);
            File *f = fileManager->getFile(msgNewFile.fileName,msgNewFile.fileSize);
            if (f!= nullptr)
            {
                tcpManager->sendVeto(msgNewFile.hostName,msgNewFile.fileName,msgNewFile.fileSize);
            }
//            broadcastMessage(MessageVeto());
            break;
        }
        case(MessageType::removedFile):{
            std::cout << "Odebrano wiadomosc deleteFile\n";
//            fileInfoContainer.remove()
//            @TODO akcja do FileManagera by usunal plik
            break;
        }
        case (MessageType::bye):{
//            @TODO removeAll

            break;
        }
        case (MessageType::revokeFile):
        {
            MessageRevoke revoke = dynamic_cast<MessageRevoke&>(*msg);
            fileManager->removeFile(revoke.fileName,revoke.fileSize);
        }
        default:
        {
            std::cout << "Odebrano wiadomosc nieznanego typu\n";
            break;
        }
    }
}
/**
 * Sprawdzenie dostepnych akcji
 */
void ServerThread::checkForActions() {
    Action action = actionContainer->get();
    switch (action.action)
    {
        case (UserAction::DisableFile):
        {
            try {
                fileManager->lockFile(action.data[0],action.arg);
            }catch(FileNotFoundException e){
                logContainer->put(Log(LogType::ServerError,"Nie znaleziono pliku", "",0));
            }

            broadcastMessage(new MessageOk());
            break;
        }
        case (UserAction::EnableFile):
        {
            try {fileManager->unlockFile(action.data[0],action.arg);
            }catch(FileNotFoundException e){
                logContainer->put(Log(LogType::ServerError,"Nie znaleziono pliku", "",0));
            }
            break;
        }
        case (UserAction::RemoveFile):
        {
            if (!fileManager->removeFile(action.data[0], action.arg)) logContainer->put(Log(LogType::ServerError,"Nie znaleziono pliku", "",0));
            break;
        }
        case (UserAction::RefreshList):
        {
               broadcastMessage(new MessageRequestList(Constants::Configuration::localhostAddress));
            break;
        }
        case (UserAction::DownloadFile):
        {
            FileInfo *fileInfo = fileInfoContainer.has(action.data[0],action.arg);
            if (fileInfo!=nullptr) tcpManager->recieveFile(fileInfo);
            if (fileInfo!=nullptr) tcpManager->recieveFile(fileInfo);
            break;
        }
        case (UserAction::RevokeFile):
        {
            if (fileManager->isOwner(action.data[0],action.arg))
            {
                broadcastMessage(new MessageRevoke(action.data[0],action.arg));
            }
        }
        case (UserAction::Exit):
        {
            broadcastMessage(new MessageBye());
            exitFlag = true;
            break;
        }
    }

}

void ServerThread::sendInitialMessage()
{
    broadcastMessage(new MessageOk());
}
void ServerThread::sendExitMessage()
{
    broadcastMessage(new MessageBye());
}