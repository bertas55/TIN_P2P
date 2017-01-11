//
// Created by hubert on 08.01.17.
//

#include "FileDownload.h"

FileDownload::FileDownload(string name, string path, unsigned int size, unsigned int seeds) :
        File(name, path),
        seedsConnected(seeds)
{
    this->path = path + name;
    this->size = size;
    int partsCount;
    partsCount = (size + Constants::File::partSize - 1) / Constants::File::partSize;
    for (int i = 0; i < partsCount; i++) {
        addPartToDownload(i);
    }
    std::ofstream ofs(name, std::ios::binary | std::ios::out);
    ofs.seekp(size - 1);
    ofs.write("", 1);
}

long FileDownload::getPartToDownload() {
    std::unique_lock<std::mutex> lock(guard);
//    std::lock_guard<std::mutex> lock(guard);
    if (partsLeft.empty()) {
        return -1;
    }
    unsigned int part = partsLeft.front();
    partsLeft.pop();
    lock.unlock();
    return part;
}

unsigned long FileDownload::partsLeftCount() {
    return partsLeft.size();
}

void FileDownload::addPartToDownload(long partNumber) {
    partsLeft.push(partNumber);
}

void FileDownload::seedDisconected() {
    std::unique_lock<std::mutex> lock(guard);
    seedsConnected--;
    lock.unlock();
    if (seedsConnected==0) finished.notify_one();
}

void FileDownload::waitUntilFinished() {
    std::unique_lock<std::mutex> lock(guard);
    finished.wait(lock);
    lock.unlock();
}