#include "server_petitionget.h"
#include <cstring>
#include <fstream>

PetitionGet::PetitionGet(char* input,
                         char* output,
                         std::string resource) :
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
    strcpy(this->output, response);
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
    char c;
    int len = 0;
    std::string resourceName = _getResourceName();
    char responseOk[] = "HTTP/1.1 200 OK\n\n";
    char responseFail[] = "HTTP/1.1 404 NOT FOUND\n\n";
    if (std::ifstream(resourceName)) {
        strcpy(this->output, responseOk);
        std::fstream root;
        root.open(resourceName);
        while (root.get(c)) {
            this->output[strlen(responseOk) + len] = c;
            len++;
        }
        root.close();
        return strlen(responseOk) + len;
    } else {
        strcpy(this->output, responseFail);
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
