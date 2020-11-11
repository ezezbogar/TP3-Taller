#ifndef SERVER_H_
#define SERVER_H_

#include "../common_src/common_socket.h"
#include "server_thread.h"
#include <vector>
#include <atomic>

class Server {
private:
    Socket bindingSkt;
    std::vector<Thread*> clients;
    std::thread endCharThread;
    std::string rootFile;

    std::atomic<bool> endAccepting;
    int totalClients;

public:
    Server(std::string rootFile);

    void run(const char* port);

    ~Server();

private:

    void _getEndChar();

    void _acceptClients();

    void _createClient();

    void _end();
};

#endif  // SERVER_H_
