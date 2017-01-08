//
// Created by lukasz on 06.01.17.
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
    }

    namespace MessageTypes {
        const char* hello = "Hello";
        const char* requestFile = "RequestFile";
        const char* requestList = "RequestList";
        const char* myList = "MyList";
        const char* newFile = "NewFile";
        const char* veto = "Veto";
        const char* deleteFile = "Delete";
        const char* bye = "Bye";
    }

    namespace File {
        const unsigned int partSize = 256;
    }

    namespace Configuration {
        const unsigned short port = 8888;
        const unsigned short TCPort = 9970;
        const char* broadcastIP = "192.168.0.255";
        const char* directoryPath = "";
        const char* localhostAddress = "127.0.0.1";
    }
}