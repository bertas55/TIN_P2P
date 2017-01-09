//
// Created by Hubert Kuczyński on 01.01.17.
//

#include <iostream>
#include<thread>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include "ServerInterface.h"
#include "FileManager.h"

using namespace std;

void userInterface()
{
    ServerInterface serverInterface;
    serverInterface.consoleInterface();
    cout << "Finished!\n";

}

int main(void)
{
    FileManager fileManager;

    vector<FileInfo> files = fileManager.getFilesList();

    MessageMyList myList(files);

    cout << myList.toString() << endl;

//    for (auto fileInfo : files) {
//        cout << fileInfo.name << "\n";
//
//        if (fileInfo)
//    }
//
//    File test("", "testFile");
//
//    cout << "Name " << test.getFileInfo().name << endl;
//
//    char* ret = test.getFilePart(0);
//
//    cout << ret << endl;
//
//    char *x = "X";
//
//    test.saveFilePart(0, 1, x);
//
//    ret = test.getFilePart(0);
//
//    cout << ret << endl;
//
    userInterface();

//    struct ifaddrs *ifap, *ifa;
//    struct sockaddr_in *sa;
//    char *addr;
//
//    getifaddrs (&ifap);
//    for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
//        if (ifa->ifa_addr->sa_family==AF_INET) {
//            sa = (struct sockaddr_in *) ifa->ifa_addr;
//            addr = inet_ntoa(sa->sin_addr);
//            printf("Interface: %s\tAddress: %s\n", ifa->ifa_name, addr);
//        }
//    }
//
//    freeifaddrs(ifap);


    return 0;
}

