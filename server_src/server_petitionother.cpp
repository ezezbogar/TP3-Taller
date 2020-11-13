#include "server_petitionother.h"
#include <cstring>
#include <cstdio>

PetitionOther::PetitionOther(char* input,
                             char* output) :
                             Petition(input, output) {}

int PetitionOther::solve() {
    char response[] = "HTTP/1.1 405 METHOD NOT ALLOWED\n\n";
    char responseEnd[] = " es un comando desconocido\n";
    snprintf(this->output, strlen(response) + 1,
             "HTTP/1.1 405 METHOD NOT ALLOWED\n\n");
    int pos = 0;
    do {
        pos++;
    } while (this->input[pos] != ' ');
    for (int i = 0; i < pos; i++) {
        this->output[i + strlen(response)] = this->input[i];
    }
    snprintf(this->output + strlen(response) + pos,
             strlen(responseEnd) + 1,
             " es un comando desconocido\n");
    return strlen(response) + pos + strlen(responseEnd);
}

PetitionOther::~PetitionOther() {}
