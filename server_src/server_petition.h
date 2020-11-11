#ifndef PETITION_H_
#define PETITION_H_

class Petition {
protected:
    char* input;
    char* output;

public:
    /* Constructor */
    Petition(char* input, char* output);

    virtual int solve() = 0;

    /* Destructor */
    virtual ~Petition();
};

#endif  // PETITION_H_
