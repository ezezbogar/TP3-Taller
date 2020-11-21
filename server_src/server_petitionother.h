#ifndef SERVER_SRC_SERVER_PETITIONOTHER_H_
#define SERVER_SRC_SERVER_PETITIONOTHER_H_

#include "server_petition.h"

class PetitionOther : public Petition {
 public:
    /* Constructor */
    PetitionOther(char* input, char* output);

    /* Resuelve la peticion del cliente para el caso en que
     * el metodo sea otro diferente a GET y POST */
    int solve() override;

    /* Destructor */
    ~PetitionOther();
};

#endif  // SERVER_SRC_SERVER_PETITIONOTHER_H_
