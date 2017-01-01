//
// Created by Hubert Kuczyński on 01.01.17.
//

#ifndef TIN_P2P_CONSTANTS_H
#define TIN_P2P_CONSTANTS_H

namespace Constants {
    namespace JsonKeys {
        const char* type = "type";
        const char* hostName = "hostName";
        const char* fileName = "fileName";
        const char* fileSize = "fileSize";
        const char* offset = "offset";
    }

    namespace MessageTypes {
        const char* hello = "Hello";
        const char* requestFile = "RequestFile";
        const char* requestList = "RequestList";
        const char* newFile = "NewFile";
        const char* veto = "Veto";
        const char* deleteFile = "Delete";
    }
}

#endif //TIN_P2P_CONSTANTS_H
