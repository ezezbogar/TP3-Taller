#ifndef SERVER_SRC_SERVER_SERVER_H_
#define SERVER_SRC_SERVER_SERVER_H_

#include "../common_src/common_socket.h"
#include "server_thread.h"
#include "server_messenger.h"
#include <vector>
#include <atomic>

class Server {
 private:
    Socket bindingSkt;
    std::vector<Thread*> clients;
    std::thread endCharThread;
    std::string rootFile;

    std::atomic<bool> endAccepting;

 public:
    Server(std::string rootFile);

    void run(const char* port);

    ~Server();

 private:
    /* Lee la entrada estandar hasta que se introduce
     * el caracter finalizador*/
    void _getEndChar();

    void _acceptClients();

    void _createClient(Socket& peer);

    void _deleteFinishedClients();

    void _deleteAllClients();

    void _end();
};

#endif  // SERVER_SRC_SERVER_SERVER_H_
