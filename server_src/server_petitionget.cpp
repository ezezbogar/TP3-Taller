#include "server_petitionget.h"
#include <string>

PetitionGet::PetitionGet(char* input,
                         char* output,
                         System& system) :
                         Petition(input, output), system(system) {}

int PetitionGet::solve() {
    if (this->input[5] == ' ') {  // GET sin "resource" especificado
        return  loadRootResource();
    } else {
        return loadRequest();  // GET con "resource" especificado
    }
}

int PetitionGet::loadRootResource() {
    std::string response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
    std::string file = this->system.getFile(system.getRootFile());

    response.copy(this->output, response.size(), 0);
    file.copy(this->output + response.size(), file.size(), 0);

    return (response.size() + file.size());
}

int PetitionGet::loadRequest() {
    std::string resourceName = _getResourceName();
    std::string file = this->system.getFile(resourceName);

    if (!file.empty()) {
        std::string responseOk = "HTTP/1.1 200 OK\n\n";
        responseOk.copy(this->output, responseOk.size(), 0);
        file.copy(this->output + responseOk.size(), file.size(), 0);
        return (responseOk.size() + file.size());
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
