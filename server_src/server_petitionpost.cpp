#include "server_petitionpost.h"
#include <iostream>//borrar
#include <cstring>

#define BUF_SIZE 128
#define SMALL_BUF_SIZE 8
#define ERROR -1

PetitionPost::PetitionPost(char* input, char* output, int msgLen) : Petition(input, output) {
    this->msgLen = msgLen;
}

int PetitionPost::solve() {

    std::cout << "petitionpost" <<std::endl;//borrar
    if (this->input[6] == ' ') {
        return _emptyPost();
    } else {
        return _postResource();
    }
}

int PetitionPost::_emptyPost() {
    char response[] = "HTTP/1.1 403 FORBIDDEN\n\n";
    strncpy(this->output, response, strlen(response));
    return strlen(response);
}

int PetitionPost::_postResource() {
    //char response[] = "HTTP/1.1 200 OK\n\n";
    //int bodySize = _getBodySize();
    //bool newLine = false;
    return 0;

}

int PetitionPost::_getBodySize() {
    char cmp[] = "Content-Length";
    char c, buf[BUF_SIZE];
    int pos = 0, i = 0;
    bool lenFound = false;
    while (!lenFound) {
        c = this->input[i];
        pos++;
        i++;
        if (c == '\n') {
            pos = 0;
        } else {
            buf[pos] = c;
        }
        if (pos == static_cast<int>(strlen(cmp)) && strncmp(buf, cmp, strlen(cmp)) == 0){
            return _getNumberBodySize(i);
        }
    }
    return ERROR;
}

int PetitionPost::_getNumberBodySize(int position) {
    char buf[SMALL_BUF_SIZE], c;
    int posBuf = 0;
    do {
        c = this->input[position];
        buf[posBuf] = c;
        posBuf++;
        position++;
    } while (c != ' ');
    buf[posBuf + 1] = '\0';
    return atoi(buf);
}

PetitionPost::~PetitionPost() {}