#include "server_petitionsolver.h"
#include <cstring>

#define GET 1
#define POST 2
#define OTHER 3

PetitionSolver::PetitionSolver(char* input, char* output, std::string resource) {
    int petitionType = _getPetitionType(input);
    if (petitionType == GET) {
        this->petition = new PetitionGet(input, output, resource);
    } else if (petitionType == POST) {
        this->petition = new PetitionPost(input, output);
    } else if (petitionType == OTHER) {
        this->petition = new PetitionOther(input, output);
    }


}

int PetitionSolver::solve() {
    return this->petition->solve();
}

int PetitionSolver::_getPetitionType(const char* input) {
    if (strncmp(input, "GET", 3) == 0) {
        return GET;
    } else if (strncmp(input, "POST", 4) == 0) {
        return POST;
    } else {
        return OTHER;
    }
}

PetitionSolver::~PetitionSolver() {
    delete this->petition;
}