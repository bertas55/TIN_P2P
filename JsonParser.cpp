//
// Created by hubert on 05.01.17.
//

#include "JsonParser.h"
#include "Exceptions.h"

using namespace std;

Message* JsonParser::parse(string jsonMessage) {
    Message *messageToReturn;
    Json::Value parsedJson;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse(jsonMessage, parsedJson);
    if (parsingSuccessful)
    {
        Json::Value messageTypeVal = parsedJson[Constants::JsonKeys::type];
        const char* messageType = messageTypeVal.asCString();

        if (strcmp(messageType, Constants::MessageTypes::ok) == 0) {
            // hello, is it me you looking for?
            messageToReturn = new MessageOk();
        } else if (strcmp(messageType, Constants::MessageTypes::requestFile) == 0) {
            string hostName = parsedJson[Constants::JsonKeys::hostName].asString();
            string fileName = parsedJson[Constants::JsonKeys::fileName].asString();
            unsigned long fileSize = parsedJson[Constants::JsonKeys::fileSize].asUInt();
            unsigned int offset = parsedJson[Constants::JsonKeys::offset].asUInt();
            messageToReturn = new MessageRequestFile(hostName, fileName, fileSize, offset);
        } else if (strcmp(messageType, Constants::MessageTypes::requestList) == 0) {
            string hostName = parsedJson[Constants::JsonKeys::hostName].asString();
            messageToReturn = new MessageRequestList(hostName);
        } else if (strcmp(messageType, Constants::MessageTypes::myList) == 0) {
            vector<FileInfo> fileInfos;
            messageToReturn = new MessageMyList();
        } else if (strcmp(messageType, Constants::MessageTypes::newFile) == 0) {
            string fileName = parsedJson[Constants::JsonKeys::fileName].asString();
            unsigned long fileSize = parsedJson[Constants::JsonKeys::fileSize].asUInt();
            string hostName = parsedJson[Constants::JsonKeys::hostName].asString();
            messageToReturn = new MessageNewFile(fileName, fileSize, hostName);
        } else if (strcmp(messageType, Constants::MessageTypes::veto) == 0) {
            string fileName = parsedJson[Constants::JsonKeys::fileName].asString();
            unsigned long fileSize = parsedJson[Constants::JsonKeys::fileSize].asUInt();
            messageToReturn = new MessageVeto(fileName, fileSize);
        } else if (strcmp(messageType, Constants::MessageTypes::removedFile) == 0) {
            string fileName = parsedJson[Constants::JsonKeys::fileName].asString();
            unsigned long fileSize = parsedJson[Constants::JsonKeys::fileSize].asUInt();
            string hostName = parsedJson[Constants::JsonKeys::hostName].asString();
            messageToReturn = new MessageFileRemoved(fileName, fileSize, hostName);
        } else if (strcmp(messageType, Constants::MessageTypes::bye) == 0) {
            messageToReturn = new MessageBye();
        } else if (strcmp(messageType, Constants::MessageTypes::denied) == 0) {
            messageToReturn = new MessageDenied();
        } else if (strcmp(messageType, Constants::MessageTypes::revoke) == 0) {
            string fileName = parsedJson[Constants::JsonKeys::fileName].asString();
            unsigned long fileSize = parsedJson[Constants::JsonKeys::fileSize].asUInt();
            messageToReturn = new MessageRevoke(fileName, fileSize);
        } else if (strcmp(messageType, Constants::MessageTypes::myFile) == 0) {
            string fileName = parsedJson[Constants::JsonKeys::fileName].asString();
            unsigned long fileSize = parsedJson[Constants::JsonKeys::fileSize].asUInt();
            string hostName = parsedJson[Constants::JsonKeys::hostName].asString();
            bool owner = parsedJson[Constants::JsonKeys::owner].asBool();
            bool blocked = parsedJson[Constants::JsonKeys::blocked].asBool();
            messageToReturn = new MessageMyFile(fileName, fileSize, hostName, blocked, owner);
        } else {
            throw UnknownMessageException();
        }
    } else {
        throw JsonParsingException();
    }

    return messageToReturn;
}