#ifndef CLIENT_H_
#define CLIENT_H_

#include "../common_src/common_socket.h"

class Client {
private:
    char* host;
    char* port;
    Socket ClientSocket;

public:
    /* Constructor */
    Client(char* host, char* port);

    void sendPetition();

    void receiveReply();

    /* Destructor */
    ~Client();
};

#endif  // CLIENT_H_
