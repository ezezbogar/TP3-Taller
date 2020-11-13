#ifndef SERVER_SRC_SERVER_MESSENGER_H_
#define SERVER_SRC_SERVER_MESSENGER_H_



#include "server_petitionsolver.h"
#include "server_thread.h"
#include "../common_src/common_socket.h"
#include <string>

class Messenger : public Thread {
 private:
    Socket peer;
    std::string rootFile;
    bool clientFinished;

    char* input;
    char* output;

 public:
    /* Constructor */
    Messenger(const std::string& rootFile, Socket&& peer);

    void solve() override;

    bool finished() override;

    /* Destructor */
    ~Messenger();

 private:
    /* Imprime la primer linea del petitorio */
    void _printFirstLine();
};

#endif  // SERVER_SRC_SERVER_MESSENGER_H_
