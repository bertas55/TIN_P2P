//
// Created by lukasz on 07.01.17.
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

/**
 * Klasa reprezentujaca polaczenie TCP
 */
class Connection {

public:
    Connection(LogContainer*,Socket*, FileDownload*);     // Konstruktor z podanym plikiem do wysylania
    Connection(LogContainer*,Socket*,FileManager*,FileInfoContainer*);            // Konstruktor do odbierania
    Connection(LogContainer*,Socket*);
    Connection(LogContainer*,Socket *s, vector<FileInfo> f); // konstruktor do wysylania listy plikow
    Connection(LogContainer*,Socket *s, string fname, unsigned long fsize); //konstruktor do wysylania veto
    ~Connection();

    void sendFile(File*, int);
    void recieveFile(FileDownload*);
    void run();

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
    void testMethod();
    void sendVeto(string fname, unsigned long fsize);
    void sendMyList(vector<File>* vf);
    bool receiveFileInfo();
    bool receiveFilePart(FileDownload*);
    bool sendFilePart(File *);
    Message* receiveMessage();




};


#endif //TIN_P2P_CONNECTION_H
