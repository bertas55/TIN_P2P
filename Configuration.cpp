//
// Created by lukasz on 06.01.17.
//

#include "Configuration.h"

Configuration::Configuration() {
    port = 8888;
    broadcastIP = "127.0.0.1";
}
Configuration::~Configuration() {}

 static const unsigned short Configuration::getBroadcastPort() {
    return  port;
}

 static const char* Configuration::getBroadcastIP() {
    return broadcastIP.c_str();
}