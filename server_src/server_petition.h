#ifndef SERVER_SRC_SERVER_PETITION_H_
#define SERVER_SRC_SERVER_PETITION_H_

class Petition {
 protected:
    char* input;
    char* output;

 public:
    /* Constructor */
    Petition(char* input, char* output);

    /* Este metodo es implementado por las clases hijas */
    virtual int solve() = 0;

    /* Destructor */
    virtual ~Petition();
};

#endif  // SERVER_SRC_SERVER_PETITION_H_
