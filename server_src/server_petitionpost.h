#ifndef PETITIONPOST_H_
#define PETITIONPOST_H_

#include "server_petition.h"
#include <string>

class PetitionPost : public Petition {
private:
    int msgLen;
public:
    /* Constructor */
    PetitionPost(char* input, char* output, int msgLen);

    int solve() override;

    /* Destructor */
    ~PetitionPost();

private:
    int _emptyPost();
    int _postResource();
    void _writeFile(int bodyStart, std::string fileName, int headerLen);
    std::string _getPostName();
};

#endif  // PETITIONPOST_H_
