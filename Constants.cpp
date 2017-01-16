//
// Created by Lukasz Niedzwiedz on 06.01.17.
//

#include "Constants.h"

namespace Constants {
    namespace JsonKeys {
        const char* type = "type";
        const char* hostName = "hostName";
        const char* fileName = "fileName";
        const char* fileSize = "fileSize";
        const char* offset = "offset";
        const char* files = "files";
        const char* blocked = "blocked";
        const char* owner = "owner";
        const char* checksum = "checksum";
    }

    namespace MessageTypes {
        const char* ok = "Ok";
        const char* requestFile = "RequestFile";
        const char* requestList = "RequestList";
        const char* myList = "MyList";
        const char* newFile = "NewFile";
        const char* veto = "Veto";
        const char* removedFile = "removedFile";
        const char* bye = "Bye";
        const char* denied = "Denied";
        const char* revoke = "Revoke";
        const char* myFile = "MyFile";
        const char* checksum = "Checksum";
        const unsigned short maxMessageSize = 512;
    }

    namespace File {
        const unsigned int partSize = 256;
    }

    namespace Configuration {
        unsigned short port = 8888;
        unsigned short TCPort = 9970;
        char* broadcastIP = "192.168.0.255";
        char* localhostAddress = "127.0.0.1";
        const char* directoryPath = "";
        const char* downloadPath = "";
        const bool debugMode = true;
        const bool guiTest = false;
        const char* configPath = "config.ini";
    }
}