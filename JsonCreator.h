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
    std::string requestFile(std::string, std::string, unsigned int, unsigned int);
    // RequestList
    std::string requestList(std::string);
    // MyList
    std::string myList(std::vector<FileInfo>);
    // NewFile
    std::string newFile(std::string, unsigned int, std::string);
    // Veto
    std::string veto(std::string, unsigned int);
    // Delete
    std::string deleteFile(std::string, unsigned int, std::string);
    // Bye
    std::string bye();
    // Denied
    std::string denied();
};


#endif //TIN_P2P_JSONCREATOR_H
