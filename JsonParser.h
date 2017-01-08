//
// Created by hubert on 05.01.17.
//

#ifndef TIN_P2P_JSONPARSER_H
#define TIN_P2P_JSONPARSER_H


#include "Message.h"
//#include "Constants.h"
#include <iostream>
#include <string>
#include <cstring>
#include "Dependencies/JsonCpp/json/json.h"
#include "JsonCreator.h"

namespace JsonParser {
    Message* parse(string msg);
}


#endif //TIN_P2P_JSONPARSER_H
