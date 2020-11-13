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

    /* Resuelve la peticion del cliente para el caso en que el
     * metodo sea GET */
    int solve() override;

    /* Destructor */
    ~PetitionGet();

 private:
    /* Resuelve la peticion para el caso en el que "resource"
     * no esta especificado */
    int loadRootResource();

    /* Resuelve la peticion para el caso en el que "resource"
     * si esta especificado */
    int loadRequest();

    /* Devuelve el nombre del "resource" de la peticion */
    std::string _getResourceName();
};

#endif  // SERVER_SRC_SERVER_PETITIONGET_H_
