//
// Created by hubert on 05.01.17.
//

#ifndef TIN_P2P_MESSAGE_H
#define TIN_P2P_MESSAGE_H

#include <string>
using namespace std;

enum MessageType {
    hello,
    handshake,
    requestFile,
    requestList,
    myList,
    newFile,
    veto,
    deleteFile
};

struct Message {

    MessageType type;

};

struct MessageHello : Message {
    MessageHello() {
        type = hello;
    }
};

struct MessageHandshake : Message {
    MessageHandshake() {
        type = handshake;
    }
};

struct MessageRequestFile : Message {
    MessageRequestFile() {
        type = requestFile;
    }
};

struct MessageRequestList : Message {
    MessageRequestList() {
        type = requestList;
    }
};

struct MessageMyList : Message {
    MessageMyList() {
        type = myList;
    }
};

struct MessageNewFile : Message {
    MessageNewFile() {
        type = newFile;
    }
};

struct MessageHello : Message {
    MessageHello() {
        type = hello;
    }
};

struct MessageHello : Message {
    MessageHello() {
        type = hello;
    }
};








#endif //TIN_P2P_MESSAGE_H
