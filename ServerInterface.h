//
// Created by lukasz on 06.01.17.
//

#ifndef TIN_P2P_SERVERINTERFACE_H
#define TIN_P2P_SERVERINTERFACE_H
#include "ServerThread.h"
#include "File.h"
#include <string>
#include "ActionContainer.h"
#include "FileManager.h"
#include "LogContainer.h"

/**
 * Interfejs do serwera.
 */
class ServerInterface {
public:
    ServerInterface();
    ServerInterface(string currentPath);                         // W gui z tego korzystac
    ~ServerInterface();

    void consoleInterface();
    void downloadFile(string fileName,string fileSize);     // Wywylanie w momencie, gdy uzytkownik wybierze z listy plik do pobrania
    void refreshList();                                            // W momencie wywolania czyszczona jest lista dostepnych plikow sieciowo w GUI, pliki beda sie pojawiac poprzez odczytanie odpowiedniego logu
    void enableFile(string fileName,string fileSize);       // Wywolanie w momencie gdy uzytkownik odblkouje plik
    void disableFile(string fileName,string fileSize);      // Wywolanie w momencie gdy uzytkownik zablkouje plik
    void addFile(string fileName, string filePath);                // Wywlanie w momencie gdy dodawany jest plik
    void userExit();                                               // wywolane w momencie gdy uzytkownik konczy dzialanie programu
    void removeFile(string fileName,string fileSize);       // Wywlane, gdy uzytkownik usuwa wlasny plik
    void revokeFile(string fileName,string fileSize);       // Wywolane gdy uzytkownik chce uniewaznic plik
    void loadConfiguration(string);
    LogContainer* getLogContainer();

private:
    ServerThread *server;
    FileManager fileManager;
    ActionContainer container;
    LogContainer *logContainer;
    string serverPort, clientPort;
    string broadcastAdress;

    void putServerAction(UserAction);
    void debug(string);
    bool guiDebug();
    void setMyIp();
    void test();
};


#endif //TIN_P2P_SERVERINTERFACE_H
