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

struct LoadingFileException : public exception {
    const char * what () const throw () {
        return "Could not load file";
    }
};

struct OutOfRangeException : public exception {
    const char * what () const throw () {
        return "Tried to access file part that is out of range";
    }
};
struct ConnectionException : public exception
{
    const char * what () const throw () {
        return "Failed to set up TCP connection";
    }
};


#endif //TIN_P2P_EXCEPTIONS_H
