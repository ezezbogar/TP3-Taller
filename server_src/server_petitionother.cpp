#include "server_petitionother.h"
#include <string>

PetitionOther::PetitionOther(char* input,
                             char* output) :
                             Petition(input, output) {}

int PetitionOther::solve() {
    std::string responseBegin = "HTTP/1.1 405 METHOD NOT ALLOWED\n\n";
    std::string responseEnd = " es un comando desconocido\n";
    responseBegin.copy(this->output, responseBegin.size(), 0);
    int pos = 0;
    do {
        pos++;
    } while (this->input[pos] != ' ');
    for (int i = 0; i < pos; i++) {
        this->output[i + responseBegin.size()] = this->input[i];
    }
    responseEnd.copy(this->output + pos + responseBegin.size()
                     , responseEnd.size(), 0);
    return responseBegin.size() + pos + responseEnd.size();
}

PetitionOther::~PetitionOther() {}
