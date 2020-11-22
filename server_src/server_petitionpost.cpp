#include "server_petitionpost.h"
#include <fstream>//borrar
#include <string>

PetitionPost::PetitionPost(char* input,
                           char* output,
                           int msgLen,
                           System& system) :
                           Petition(input, output), system(system) {
    this->msgLen = msgLen;
}

int PetitionPost::solve() {
    if (this->input[6] == ' ') {
        return _emptyPost();
    } else {
        return _postResource();
    }
}

int PetitionPost::_emptyPost() {
    std::string response = "HTTP/1.1 403 FORBIDDEN\n\n";
    response.copy(this->output, response.size(), 0);
    return response.size();
}

int PetitionPost::_postResource() {
    std::string response = "HTTP/1.1 200 OK\n\n";
    std::string fileName = _getPostName();
    bool newLine = false;
    int bodyBegin = 0;

    response.copy(this->output, response.size(), 0);
    for (int i = 0; i < this->msgLen; i++) {
        if (this->input[i] == '\n' && newLine == true) {
            _writeFile(i + 1, fileName, response.size());
            bodyBegin = i + 1;
            break;
        } else if (this->input[i] == '\n') {
            newLine = true;
        } else {
            newLine = false;
        }
    }
    return (response.size() + this->msgLen - bodyBegin);
}

void PetitionPost::_writeFile(int bodyStart,
                              std::string fileName,
                              int headerLen) {

    for (int i = 0; i < this->msgLen - bodyStart; i++) {
        this->output[headerLen + i] = this->input[i + bodyStart];
    }
    std::string file(this->input + bodyStart, this->msgLen - bodyStart);
    this->system.loadFile(fileName, file);
}

std::string PetitionPost::_getPostName() {
    int pos = 6, len = 0;
    do {
        len++;
        pos++;
    } while (this->input[pos] != ' ');
    std::string name(this->input + 6, len);
    return name;
}

PetitionPost::~PetitionPost() {}
