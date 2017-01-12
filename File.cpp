//
// Created by hubert on 05.01.17.
//

#include "File.h"
#include "Constants.h"
#include "Exceptions.h"
#include <string>
#include <iostream>
#include <cstring>
#include "Dependencies/CRC.h"

using namespace std;

File::File(string name, string path) {
    this->name = name;
    this->path = path;
    this->size = readSize();
    locked = false;
    owner = true;
    cout << name << path << size;
}

std::ifstream::pos_type File::readSize()
{
    std::ifstream in(path, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

void File::lock() {
    locked = true;
}

void File::unlock() {
    locked = false;
}

bool File::isLocked() {
    return locked;
}

bool File::isOwner() {
    return owner;
}

string File::getName() {
    return name;
}

unsigned long File::getSize() {
    return size;
}

struct FileInfo File::getFileInfo() {
    return FileInfo(name, size, blocked, owner);
}
/**
 * Pobieranie czesci pliku
 * @param partNumber - numer czesci
 * @return - struktura Data, w ktorej zapisane sa dane,rozmiar danych i suma kontrolna
 */
Data File::getFilePart(unsigned int partNumber) {
    std::lock_guard<std::mutex> lock(guard);
    cout << "Get part: " << partNumber << endl;
    if (partNumber==40)
    {
        int j=33+partNumber;
    }
    unsigned int offset = partNumber * Constants::File::partSize;
    if (offset >= size) {
        throw OutOfRangeException();
    }
    string fullPath = path;
    ifstream file(fullPath);
    if (!file.is_open()) {
        throw LoadingFileException();
    }
    file.seekg(offset);
    unsigned int readLength = min(Constants::File::partSize, size - offset);
    char *buff = new char[readLength];
    file.read(buff, readLength);
    file.close();
    unsigned int checksum = genChecksum(buff);
    return Data(buff, checksum,readLength);
}
/**
 * Zapisywanie czesci pliku
 * @param partNumber - numer czesci
 * @param dataLength - rozmiar danych
 * @param data       - zapisane sa dane,rozmiar danych i suma kontrolna
 */
void File::saveFilePart(unsigned int partNumber, unsigned int dataLength, Data* data) {
    std::lock_guard<std::mutex> lock(guard);
    if (partNumber==40)
    {
        int j=33+partNumber;
    }
    unsigned int offset = partNumber * Constants::File::partSize;
    if (offset + dataLength > size) {
        throw OutOfRangeException();
    }
    string fullPath = path;
    ofstream file(fullPath,ios::in | ios::out | ios::binary);
    if (!file.is_open()) {
        throw LoadingFileException();
    }
    if (genChecksum(data->data)!=data->checksum)
    {
        throw ChecksumException();
    }
    file.seekp(offset, ios::beg);
    file.write(data->data, dataLength);
    file.close();
}

/**
 * Generowanie sumy kontrolnej
 * @param data  - bufor dla ktorego generowana jest suma kontrolna
 * @return      - suma kontrolna
 */
unsigned int File::genChecksum(char* data) {
    return CRC::Calculate(data, sizeof(data), CRC::CRC_32());
}
