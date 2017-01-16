//
// Created by Lukasz Niedzwiedz on 07.01.17.
//

#include <iostream>
#include "TCPManager.h"
#include "FileDownload.h"
#include "Exceptions.h"
#include "DownloadHandler.h"

TCPManager::TCPManager(FileManager* fm, FileInfoContainer*fic,bool *flag, MessageContainer* mc,LogContainer* l) :
        logContainer(l),
        fileManager(fm),
        fileInfoContainer(fic),
        exitFlag(flag),
        inputMessages(mc)
{
    id = thread(&TCPManager::connectionAccepter,this);
}
TCPManager::~TCPManager()
{
    listenerSocket->Terminate();
    id.join();
}

void TCPManager::recieveFile(struct FileInfo* fi) /*Pobieranie pliku*/
{
    /**
     * Sprawdza liste fileInfoContainer, pobiera z nich adresy zrodel ktore plik posiadaja.
     * Z podanych adresow nawiazuje polaczenie. To powinno robic sie w oddielnym watku.
     * Zarzada ktora czesc, od ktorego hosta pobrac.
     */
    std::vector<struct FileInfo> host = fileInfoContainer->getAllHostsContains(*fi);
    unsigned int seeds = host.size();
    if (host.size()>0)
    {
        FileDownload *file = new FileDownload(fi->name, Constants::Configuration::downloadPath, fi->size,seeds);
        DownloadHandler* downloadHandler = new DownloadHandler(host,file,fileManager,logContainer,exitFlag);
    }
}

void TCPManager::sendMyList(string hostName)
{
    vector<FileInfo> list = fileManager->getFilesList();
    try {
        Socket *connectionSocket = SocketCreator::CreateSocket(hostName, Constants::Configuration::TCPort, true);
        Connection *c = new Connection(logContainer,
                                       connectionSocket,
                                       fileManager->getFilesList());
    }catch(ConnectionException e)
    {
        e.what();
    }

}
void TCPManager::sendVeto(string host, string fname, unsigned long fsize)
{
    try {
        Socket *connectionSocket = SocketCreator::CreateSocket(host, Constants::Configuration::TCPort, true);
        Connection *c = new Connection(logContainer, connectionSocket, fname, fsize);
    }catch(ConnectionException e)
    {
        e.what();
    }
}

void TCPManager::connectionAccepter()
{
    listenerSocket = SocketCreator::createTCPListener();
    Connection *c;
    Socket *connectionSocket;
    while (!(*exitFlag))
    {
        try {
            connectionSocket = listenerSocket->Accept();
        } catch (ConnectionException e){
            e.what();
            continue;
        }

        c = new Connection(logContainer, connectionSocket,fileManager,fileInfoContainer);
        connList.push_back(c);
        cout << "New connection\n";
    }
    if (*exitFlag){
        for (unsigned int i = 0; i < connList.size() ; ++i)
        {
            if (connList[i]!=NULL) connList[i]->shutdown();
        }
    }
    cout << "TCPListener end\n";
    delete listenerSocket;
}
