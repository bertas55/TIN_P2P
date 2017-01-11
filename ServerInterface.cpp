//
// Created by lukasz on 06.01.17.
//

#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include "ServerInterface.h"


//enum UserAction{ RefreshList, DownloadFile, DisableFile, EnableFile, RemoveFile, Exit };
ServerInterface::ServerInterface()
{
    loadConfiguration("");
    debug("Konstuktor ServerInterface::ServerInterface()");
    logContainer = new LogContainer();
    if (!guiDebug()) server = new ServerThread(&container,&fileManager,logContainer);
}

ServerInterface::ServerInterface(LogContainer* lg,string currentPath): logContainer(lg)
{
    loadConfiguration(currentPath);
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
            string fileName;
            string fileSize;
            cout << "File name: ";
            cin >> fileName;
            cout << "File size: ";
            cin >> fileSize;
            disableFile(fileName,fileSize);
            break;
        }
        case (UserAction::EnableFile):
        {
            string fileName;
            string fileSize;
            cout << "File name: ";
            cin >> fileName;
            cout << "File size: ";
            cin >> fileSize;
            enableFile(fileName,fileSize);
            break;
        }
        case (UserAction::RemoveFile):
        {
            string fileName;
            string fileSize;
            cout << "File name: ";
            cin >> fileName;
            cout << "File size: ";
            cin >> fileSize;
            removeFile(fileName,fileSize);
            break;
        }
        case (UserAction::RefreshList):
        {
            refreshList();
            break;
        }
        case (UserAction::DownloadFile):
        {
            string fileName;
            string fileSize;
            cout << "File name: ";
            cin >> fileName;
            cout << "File size: ";
            cin >> fileSize;
            downloadFile(fileName,fileSize);
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
    debug("Wywolano funkcje ServerInterface::downloadFile("+fileName+",");
    if (!guiDebug())container.put(Action(UserAction::DownloadFile, fileName,"", stoul(fileSize)));
}
void ServerInterface::refreshList()
{
    debug("Wywolano funkcje ServerInterface::refreshList()");
    if (!guiDebug()) container.put(Action(UserAction::RefreshList,"","",0));

}
void ServerInterface::enableFile(string fileName,string fileSize)
{
    debug("Wywolano funkcje ServerInterface::enableFile("+fileName+",");
    if (!guiDebug()) container.put(Action(UserAction::EnableFile,fileName,"",stoul(fileSize)));
}
void ServerInterface::disableFile(string fileName,string fileSize)
{
    debug("Wywolano funkcje ServerInterface::disableFile("+fileName+",");
    if (!guiDebug()) container.put(Action(UserAction::DisableFile,fileName,"",stoul(fileSize)));
}
void ServerInterface::userExit()
{
    debug("Wywolano funkcje ServerInterface::userExit");
    if (!guiDebug()) container.put(Action(UserAction::Exit,"","",0));
}

void ServerInterface::removeFile(string fileName, string fileSize) {
    debug("Wywolano funkcje ServerInterface::enableFile("+fileName);
    if (!guiDebug())
        container.put(Action(UserAction::RemoveFile,fileName,"",stoul(fileSize)));
}

void ServerInterface::addFile(string fileName, string filePath) {
    debug("Wywolano funkcje ServerInterface::addFile("+fileName+","+filePath+")");
    if (!guiDebug()) container.put(Action(UserAction::AddFile,fileName,filePath,0));
}

void ServerInterface::revokeFile(string fileName, string fileSize) {
    if (!guiDebug()) container.put(Action(UserAction::RevokeFile,fileName,"",stoul(fileSize)));
}


void ServerInterface::consoleInterface() {
    int myAction;
    do {
//        enum UserAction{ RefreshList, DownloadFile, DisableFile, EnableFile, RemoveFile, AddFile, RevokeFile, Exit };
        cout << "Welcome Pirate!\n";
        cout << "0. RefreshList\n1.DownloadFile\n2.Disbale File\n";
        cout << "3.EnableFile\n4.Remove File\n5.AddFile\n6.RevokeFile" << endl;
        cout << "7. Exit\n";
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

void ServerInterface::setMyIp() {
    int fd;
    struct ifreq ifr;

    fd = socket(AF_INET, SOCK_DGRAM, 0);

    /* I want to get an IPv4 IP address */
    ifr.ifr_addr.sa_family = AF_INET;

    /* I want IP address attached to "eth0" */
    strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1);

    ioctl(fd, SIOCGIFADDR, &ifr);

    close(fd);

    /* display result */
    printf("%s\n", inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
}

void ServerInterface::loadConfiguration(string currentPath) {
    string path;
    if (currentPath.length()==0) path= Constants::Configuration::configPath;
    else path = currentPath + "/" + Constants::Configuration::configPath;
    ifstream infile(path);
    std::string line;
    getline(infile, line);
    std::istringstream iss(line);
    Constants::Configuration::port = stoi(line);

    getline(infile, line);
    Constants::Configuration::TCPort = stoi(line);

    getline(infile, line);
    Constants::Configuration::broadcastIP = new char[line.length()];
    strcpy(Constants::Configuration::broadcastIP, line.c_str());

    getline(infile, line);
    Constants::Configuration::localhostAddress = new char[line.length()];
    strcpy(Constants::Configuration::localhostAddress, line.c_str());
}