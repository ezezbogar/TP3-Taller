#include "server_petitionother.h"
#include <cstring>
#include <cstdio>

PetitionOther::PetitionOther(char* input,
                             char* output) :
                             Petition(input, output) {}

int PetitionOther::solve() {
    char response[] = "HTTP/1.1 405 METHOD NOT ALLOWED\n\n";
    snprintf(this->output, strlen(response) + 1,
             "HTTP/1.1 405 METHOD NOT ALLOWED\n\n");
    return strlen(response);
}

PetitionOther::~PetitionOther() {}
