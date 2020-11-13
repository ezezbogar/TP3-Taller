#include "server_petitionget.h"
#include <cstring>
#include <fstream>

PetitionGet::PetitionGet(char* input,
                         char* output,
                         const std::string& resource) :
                         Petition(input, output) {
    this->resource = resource;
}

int PetitionGet::solve() {
    if (this->input[5] == ' ') {  // GET sin "resource" especificado
        return  loadRootResource();
    } else {
        return loadRequest();  // GET con "resource" especificado
    }
}

int PetitionGet::loadRootResource() {
    char c;
    int len = 0;
    char response[] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
    snprintf(this->output, strlen(response) + 1,
             "HTTP/1.1 200 OK\nContent-Type: text/html\n\n");
    std::fstream root;
    root.open(this->resource);

    while (root.get(c)) {
        this->output[strlen(response) + len] = c;
        len++;
    }
    root.close();
    return strlen(response) + len;
}

int PetitionGet::loadRequest() {
    std::string resourceName = _getResourceName();
    if (std::ifstream(resourceName)) {
        char c;
        int len = 0;
        char responseOk[] = "HTTP/1.1 200 OK\n\n";
        snprintf(this->output, strlen(responseOk) + 1, "HTTP/1.1 200 OK\n\n");
        std::fstream root;
        root.open(resourceName);
        while (root.get(c)) {
            this->output[strlen(responseOk) + len] = c;
            len++;
        }
        root.close();
        return strlen(responseOk) + len;
    } else {
        char responseFail[] = "HTTP/1.1 404 NOT FOUND\n\n";
        snprintf(this->output, strlen(responseFail) + 1,
                 "HTTP/1.1 404 NOT FOUND\n\n");
        return strlen(responseFail);
    }
}

std::string PetitionGet::_getResourceName() {
    int pos = 5, len = 0;
    do {
        len++;
        pos++;
    } while (this->input[pos] != ' ');
    std::string name(this->input + 5, len);
    return name;
}

PetitionGet::~PetitionGet() {}
