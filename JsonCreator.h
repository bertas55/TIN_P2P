//
// Created by Hubert Kuczyński on 01.01.17.
//

#ifndef TIN_P2P_JSONCREATOR_H
#define TIN_P2P_JSONCREATOR_H

#include <string>
#include "Constants.h"

namespace JsonCreator {
    // Hello
    std::string hello();
    // Handshake
    std::string handshake(std::string);
    // RequestFile
    std::string requestFile(std::string, std::string, unsigned int, unsigned int);
    // RequestList
    std::string requestList();
    // TODO: MyList
    // NewFile
    std::string newFile(std::string, unsigned int);
    // Veto
    std::string veto(std::string, unsigned int);
    // Delete
    std::string deleteFile(std::string, unsigned int);

};


#endif //TIN_P2P_JSONCREATOR_H
