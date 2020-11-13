#include "server_petitionother.h"
#include <cstring>

PetitionOther::PetitionOther(char* input,
                             char* output) :
                             Petition(input, output) {}

int PetitionOther::solve() {
    char response[] = "HTTP/1.1 405 METHOD NOT ALLOWED\n\n";
    strcpy(this->output, response);
    return strlen(response);
}

PetitionOther::~PetitionOther() {}
