//
// Created by Lukasz Niedzwiedz on 07.01.17.
//

#ifndef TIN_P2P_TCPMANAGER_H
#define TIN_P2P_TCPMANAGER_H
#include "Connection.h"
#include "FileManager.h"
#include "FileInfoContainer.h"
#include "MessageContainer.h"
#include "LogContainer.h"

/**
 * Klasa zarzadzajaca polczeniami TCP.
 * Tworzy watek sluchacza TCP, ktory akceptuje polaczenia.
 * Tworzy watki zarzadcy pobierania (DownloadHandler).
 */
class TCPManager {

public:
    TCPManager(FileManager*, FileInfoContainer*, bool*, MessageContainer*, LogContainer*);
    ~TCPManager();
    void recieveFile(struct FileInfo*); /*Pobieranie pliku*/
    void sendMyList(string hostName);
    void sendVeto(string host, string fname, unsigned long fsize);


private:
    FileManager *fileManager;
    FileInfoContainer *fileInfoContainer;
    MessageContainer* inputMessages;
    LogContainer *logContainer;
    vector<Connection*> connList;
    std::thread id;
    Socket *listenerSocket;
    bool *exitFlag;

    void connectionAccepter();


};


#endif //TIN_P2P_TCPMANAGER_H
