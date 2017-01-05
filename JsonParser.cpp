//
// Created by hubert on 05.01.17.
//

#include <iostream>
#include "JsonParser.h"
#include "Dependencies/JsonCpp/json/json.h"

Message JsonParser::parse(string jsonMessage) {
    Json::Value parsedFromString;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse(jsonMessage, parsedFromString);
    if (parsingSuccessful)
    {
        std::cout << styledWriter.write(parsedFromString) << std::endl;
    }
}