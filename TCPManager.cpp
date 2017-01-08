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

}
TCPManager::~TCPManager()
{

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
            cout << "Uruchamiam polaczenia\n";
            Connection(SocketCreator::CreateSocket(host[i].hostAddress,Constants::Configuration::TCPort,true), &file);
        }
    }

}

void TCPManager::connectionAccepter()
{
    s = SocketCreator::createTCPListener();

    while (!(*exitFlag))
    {
//        @TODO jakies wyjatki?
        Socket *newSocket = s->Accept();
        Connection(newSocket,fileManager);
    }
    delete s;
}