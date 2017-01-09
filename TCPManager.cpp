//
// Created by lukasz on 07.01.17.
//

#include <iostream>
#include "TCPManager.h"
#include "FileDownload.h"

TCPManager::TCPManager(FileManager* fm, FileInfoContainer*fic,bool *flag, MessageContainer* mc) :
        fileManager(fm),
        fileInfoContainer(fic),
        exitFlag(flag),
        inputMessages(mc)
{
    id = thread(&TCPManager::connectionAccepter,this);
}
TCPManager::~TCPManager()
{
    id.join();
}

void TCPManager::sendFile(File* f, char* recieverAddress, unsigned short recieverPort) /*Wysylanie pliku do zadanego hosta*/
{
//    Connection conn(SocketCreator::CreateSocket(recieverAddress,recieverPort,true),f);
    /**
     * Rozpoczyna polaczenie z zadanym portem. Do tego wykorzystywana jest klasa Connection
     */
}



void TCPManager::recieveFile(struct FileInfo* fi) /*Pobieranie pliku*/
{
    /**
     * Sprawdza liste fileInfoContainer, pobiera z nich adresy zrodel ktore plik posiadaja.
     * Z podanych adresow nawiazuje polaczenie. To powinno robic sie w oddielnym watku.
     * Zarzada ktora czesc, od ktorego hosta pobrac.
     */
     std::vector<struct FileInfo> host = fileInfoContainer->getAllHostsContains(*fi);
    std::cout << "Zajebisty debuger\n";
    if (host.size()>0)
    {
        FileDownload file(fi->name,fi->size);
        for (int i=0; i < host.size();++i)
        {
            cout << "Uruchamiam polaczenie z :" << host[i].hostAddress << endl;
            Connection *c = new Connection( SocketCreator::CreateSocket(), &file);
//            Connection( SocketCreator::CreateSocket(host[i].hostAddress,Constants::Configuration::TCPort,true), &file);
//            connList.push_back( new Connection( SocketCreator::CreateSocket(host[i].hostAddress,Constants::Configuration::TCPort,true), &file));
//            std::thread(connList.back()->recieveFile,connList.back(), file);
//            std::thread t(&Connection::recieveFile, Connection(SocketCreator::CreateSocket(host[i].hostAddress,Constants::Configuration::TCPort,true), &file),file );
            cout <<"Next\n";
            this_thread::__sleep_for(chrono::seconds(2),chrono::nanoseconds(0));
        }

    }

}

void TCPManager::connectionAccepter()
{
    s = SocketCreator::createTCPListener();

    while (!(*exitFlag))
    {
//        @TODO jakies wyjatki?
//        Socket *newSocket = s->Accept();
        Connection( s->Accept(),fileManager);
        cout << "New connection\n";
    }
    delete s;
}