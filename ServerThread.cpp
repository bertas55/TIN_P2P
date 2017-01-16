//
// Created by lukasz on 05.01.17.
//

#include "ServerThread.h"
#include "Exceptions.h"
#include <iostream>
#include <cstring>

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
            /*Wiadomosc requestFile powinna przyjsc na TCP, dlatego tutaj nie jest obslugiwana*/
            std::cout << "Odebrano wiadomosc RequestFile\n";
            break;
        }
        case(MessageType::myList):{
            /*Wiadomosc myList powinna przyjsc na TCP, dlatego tutaj nie jest obslugiwana*/
            std::cout << "Odebrano wiadomosc myList\n";
            break;
        }
        case(MessageType::requestList):{
            /*Jako odpowiedz na wiadomosc requestList, tworzymy polaczenie TCP z nadawca i wysylamy mu nasze pliki*/
            tcpManager->sendMyList(msg->hostName);
            std::cout << "Odebrano wiadomosc requestList\n";
            break;
        }
        case(MessageType::veto):{
            /*Wiadomosc veto powinna przyjsc na TCP, dlatego tutaj nie jest obslugiwana*/
            std::cout << "Odebrano wiadomosc veto\n";
            break;
        }
        case(MessageType::newFile):{
            /*Sprawdzamy czy posiadamy plik o takiej samej nazwie i rozmiarze. Jezeli tak, wysylamy na TCP nadawcy wiadomosc veto*/
            std::cout << "Odebrano wiadomosc newFile\n";
            if (msg->hostName!=Constants::Configuration::localhostAddress) {
                MessageNewFile msgNewFile = dynamic_cast<MessageNewFile &>(*msg);
                File *f = fileManager->getFile(msgNewFile.fileName, msgNewFile.fileSize);
                if (f != nullptr) {
                    tcpManager->sendVeto(msgNewFile.hostName, msgNewFile.fileName, msgNewFile.fileSize);
                } else {
                    cout << msgNewFile.toString();
                    fileInfoContainer.put(
                            FileInfo(msgNewFile.fileName, msgNewFile.fileSize, false, false, msg->hostName));
                    logContainer->put(
                            Log(LogType::FileAppeared, msgNewFile.fileName, msg->hostName, msgNewFile.fileSize));
                }
            }
            break;
        }
        case(MessageType::removedFile): {
            /*Sprawdzenie i usuniecie zasobu dostepnego sieciowo*/
            if (msg->hostName != Constants::Configuration::localhostAddress) {
                std::cout << "Odebrano wiadomosc deleteFile\n";
                MessageFileRemoved toRemove = dynamic_cast<MessageFileRemoved &>(*msg);
                if (fileInfoContainer.remove(toRemove.fileName, toRemove.fileSize, msg->hostName))
                    logContainer->put(Log(LogType::FileDisappeared, toRemove.fileName,msg->hostName  ,toRemove.fileSize));
            }
            break;
        }
        case (MessageType::bye):{
            /*Jezeli to nie jest nasz adres, usuwamy pliki dostepne sieciowo od zadanego hosta*/
            if (msg->hostName != Constants::Configuration::localhostAddress)
            {
                FileInfo* f;
                while((f=fileInfoContainer.remove(msg->hostName))!=NULL)
                {
                    logContainer->put(Log(LogType::FileDisappeared, f->name,f->hostAddress  ,f->size));
                }
            }
            break;
        }
        case (MessageType::revokeFile):
        {
            if (msg->hostName!=Constants::Configuration::localhostAddress) {
                MessageRevoke revoke = dynamic_cast<MessageRevoke &>(*msg);
                if (fileManager->removeFile(revoke.fileName, revoke.fileSize)) {
                    logContainer->put(Log(FileRemoved, revoke.fileName, "", revoke.fileSize));
                    broadcastMessage(new MessageFileRemoved(revoke.fileName, revoke.fileSize,
                                                            Constants::Configuration::localhostAddress));
                }
            }
            break;
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
                logContainer->put(Log(LogType::FileBlocked,action.data[0],action.data[1],action.arg));
            }catch(FileNotFoundException e){
                logContainer->put(Log(LogType::ServerError,"Nie znaleziono pliku", "",0));
            }

            broadcastMessage(new MessageOk());
            break;
        }
        case (UserAction::EnableFile):
        {
            try {
                fileManager->unlockFile(action.data[0],action.arg);
                logContainer->put(Log(LogType::FileUnblocked,action.data[0],action.data[1],action.arg));
            }catch(FileNotFoundException e){
                logContainer->put(Log(LogType::ServerError,"Nie znaleziono pliku", "",0));
            }
            break;
        }
        case (UserAction::RemoveFile):
        {
            if (!fileManager->removeFile(action.data[0], action.arg)) logContainer->put(Log(LogType::ServerError,"Nie znaleziono pliku", "",0));
            else broadcastMessage(new MessageFileRemoved(action.data[0],action.arg,Constants::Configuration::localhostAddress));
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
            break;
        }
        case (UserAction::RevokeFile):
        {
            if (fileManager->isOwner(action.data[0],action.arg))
            {
                broadcastMessage(new MessageRevoke(action.data[0],action.arg));
            }
            break;
        }
        case (UserAction::AddFile):
        {
            File* file = fileManager->addFile(action.data[0],action.data[1]);
            if (file!=nullptr)
            {
                cout << "Broadcast AddFile\n";
                broadcastMessage(new MessageNewFile(file->getName(),file->getSize(),Constants::Configuration::localhostAddress));
            }
            break;
        }
        case (UserAction::Exit):
        {
            broadcastMessage(new MessageBye());
            exitFlag = true;
            UDPReciver->closeSocket();
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