//
// Created by lukasz on 07.01.17.
//

#include "TCPManager.h"

TCPManager::TCPManager(FileManager* fm, FileInfoContainer*fic,bool *flag) :fileManager(fm), fileInfoContainer(fic), exitFlag(flag)
{

}
TCPManager::~TCPManager()
{

}

void TCPManager::sendFile(File* f, char* recieverAddress, unsigned short recieverPort) /*Wysylanie pliku do zadanego hosta*/
{
    Connection conn(SocketCreator::CreateSocket(recieverAddress,recieverPort,true),f);
    /**
     * Rozpoczyna polaczenie z zadanym portem. Do tego wykorzystywana jest klasa Connection
     */
}
void TCPManager::recieveFile(struct FileInfo*) /*Pobieranie pliku*/
{
    /**
     * Sprawdza liste fileInfoContainer, pobiera z nich adresy zrodel ktore plik posiadaja.
     * Z podanych adresow nawiazuje polaczenie. To powinno robic sie w oddielnym watku.
     * Zarzada ktora czesc, od ktorego hosta pobrac.
     */
}

void TCPManager::connectionAccepter()
{
    s = SocketCreator::createTCPListener();

    while (!(*exitFlag))
    {
//        @TODO jakies wyjatki?
        Socket *newSocket = s->Accept();
        connList.push_back(new Connection(newSocket));
    }
    delete s;
}