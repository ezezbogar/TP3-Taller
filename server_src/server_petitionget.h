#ifndef PETITIONGET_H_
#define PETITIONGET_H_

#include "server_petition.h"
#include <string>

class PetitionGet : public Petition {
private:
    std::string resource;
public:
    /* Constructor */
    PetitionGet(char* input, char* output, std::string resource);

    int solve() override;

    /* Destructor */
    ~PetitionGet();

private:
    int loadRootResource();
    int loadRequest();
    std::string _getResourceName();
};

#endif  // PETITIONGET_H_
