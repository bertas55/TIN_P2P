//
// Created by Hubert Kuczyński on 01.01.17.
//

#ifndef TIN_P2P_JSONCREATOR_H
#define TIN_P2P_JSONCREATOR_H

#include <string>
#include <vector>
#include "Constants.h"
#include "File.h"

namespace JsonCreator {
    // Hello
    std::string ok();
    // Handshake
    std::string handshake(std::string);
    // RequestFile
    std::string requestFile(std::string, std::string, unsigned long, unsigned int);
    // RequestList
    std::string requestList(std::string);
    // MyList
    std::string myList(std::vector<FileInfo>);
    // NewFile
    std::string newFile(std::string, unsigned long, std::string);
    // Veto
    std::string veto(std::string, unsigned long);
    // Delete
    std::string deleteFile(std::string, unsigned long, std::string);
    // Bye
    std::string bye();
    // Denied
    std::string denied();
    // Revoke
    std::string revokeFile(std::string, unsigned long);
};


#endif //TIN_P2P_JSONCREATOR_H
