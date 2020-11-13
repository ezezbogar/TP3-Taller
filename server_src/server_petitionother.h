#ifndef SERVER_SRC_SERVER_PETITIONOTHER_H_
#define SERVER_SRC_SERVER_PETITIONOTHER_H_

#include "server_petition.h"
#include <string>

class PetitionOther : public Petition {
 public:
    /* Constructor */
    PetitionOther(char* input, char* output);

    int solve() override;

    /* Destructor */
    ~PetitionOther();
};

#endif  // SERVER_SRC_SERVER_PETITIONOTHER_H_
