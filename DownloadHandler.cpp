//
// Created by lukasz on 11.01.17.
//

#include <iostream>
#include "DownloadHandler.h"
#include "Connection.h"

DownloadHandler::DownloadHandler(std::vector<FileInfo> h,
                                 FileDownload* file,
                                 FileManager* fm,
                                 LogContainer* lc,
                                 bool* exit):
    hosts(h),
    fileManager(fm),
    logContainer(lc),
    exitFlag(exit)
{
    threadId = std::thread(&DownloadHandler::startDownload,this,file);
}
DownloadHandler::~DownloadHandler()
{
    threadId.join();
}

void DownloadHandler::startDownload(FileDownload *file)
{
    for (int i=0; i < hosts.size();++i)
    {
        cout << "Uruchamiam polaczenie z :" << hosts[i].hostAddress << endl;
        Connection *c = new Connection(logContainer, SocketCreator::CreateSocket(hosts[i].hostAddress,Constants::Configuration::TCPort,true), file);
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