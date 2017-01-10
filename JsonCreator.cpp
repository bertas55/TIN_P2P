//
// Created by Hubert Kuczyński on 01.01.17.
//

#include <string>
#include "JsonCreator.h"
#include "Dependencies/JsonCpp/json/json.h"
#include "File.h"


using namespace std;

namespace JsonCreator {
    string ok() {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::ok;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }

    string handshake(string hostName) {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::ok;
        json[Constants::JsonKeys::hostName] = hostName;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }

    string requestFile(string hostName, string fileName, unsigned long fileSize, unsigned int offset) {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::requestFile;
        json[Constants::JsonKeys::hostName] = hostName;
        json[Constants::JsonKeys::fileName] = fileName;
        json[Constants::JsonKeys::fileSize] = fileSize;
        json[Constants::JsonKeys::offset] = offset;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }

    string requestList(string hostName) {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::requestList;
        json[Constants::JsonKeys::hostName] = hostName;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }

    string myList() {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::myList;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }

    string newFile(string fileName, unsigned long fileSize, string hostName) {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::newFile;
        json[Constants::JsonKeys::fileName] = fileName;
        json[Constants::JsonKeys::fileSize] = fileSize;
        json[Constants::JsonKeys::hostName] = hostName;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }

    string veto(string fileName, unsigned long fileSize) {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::veto;
        json[Constants::JsonKeys::fileName] = fileName;
        json[Constants::JsonKeys::fileSize] = fileSize;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }

    string removedFile(string fileName, unsigned long fileSize, string hostName) {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::removedFile;
        json[Constants::JsonKeys::fileName] = fileName;
        json[Constants::JsonKeys::fileSize] = fileSize;
        json[Constants::JsonKeys::hostName] = hostName;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }

    string bye() {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::bye;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }

    string denied() {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::denied;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }

    string revokeFile(string fileName, unsigned long fileSize) {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::revoke;
        json[Constants::JsonKeys::fileName] = fileName;
        json[Constants::JsonKeys::fileSize] = fileSize;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }

    string myFile(string fileName, unsigned long fileSize, string hostName, bool locked, bool owner) {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::myFile;
        json[Constants::JsonKeys::fileName] = fileName;
        json[Constants::JsonKeys::fileSize] = fileSize;
        json[Constants::JsonKeys::hostName] = hostName;
        json[Constants::JsonKeys::blocked] = locked;
        json[Constants::JsonKeys::owner] = owner;
        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }

    string checksum(string checksum) {
        Json::Value json;
        json[Constants::JsonKeys::type] = Constants::MessageTypes::checksum;
        json[Constants::JsonKeys::checksum] = checksum;

        Json::FastWriter fastWriter;
        return fastWriter.write(json);
    }
}
