//
// Created by lukasz on 06.01.17.
//

#ifndef TIN_P2P_CONFIGURATION_H
#define TIN_P2P_CONFIGURATION_H
#include <string>

class Configuration {
public:
     static unsigned short getBroadcastPort();
     static std::string getBroadcastIP();

private:
//    static unsigned short port = 8888;
//    static std::string broadcastIP = "127.0.0.1";
    Configuration();
    Configuration(Configuration const&);
    Configuration& operator=(Configuration const&);
    ~Configuration();

};


#endif //TIN_P2P_CONFIGURATION_H
