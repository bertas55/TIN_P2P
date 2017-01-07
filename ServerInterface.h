//
// Created by lukasz on 06.01.17.
//

#ifndef TIN_P2P_SERVERINTERFACE_H
#define TIN_P2P_SERVERINTERFACE_H
#include "ServerThread.h"
#include "File.h"
#include <string>

enum UserAction{ RefreshList, DownloadFile, DisableFile, EnableFile, RemoveFile, Exit };


class ServerInterface {
public:
    ServerInterface();
    ~ServerInterface();

    void userAction(UserAction);

//    void downloadFile(int index);
//    void refreshList();
//    void enableFile(File);
//    void disableFile(File);
//    void userExit();
//    void getDownloadProgress(File);


private:
    ServerThread *server;
    MessageContainer container;
    string serverPort, clientPort;
    string broadcastAdress;

    void fileManagerAction(UserAction);
    void putServerAction(UserAction);
    bool loadConfig(string);
};


#endif //TIN_P2P_SERVERINTERFACE_H
