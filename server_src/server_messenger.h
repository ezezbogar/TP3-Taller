#ifndef MESSENGER_H_
#define MESSENGER_H_

#define MEMORY_SIZE 1024

#include "server_petitionsolver.h"
#include "server_thread.h"
#include "../common_src/common_socket.h"

class Messenger : public Thread {
private:
    Socket peer;
    std::string rootFile;
    bool clientFinished;

    char input[MEMORY_SIZE];
    char output[MEMORY_SIZE];
public:
    /* Constructor */
    Messenger(std::string rootFile, Socket&& peer);

    void solve() override;

    bool finished() override;

    /* Destructor */
    ~Messenger();
};

#endif  // MESSENGER_H_
