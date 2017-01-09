//
// Created by Hubert Kuczyński on 01.01.17.
//
#pragma once
#ifndef TIN_P2P_CONSTANTS_H
#define TIN_P2P_CONSTANTS_H
/*
 * Stale
 */
namespace Constants {
    namespace JsonKeys {
        extern const char* type;
        extern const char* hostName;
        extern const char* fileName;
        extern const char* fileSize;
        extern const char* offset;
        extern const char* files;
        extern const char* blocked;
        extern const char* owner;
    }

    namespace MessageTypes {
        extern const char* ok;
        extern const char* requestFile;
        extern const char* requestList;
        extern const char* myList;
        extern const char* newFile;
        extern const char* veto;
        extern const char* deleteFile;
        extern const char* bye;
        extern const char* denied;
        extern const char* revoke;
    }

    namespace File {
        extern const unsigned int partSize;
    }

    namespace Configuration {
        extern const unsigned short port;
        extern const unsigned short TCPort;
        extern const char* broadcastIP;
        extern const char* directoryPath;
        extern const char* downloadPath;
        extern const char* localhostAddress;
        extern const bool debugMode;
        extern const bool guiTest;
    }
}

#endif //TIN_P2P_CONSTANTS_H
