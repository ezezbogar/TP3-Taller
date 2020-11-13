#ifndef SERVER_SRC_SERVER_PETITIONGET_H_
#define SERVER_SRC_SERVER_PETITIONGET_H_

#include "server_petition.h"
#include <string>

class PetitionGet : public Petition {
 private:
    std::string resource;
 public:
    /* Constructor */
    PetitionGet(char* input, char* output, const std::string& resource);

    int solve() override;

    /* Destructor */
    ~PetitionGet();

 private:
    int loadRootResource();
    int loadRequest();
    std::string _getResourceName();
};

#endif  // SERVER_SRC_SERVER_PETITIONGET_H_
