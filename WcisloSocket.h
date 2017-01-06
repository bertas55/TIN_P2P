//
// Created by lukasz on 05.01.17.
//

#ifndef TIN_P2P_WCISLOSOCKET_H
#define TIN_P2P_WCISLOSOCKET_H
#include "Socket.h"
#include <string>
#include "Configuration.h"
/**
 * 
 */
class WcisloSocket : protected Socket {

public:
    WcisloSocket(int);
    ~WcisloSocket();
    bool Bind(unsigned short port);
    bool Listen(void);
    Socket* Accept(void);
    bool setBroadcast();
    bool setBroadcastListerner();

private:
    int broadcastEnable;

};


#endif //TIN_P2P_WCISLOSOCKET_H
