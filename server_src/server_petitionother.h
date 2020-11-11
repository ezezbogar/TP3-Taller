#ifndef PETITIONOTHER_H_
#define PETITIONOTHER_H_

#include "server_petition.h"

class PetitionOther : public Petition {
public:
    /* Constructor */
    PetitionOther(char* input, char* output);

    int solve() override;

    /* Destructor */
    ~PetitionOther();
};

#endif  // PETITIONOTHER_H_
