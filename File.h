//
// Created by hubert on 05.01.17.
//

#ifndef TIN_P2P_FILE_H
#define TIN_P2P_FILE_H

#include <string>
#include <fstream>
using namespace std;

class File {

public:
    File();

    char* getFilePart(unsigned int partNumber);

    string getFileName();

    unsigned int getFileSize();

private:
    fstream file;
    string name;
    unsigned int size;

};


#endif //TIN_P2P_FILE_H
