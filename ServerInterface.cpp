//
// Created by lukasz on 06.01.17.
//

#include <iostream>
#include "ServerInterface.h"


//enum UserAction{ RefreshList, DownloadFile, DisableFile, EnableFile, RemoveFile, Exit };
ServerInterface::ServerInterface()
{
    debug("Konstuktor ServerInterface::ServerInterface()");
    logContainer = new LogContainer();
    if (!guiDebug()) server = new ServerThread(&container,&fileManager);
}

ServerInterface::ServerInterface(LogContainer* lg): logContainer(lg)
{
    debug("Konstuktor ServerInterface::ServerInterface(LogContainer* lg)");
}

ServerInterface::~ServerInterface()
{
    if (!guiDebug()) {
        delete server;
        delete logContainer;
    }
}

void ServerInterface::putServerAction(UserAction action)
{
    switch (action)
    {
        case (UserAction::DisableFile):
        {
//            disableFile(NULL);
            break;
        }
        case (UserAction::EnableFile):
        {
//            enableFile(NULL);
            break;
        }
        case (UserAction::RemoveFile):
        {
//            removeFile(NULL);
            break;
        }
        case (UserAction::RefreshList):
        {
            refreshList();
            break;
        }
        case (UserAction::DownloadFile):
        {
//            downloadFile(NULL);
            break;
        }
        case (UserAction::Exit):
        {
            userExit();
            break;
        }
    }
}

void ServerInterface::downloadFile(string fileName,string fileSize)
{
    debug("Wywolano funkcje ServerInterface::downloadFile("+fileName+","+fileSize+")");
    if (!guiDebug())container.put(Action(UserAction::DownloadFile, fileName,fileSize,0));
}
void ServerInterface::refreshList()
{
    debug("Wywolano funkcje ServerInterface::refreshList()");
    if (!guiDebug()) container.put(Action(UserAction::RefreshList,"","",0));

}
void ServerInterface::enableFile(string fileName,string fileSize)
{
    debug("Wywolano funkcje ServerInterface::enableFile("+fileName+","+fileSize+")");
    if (!guiDebug()) container.put(Action(UserAction::EnableFile,fileName,fileSize,0));
}
void ServerInterface::disableFile(string fileName,string fileSize)
{
    debug("Wywolano funkcje ServerInterface::disableFile("+fileName+","+fileSize+")");
    if (!guiDebug()) container.put(Action(UserAction::DisableFile,fileName,fileSize,0));
}
void ServerInterface::userExit()
{
    debug("Wywolano funkcje ServerInterface::userExit");
    if (!guiDebug()) container.put(Action(UserAction::Exit,"","",0));
}

void ServerInterface::removeFile(string fileName,string fileSize) {
    debug("Wywolano funkcje ServerInterface::enableFile("+fileName+","+fileSize+")");
    if (!guiDebug())
        container.put(Action(UserAction::RemoveFile,fileName,fileSize,0));
}

void ServerInterface::addFile(string fileName, string filePath) {
    debug("Wywolano funkcje ServerInterface::addFile("+fileName+","+filePath+")");
    if (!guiDebug()) container.put(Action(UserAction::AddFile,fileName,filePath,0));
}

void ServerInterface::consoleInterface() {
    int myAction;
    do {
        cout << "Welcome Pirate!\n";
        cout << "0. RefreshList\n1.DownloadFile\n2.Disbale File\n";
        cout << "3.EnableFile\n4.Remove File\n5.Exit" << endl;
        cin >> myAction;
        putServerAction((UserAction)myAction);
;
    } while (myAction!=UserAction::Exit);
}

void ServerInterface::debug(string message)
{
    if (Constants::Configuration::debugMode) cout << message << endl;
}

bool ServerInterface::guiDebug() {
    return Constants::Configuration::guiTest;
}