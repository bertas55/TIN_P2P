//
// Created by Hubert Kuczyński on 01.01.17.
//
#pragma once
#ifndef TIN_P2P_CONSTANTS_H
#define TIN_P2P_CONSTANTS_H

namespace Constants {
    namespace JsonKeys {
        extern const char* type;
        extern const char* hostName;
        extern const char* fileName;
        extern const char* fileSize;
        extern const char* offset;
    }

    namespace MessageTypes {
        extern const char* hello;
        extern const char* requestFile;
        extern const char* requestList;
        extern const char* newFile;
        extern const char* veto;
        extern const char* deleteFile;
    }

    namespace File {
        extern const unsigned int partSize;
    }
}

#endif //TIN_P2P_CONSTANTS_H
