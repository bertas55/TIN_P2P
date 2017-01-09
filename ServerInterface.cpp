//
// Created by lukasz on 06.01.17.
//

#include <iostream>
#include "ServerInterface.h"


//enum UserAction{ RefreshList, DownloadFile, DisableFile, EnableFile, RemoveFile, Exit };
ServerInterface::ServerInterface()
{

    server = new ServerThread(&container,&fileManager);


}

ServerInterface::ServerInterface(LogContainer* lg)
{

}

ServerInterface::~ServerInterface()
{

    delete server;
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
    container.put(Action(UserAction::DownloadFile, fileName,fileSize,0));
}
void ServerInterface::refreshList()
{
//    container.put(Action(UserAction::RefreshList,fileName,fileSize,0));

}
void ServerInterface::enableFile(string fileName,string fileSize)
{
    container.put(Action(UserAction::EnableFile,fileName,fileSize,0));
}
void ServerInterface::disableFile(string fileName,string fileSize)
{
//    container.put(Action(UserAction::DisableFile,f,0));
}
void ServerInterface::userExit()
{
    container.put(Action(UserAction::Exit,"","",0));
}

void ServerInterface::removeFile(string fileName,string fileSize) {
//    container.put(Action(UserAction::RemoveFile,f,0));
}

void ServerInterface::addFile(string fileName, string filePath) {
    container.put(Action(UserAction::AddFile,fileName,filePath,0));
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