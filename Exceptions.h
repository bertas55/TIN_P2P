//
// Created by hubert on 06.01.17.
//

#ifndef TIN_P2P_EXCEPTIONS_H
#define TIN_P2P_EXCEPTIONS_H

#include <exception>
using namespace std;

struct NoElementsException : public exception {
    const char * what () const throw () {
        return "No elements";
    }
};

struct UnknownMessageException : public exception {
    const char * what () const throw () {
        return "Unknown message type";
    }
};

struct JsonParsingException : public exception {
    const char * what () const throw () {
        return "Json parsing error";
    }
};

struct FileNotFoundException : public exception {
    const char * what () const throw () {
        return "File not found";
    }
};


#endif //TIN_P2P_EXCEPTIONS_H
