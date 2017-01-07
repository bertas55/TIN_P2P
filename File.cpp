//
// Created by hubert on 05.01.17.
//

#include "File.h"
#include "Constants.h"
#include <string>
#include <iostream>

using namespace std;

File::File(string path, string name) {
    string fullPath = path + name;
    fstream file(fullPath, std::ios::binary);
    this->name = name;
    this->size = readSize();
}

File::~File() {
    file.close();
}

std::ifstream::pos_type File::readSize()
{
    std::ifstream in(name, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

void File::lock() {
    if (!locked) {
        locked = true;
    } else {
        // throw "is already locked"
    }
}

void File::unlock() {
    if (locked) {
        locked = false;
    } else {
        // throw "is already unlocked"
    }
}

bool File::isLocked() {
    return locked;
}

struct FileInfo File::getFileInfo() {
    return FileInfo(name, size);
}

char* File::getFilePart(unsigned int partNumber) {
    unsigned int offset = partNumber * Constants::File::partSize;
    if (offset + Constants::File::partSize >= size) {
        //throw
    }

    ifstream file;
    file.open("./testFile", ios::in | ios::binary | ios::trunc);
    file.seekg(offset);
    unsigned int readLength, d;
    if ((d = (size - offset)) >= Constants::File::partSize) {
        readLength = Constants::File::partSize;
    } else {
        readLength = d;
    }
    char *buff = new char[readLength];
    file.read(buff, readLength);
    file.close();
    return buff;
}


//fstream binaryIo;
//binaryIo.open(fileName, ios::in | ios::binary | ios::trunc);
//
//binaryIo.read(&size, sizeof(size)); // read the number of elements
//
//myData.resize(size); // allocate memory for an array
//binaryIo.read(myData.data(), size * sizeof(myData.value_type));
//binaryIo.close();




//// open the file:
//std::ifstream file(filename, std::ios::binary);
//
//// Stop eating new lines in binary mode!!!
//file.unsetf(std::ios::skipws);
//
//// get its size:
//std::streampos fileSize;
//
//file.seekg(0, std::ios::end);
//fileSize = file.tellg();
//file.seekg(0, std::ios::beg);
//
//// reserve capacity
//std::vector<BYTE> vec;
//vec.reserve(fileSize);
//
//// read the data:
//vec.insert(vec.begin(),
//        std::istream_iterator<BYTE>(file),
//        std::istream_iterator<BYTE>());

