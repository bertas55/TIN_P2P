//
// Created by hubert on 05.01.17.
//

#ifndef TIN_P2P_MESSAGEHELLO_H
#define TIN_P2P_MESSAGEHELLO_H

#include "Message.h"

struct MessageHello : Message {
    MessageHello() {
        type = hello;
    }
};


#endif //TIN_P2P_MESSAGEHELLO_H
