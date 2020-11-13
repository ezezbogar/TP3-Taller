#include "server_petitionpost.h"
#include <fstream>
#include <cstring>
#include <cstdio>

PetitionPost::PetitionPost(char* input,
                           char* output,
                           int msgLen) :
                           Petition(input, output) {
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
    char response[] = "HTTP/1.1 403 FORBIDDEN\n\n";
    snprintf(this->output, strlen(response) + 1, "HTTP/1.1 403 FORBIDDEN\n\n");
    return strlen(response);
}

int PetitionPost::_postResource() {
    char response[] = "HTTP/1.1 200 OK\n\n";
    std::string fileName = _getPostName();
    bool newLine = false;
    snprintf(this->output, strlen(response) + 1, "HTTP/1.1 200 OK\n\n");
    int bodyBegin = 0;

    for (int i = 0; i < this->msgLen; i++) {
        if (this->input[i] == '\n' && newLine == true) {
            _writeFile(i + 1, fileName, strlen(response));
            bodyBegin = i +1;
            break;
        } else if (this->input[i] == '\n') {
            newLine = true;
        } else {
            newLine = false;
        }
    }
    return (strlen(response) + this->msgLen - bodyBegin);
}

void PetitionPost::_writeFile(int bodyStart,
                              std::string fileName,
                              int headerLen) {
    std::ofstream post;
    post.open(fileName);
    for (int i = 0; i < this->msgLen - bodyStart; i++) {
        post << this->input[i + bodyStart];
        this->output[headerLen + i] = this->input[i + bodyStart];
    }
    post.close();
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