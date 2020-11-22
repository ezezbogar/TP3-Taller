#include "server_system.h"
#include <fstream>
#include <iostream>

#define BUFFER_SIZE 128

System::System(std::string rootFile) {
    std::fstream root;
    std::string file;
    char buf[BUFFER_SIZE];

    this->rootFile = rootFile;
    root.open(rootFile);
    while (!root.eof()) {
        root.read(buf, BUFFER_SIZE);
        file.append(buf, root.gcount());
    }
    root.close();

    this->hardDrive[rootFile] = file;
}

std::string System::getFile(std::string fileName) {
    std::unique_lock<std::mutex> lck(this->FilesMtx);
    std::map<std::string, std::string>::iterator it;
    std::string emptyString;

    it = this->hardDrive.find(fileName);
    if (it != this->hardDrive.end()) {
        return this->hardDrive.find(fileName)->second;
    }
    return emptyString;
}

void System::loadFile(const std::string& fileName, const std::string& file) {
    std::unique_lock<std::mutex> lck(this->FilesMtx);
    this->hardDrive[fileName] = file;
}

void System::printOnScreen(const std::string& str) {
    std::unique_lock<std::mutex> lck(this->stdoutMtx);
    std::cout << str << std::endl;
}

std::string System::getRootFile() {
    return this->rootFile;
}

System::~System() {}
