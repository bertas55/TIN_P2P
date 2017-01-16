//
// Created by Lukasz Niedzwiedz on 07.01.17.
//

#ifndef TIN_P2P_CONNECTION_H
#define TIN_P2P_CONNECTION_H
#include "SocketCreator.h"
#include "Socket.h"
#include "thread"
#include "File.h"
#include "FileManager.h"
#include "FileDownload.h"
#include "LogContainer.h"
#include "FileInfoContainer.h"
#include "Message.h"

/**
 * Klasa reprezentujaca polaczenie TCP
 */
class Connection {

public:
    Connection(LogContainer*,Socket*, FileDownload*);                           // Konstruktor z podanym plikiem do wysylania
    Connection(LogContainer*,Socket*,FileManager*,FileInfoContainer*);            // Konstruktor do odbierania
    Connection(LogContainer*,Socket *s, vector<FileInfo> f);                    // konstruktor do wysylania listy plikow
    Connection(LogContainer*,Socket *s, string fname, unsigned long fsize);     //konstruktor do wysylania veto
    ~Connection();

    void recieveFile(FileDownload*);
    void run();
    void shutdown();

private:
    std::thread threadId;
    FileManager *fileManager;
    LogContainer *logContainer;
    FileInfoContainer *fileInfoContainer;
    int descriptor;
    bool running;
    Socket *sock;
    void interpreteMessage(Message *msg);
    void sendMessage(Message *msg);
    void sendVeto(string fname, unsigned long fsize);
    void sendMyList(vector<FileInfo> f);
    bool receiveFileInfo();
    bool receiveFilePart(FileDownload*, unsigned int,string);
    bool sendFilePart(string, unsigned long, unsigned int);
    Message* receiveMessage();




};


#endif //TIN_P2P_CONNECTION_H