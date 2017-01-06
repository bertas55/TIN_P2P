//
// Created by lukasz on 06.01.17.
//

#ifndef TIN_P2P_CONFIGURATION_H
#define TIN_P2P_CONFIGURATION_H
#include <string>

class Configuration {
public:
    static const unsigned short getBroadcastPort();
    static const char* getBroadcastIP();

    static const char* getDirectoryPath();

private:
    static unsigned short port;
    static std::string broadcastIP;
    static std::string directoryPath;
    Configuration();
    ~Configuration();

};


#endif //TIN_P2P_CONFIGURATION_H
