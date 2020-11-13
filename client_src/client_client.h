#ifndef CLIENT_SRC_CLIENT_CLIENT_H_
#define CLIENT_SRC_CLIENT_CLIENT_H_

#include "../common_src/common_socket.h"

class Client {
 private:
    char* host;
    char* port;
    Socket ClientSocket;
    bool connected;

 public:
    /* Constructor */
    Client(char* host, char* port);

    /* Se conecta a algun peer del servidor y en caso de exito envia
     * el contenido de stdin */
    void sendPetition();

    /* Recibe mediante la conexion establecida (si es que la hay) la respuesta
     * del servidor ante el mensage enviado y la imprime por pantalla */
    void receiveReply();

    /* Destructor */
    ~Client();
};

#endif  // CLIENT_SRC_CLIENT_CLIENT_H_
