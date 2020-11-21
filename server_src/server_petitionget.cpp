#include "server_petitionget.h"
#include <fstream>//borrar
#include <string>

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
    std::string response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
    response.copy(this->output, response.size(), 0);
    std::fstream root;
    root.open(this->resource);

    while (root.get(c)) {
        this->output[response.size() + len] = c;
        len++;
    }
    root.close();
    return response.size() + len;
}

int PetitionGet::loadRequest() {
    std::string resourceName = _getResourceName();
    if (std::ifstream(resourceName)) {
        char c;
        int len = 0;
        std::string responseOk = "HTTP/1.1 200 OK\n\n";
        responseOk.copy(this->output, responseOk.size(), 0);
        std::fstream root;
        root.open(resourceName);
        while (root.get(c)) {
            this->output[responseOk.size() + len] = c;
            len++;
        }
        root.close();
        return (responseOk.size() + len);
    } else {
        std::string responseFail = "HTTP/1.1 404 NOT FOUND\n\n";
        responseFail.copy(this->output, responseFail.size(), 0);
        return responseFail.size();
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
