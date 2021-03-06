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
    // RequestFile
    std::string requestFile(std::string, std::string, unsigned long, unsigned int);
    // RequestList
    std::string requestList(std::string);
    // MyList
    std::string myList();
    // NewFile
    std::string newFile(std::string, unsigned long, std::string);
    // Veto
    std::string veto(std::string, unsigned long);
    // Delete
    std::string removedFile(std::string, unsigned long, std::string);
    // Bye
    std::string bye();
    // Denied
    std::string denied();
    // Revoke
    std::string revokeFile(std::string, unsigned long);
    // MyFile
    std::string myFile(std::string, unsigned long, std::string, bool, bool);
    // Checksum
    std::string checksum(std::string);
};


#endif //TIN_P2P_JSONCREATOR_H
