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

    void sendPetition();

    void receiveReply();

    /* Destructor */
    ~Client();
};

#endif  // CLIENT_SRC_CLIENT_CLIENT_H_
