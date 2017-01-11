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
        extern const char* checksum;
    }

    namespace MessageTypes {
        extern const char* ok;
        extern const char* requestFile;
        extern const char* requestList;
        extern const char* myList;
        extern const char* newFile;
        extern const char* veto;
        extern const char* removedFile;
        extern const char* bye;
        extern const char* denied;
        extern const char* revoke;
        extern const char* myFile;
        extern const char* checksum;
        extern const unsigned short maxMessageSize;
    }

    namespace File {
        extern const unsigned int partSize;
    }

    namespace Configuration {
        extern unsigned short port;
        extern unsigned short TCPort;
        extern char* broadcastIP;
        extern char* localhostAddress;
        extern const char* directoryPath;
        extern const char* downloadPath;
        extern const bool debugMode;
        extern const bool guiTest;
        extern const char* configPath;
    }
}

#endif //TIN_P2P_CONSTANTS_H
