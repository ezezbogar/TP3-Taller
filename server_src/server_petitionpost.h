#ifndef SERVER_SRC_SERVER_PETITIONPOST_H_
#define SERVER_SRC_SERVER_PETITIONPOST_H_

#include "server_petition.h"
#include <string>

class PetitionPost : public Petition {
 private:
    int msgLen;

 public:
    /* Constructor */
    PetitionPost(char* input, char* output, int msgLen);

    /* Resuelve la peticion del cliente para el caso en que
     * el metodo sea POST */
    int solve() override;

    /* Destructor */
    ~PetitionPost();

 private:
    /* Resuelve la peticion para el caso en el que "resource"
     * no esta especificado */
    int _emptyPost();

    /* Resuelve la peticion para el caso en el que "resource"
     * si esta especificado */
    int _postResource();

    /* Crea un archivo con el nombre del resource y el contenido es el
     * body del petitorio */
    void _writeFile(int bodyStart, std::string fileName, int headerLen);

    /* Devuelve el nombre del "resource" de la peticion */
    std::string _getPostName();
};

#endif  // SERVER_SRC_SERVER_PETITIONPOST_H_
