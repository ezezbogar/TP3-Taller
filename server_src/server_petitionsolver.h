#ifndef SERVER_SRC_SERVER_PETITIONSOLVER_H_
#define SERVER_SRC_SERVER_PETITIONSOLVER_H_

#include "server_petition.h"
#include "server_petitionget.h"
#include "server_petitionpost.h"
#include "server_petitionother.h"
#include <string>

class PetitionSolver {
 private:
    Petition* petition;

 public:
    /* Constructor */
    PetitionSolver(char* input, char* output, std::string resource, int msgLen);

    int solve();

    /* Destructor */
    ~PetitionSolver();

 private:
    int _getPetitionType(const char* input);
};

#endif  // SERVER_SRC_SERVER_PETITIONSOLVER_H_
