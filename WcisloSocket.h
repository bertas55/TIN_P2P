//
// Created by lukasz on 05.01.17.
//

#ifndef TIN_P2P_WCISLOSOCKET_H
#define TIN_P2P_WCISLOSOCKET_H
#include "Socket.h"
/**
 * Class made as contribution to the man who is the best at "Walenie Konia"
 */
class WcisloSocket : protected Socket {

public:
    WcisloSocket(int);
    ~WcisloSocket();
    bool Bind(unsigned short port);
    bool Listen(void);
    Socket* Accept(void);


};


#endif //TIN_P2P_WCISLOSOCKET_H
