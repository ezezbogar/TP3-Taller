#ifndef PETITIONSOLVER_H_
#define PETITIONSOLVER_H_

#define MEMORY_SIZE 1024

#include "server_petition.h"
#include "server_petitionget.h"
#include "server_petitionpost.h"
#include "server_petitionother.h"
#include "../common_src/common_socket.h"
#include "server_thread.h"
#include <string>

class PetitionSolver : Thread {
private:

    char input[MEMORY_SIZE];
    char output[MEMORY_SIZE];
    Petition* petition;

public:
    /* Constructor */
    PetitionSolver(char* input, char* output, std::string resource);

    void solve();

    /* Destructor */
    ~PetitionSolver();

private:
    int _getPetitionType(const char* input);
};

#endif  // PETITIONSOLVER_H_
