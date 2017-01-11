//
// Created by lukasz on 07.01.17.
//

#include <iostream>
#include "TCPManager.h"
#include "FileDownload.h"
#include "Exceptions.h"

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
    s->Terminate();
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
    if (seeds>0)
    {
        FileDownload *file = new FileDownload(fi->name, Constants::Configuration::downloadPath, fi->size,seeds);
        for (int i=0; i < host.size();++i)
        {
            cout << "Uruchamiam polaczenie z :" << host[i].hostAddress << endl;
            Connection *c = new Connection(logContainer, SocketCreator::CreateSocket(host[i].hostAddress,Constants::Configuration::TCPort,true), file);
            connList.push_back(c);
            cout <<"Next\n";
            this_thread::__sleep_for(chrono::seconds(2),chrono::nanoseconds(0));
        }
        file->waitUntilFinished();

        if (!(*exitFlag) && file->partsLeftCount()==0)
        {                               //Plik sciagniety pomyslnie
            fileManager->addFile(file);
        }
        else
        {                               //Pobieranie pliku nie ukonczylo sie sukcesem
            if (!(*exitFlag)) logContainer->put(Log(LogType::DownloadFileError, file->getName(), "Pobieranie pliku zakonczylo sie niepowodzeniem.", file->getSize()));
            delete file;
        }
    }
}

void TCPManager::sendMyList(string hostName)
{
    vector<FileInfo> list = fileManager->getFilesList();
    Connection *c = new Connection(logContainer, SocketCreator::CreateSocket(hostName,Constants::Configuration::TCPort,true),fileManager->getFilesList());

}
void TCPManager::sendVeto(string host, string fname, unsigned long fsize)
{

}

void TCPManager::connectionAccepter()
{
    s = SocketCreator::createTCPListener();
    Connection *c;
    Socket *connectionSocket;
    while (!(*exitFlag))
    {
        try {
            connectionSocket = s->Accept();
        } catch (ConnectionException e){
            e.what();
            continue;
        }

        c = new Connection(logContainer, connectionSocket,fileManager,fileInfoContainer);
        connList.push_back(c);
        cout << "New connection\n";
    }
    cout << "TCPListener end\n";
    delete s;
}

