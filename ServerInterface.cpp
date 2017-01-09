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
#include "ServerInterface.h"


//enum UserAction{ RefreshList, DownloadFile, DisableFile, EnableFile, RemoveFile, Exit };
ServerInterface::ServerInterface()
{
    setMyIp();
    debug("Konstuktor ServerInterface::ServerInterface()");
    logContainer = new LogContainer();
    if (!guiDebug()) server = new ServerThread(&container,&fileManager,logContainer);
}

ServerInterface::ServerInterface(LogContainer* lg): logContainer(lg)
{
    setMyIp();
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
            disableFile("",0);
            break;
        }
        case (UserAction::EnableFile):
        {
            enableFile("",0);
            break;
        }
        case (UserAction::RemoveFile):
        {
            removeFile("",0);
            break;
        }
        case (UserAction::RefreshList):
        {
            refreshList();
            break;
        }
        case (UserAction::DownloadFile):
        {
            downloadFile("",0);
            break;
        }
        case (UserAction::Exit):
        {
            userExit();
            break;
        }
    }
}

void ServerInterface::downloadFile(string fileName,unsigned long fileSize)
{
    debug("Wywolano funkcje ServerInterface::downloadFile("+fileName+",");
    if (!guiDebug())container.put(Action(UserAction::DownloadFile, fileName,"", fileSize));
}
void ServerInterface::refreshList()
{
    debug("Wywolano funkcje ServerInterface::refreshList()");
    if (!guiDebug()) container.put(Action(UserAction::RefreshList,"","",0));

}
void ServerInterface::enableFile(string fileName,unsigned long fileSize)
{
    debug("Wywolano funkcje ServerInterface::enableFile("+fileName+",");
    if (!guiDebug()) container.put(Action(UserAction::EnableFile,fileName,"",fileSize));
}
void ServerInterface::disableFile(string fileName,unsigned long fileSize)
{
    debug("Wywolano funkcje ServerInterface::disableFile("+fileName+",");
    if (!guiDebug()) container.put(Action(UserAction::DisableFile,fileName,"",fileSize));
}
void ServerInterface::userExit()
{
    debug("Wywolano funkcje ServerInterface::userExit");
    if (!guiDebug()) container.put(Action(UserAction::Exit,"","",0));
}

void ServerInterface::removeFile(string fileName, unsigned long fileSize) {
    debug("Wywolano funkcje ServerInterface::enableFile("+fileName);
    if (!guiDebug())
        container.put(Action(UserAction::RemoveFile,fileName,"",fileSize));
}

void ServerInterface::addFile(string fileName, string filePath) {
    debug("Wywolano funkcje ServerInterface::addFile("+fileName+","+filePath+")");
    if (!guiDebug()) container.put(Action(UserAction::AddFile,fileName,filePath,0));
}

void ServerInterface::revokeFile(string fileName, unsigned long fileSize) {
    if (!guiDebug()) container.put(Action(UserAction::RevokeFile,fileName,"",fileSize));
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