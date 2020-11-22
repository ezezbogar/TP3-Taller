#ifndef SERVER_SRC_SERVER_PETITIONSOLVER_H_
#define SERVER_SRC_SERVER_PETITIONSOLVER_H_

#include "server_petition.h"
#include "server_petitionget.h"
#include "server_petitionpost.h"
#include "server_petitionother.h"
#include "server_system.h"
#include <string>

class PetitionSolver {
 private:
    Petition* petition;

 public:
    /* Constructor */
    PetitionSolver(char* input, char* output, System& system, int msgLen);

    /* Constructor por copia borrado */
    PetitionSolver(const PetitionSolver& petitionSolver) = delete;

    /* Asignacion por copia borrado */
    PetitionSolver operator=(const PetitionSolver& petitionSolver) = delete;

    /* Resuelve la peticion del cliente */
    int solve();

    /* Destructor */
    ~PetitionSolver();

 private:
    /* Devuelve un int que depende del tipo de metodo
     * del petitorio*/
    int _getPetitionType(const char* input);
};

#endif  // SERVER_SRC_SERVER_PETITIONSOLVER_H_
