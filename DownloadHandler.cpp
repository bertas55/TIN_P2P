//
// Created by Lukasz Niedzwiedz on 11.01.17.
//

#include <iostream>
#include "DownloadHandler.h"
#include "Exceptions.h"

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
/**
 * Funkcja tworzaca polaczenia TCP z hostami posiadajacymi plik.
 * Watek zawiesza sie na zmiennej warunkowej, dopoki wszyskie seedy nie skoncza dzialania
 * @param file - wskaznik na pobierany plik
 */
void DownloadHandler::startDownload(FileDownload *file)
{
    for (int i=0; i < hosts.size();++i)
    {
        cout << "Uruchamiam polaczenie z :" << hosts[i].hostAddress << endl;
        try {
            Socket* s = SocketCreator::CreateSocket(hosts[i].hostAddress,
                                                    Constants::Configuration::TCPort,
                                                    true);
            Connection *c = new Connection(logContainer, s, file);
            conList.push_back(c);
        }catch(ConnectionException e)
        {
            file->seedDisconected();
            e.what();
            continue;
        }
    }
//    @TODO teoretycznie przydaloby sie, by jakos komunikowac innym ze sciagnelismy plik, ale kij z tym. Musza dac refresha, wtedy zobacza.
    file->waitUntilFinished();
    if (*exitFlag) shutdownConnections(); // teoretycznie jezeli dojdzie do tego miejsca, wszystkie polaczenia sa juz zakonczone :|
    cout << "Finished!\n";
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

void DownloadHandler::shutdownConnections() {
    for (unsigned int i = 0 ; i< conList.size() ; ++i)
    {
        if (conList[i]!=NULL) {
            conList[i]->shutdown();
        }
    }

}