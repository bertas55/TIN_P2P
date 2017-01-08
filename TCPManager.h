//
// Created by lukasz on 07.01.17.
//

#ifndef TIN_P2P_TCPMANAGER_H
#define TIN_P2P_TCPMANAGER_H
#include "Connection.h"
#include "FileManager.h"
#include "FileInfoContainer.h"

/**
 * Klasa zarzadzajaca polczeniami TCP
 *
 */
class TCPManager {

public:
    TCPManager(FileManager*, FileInfoContainer*, bool*);
    ~TCPManager();
    void sendFile(File*, char* recieverAddress, unsigned short recieverPort); /*Wysylanie pliku do zadanego hosta*/
    void recieveFile(struct FileInfo*); /*Pobieranie pliku*/


private:
    FileManager *fileManager;
    FileInfoContainer *fileInfoContainer;
    vector<Connection*> connList;
    std::thread id;
    Socket *s;
    bool *exitFlag;

    void connectionAccepter();


};


#endif //TIN_P2P_TCPMANAGER_H
