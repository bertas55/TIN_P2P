//
// Created by lukasz on 05.01.17.
//

#include "ServerThread.h"
#include "Exceptions.h"
#include <iostream>
ServerThread::ServerThread()
{
    threadId = std::thread(&ServerThread::run,this);
    exitFlag = false;
    UDPBroadcaster = new UDPAdapter(&outputMessage,SocketCreator::broadcasterSenderSocket(), true,&exitFlag);
    UDPReciver = new UDPAdapter(&inputMessages,SocketCreator::broadcasterSocket(), false,&exitFlag);

}
ServerThread::ServerThread(ActionContainer *container, FileManager *fm) : actionContainer(container), fileManager(fm)
{
    exitFlag = false;
    UDPBroadcaster = new UDPAdapter(&outputMessage,SocketCreator::broadcasterSenderSocket(), true,&exitFlag);
    UDPReciver = new UDPAdapter(&inputMessages,SocketCreator::broadcasterSocket(), false,&exitFlag);
    threadId = std::thread(&ServerThread::run,this);
}
ServerThread::~ServerThread()
{
    exitFlag = true;
    sendExitMessage();
    delete UDPBroadcaster;
    delete UDPReciver;
    threadId.detach();
}
/*
 * Glowna petla watku
 */
void ServerThread::run()
{
    while((!false==true) || true)
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
    std::cout<< msg->toString() << "Mesejdz\n";
    switch(msg->type)
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
//            @TODO Wysylanie listy powinno odbyc sie do zadanego wezla
//            broadcastMessage(new MessageMyList());
            std::cout << "Odebrano wiadomosc requestList\n";
            break;
        }
        case(MessageType::veto):{
//            @TODO sprawdzenie czy dany plik zostal przez nas dodany
            std::cout << "Odebrano wiadomosc veto\n";
            break;
        }
        case(MessageType::newFile):{
            std::cout << "Odebrano wiadomosc newFile\n";
//            @TODO sprawdzenie czy plik posiadamy, konstruktor MesseageVeto powinien moc podac nazwe i rozmiar pliku
//            broadcastMessage(MessageVeto());
            break;
        }
        case(MessageType::deleteFile):{
            std::cout << "Odebrano wiadomosc deleteFile\n";
//            @TODO akcja do FileManagera by usunal plik
            break;
        }
        case (MessageType::bye):{

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
//      @TODO Wywolanie funkcji do filemanagera o zablkowanie pliku
            cout << "Wysylam Hello\n";
            broadcastMessage(new MessageHello());
            break;
        }
        case (UserAction::EnableFile):
        {
//      @TODO Wywyloanie funkcji do filemanagera o odblikowanie pliku
            break;
        }
        case (UserAction::RemoveFile):
        {
//        @TODO Wywolanie funkcji do filemanagera o usunieciu pliku, sprawdzenie czy jestesmy wlascicilem
//            broadcastMessage(new MessageDeleteFile());
            cout << "Zakomentowalem bo nie ma arguemntow a nie chce mi sie ich robic\n";
            break;
        }
        case (UserAction::RefreshList):
        {
//          @TODO yyy
            cout << "Wysylam RequestList\n";
            broadcastMessage(new MessageRequestList());
            break;
        }
        case (UserAction::DownloadFile):
        {
//            @TODO
            break;
        }
        case (UserAction::Exit):
        {

            break;
        }
    }

}

void ServerThread::sendInitialMessage()
{
    broadcastMessage(new MessageHello());
}
void ServerThread::sendExitMessage()
{
    broadcastMessage(new MessageBye());
}