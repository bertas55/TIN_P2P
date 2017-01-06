//
// Created by Hubert Kuczyński on 01.01.17.
//

#include <string>
#include "JsonCreator.h"
#include "Dependencies/JsonCpp/json/json.h"


using namespace std;

namespace JsonCreator {
    string hello() {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::hello;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }

    string handshake(string hostName) {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::hello;
        json[Constants::JsonKeys::hostName] = hostName;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }

    string requestFile(std::string hostName, std::string fileName, unsigned int fileSize, unsigned int offset) {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::requestFile;
        json[Constants::JsonKeys::hostName] = hostName;
        json[Constants::JsonKeys::fileName] = fileName;
        json[Constants::JsonKeys::fileSize] = fileSize;
        json[Constants::JsonKeys::offset] = offset;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }

    string requestList() {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::requestList;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }

    // TODO: MyList

    std::string newFile(std::string fileName, unsigned int fileSize) {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::newFile;
        json[Constants::JsonKeys::fileName] = fileName;
        json[Constants::JsonKeys::fileSize] = fileSize;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }

    std::string veto(std::string fileName, unsigned int fileSize) {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::veto;
        json[Constants::JsonKeys::fileName] = fileName;
        json[Constants::JsonKeys::fileSize] = fileSize;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }

    std::string deleteFile(std::string fileName, unsigned int fileSize) {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::deleteFile;
        json[Constants::JsonKeys::fileName] = fileName;
        json[Constants::JsonKeys::fileSize] = fileSize;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }
}


