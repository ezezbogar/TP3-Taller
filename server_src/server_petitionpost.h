#ifndef PETITIONPOST_H_
#define PETITIONPOST_H_

#include "server_petition.h"

class PetitionPost : public Petition {
public:
    /* Constructor */
    PetitionPost(char* input, char* output);

    int solve() override;

    /* Destructor */
    ~PetitionPost();

private:
    int _emptyPost();
    int _postResource();
    int _getBodySize();
    int _getNumberBodySize(int position);
};

#endif  // PETITIONPOST_H_
