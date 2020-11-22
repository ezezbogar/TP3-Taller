#ifndef SERVER_SRC_SERVER_MESSENGER_H_
#define SERVER_SRC_SERVER_MESSENGER_H_

#include "server_petitionsolver.h"
#include "server_thread.h"
#include "../common_src/common_socket.h"
#include "server_system.h"
#include <string>

class Messenger : public Thread {
 private:
    Socket peer;
    bool clientFinished;
    System& system;

    char* input;
    char* output;

 public:
    /* Constructor */
    Messenger(const std::string& rootFile, Socket&& peer, System& system);

    /* Constructor por copia borrado*/
    Messenger(const Messenger& messenger) = delete;

    /* Asignacion por copia borrado*/
    Messenger operator=(const Messenger& messenger) = delete;

    /* Recibe el petitorio HTTP del cliente y envia la respuesta */
    void solve() override;

    /* Devuelve true si ya se termino de procesar y enviar la respuesta
     * al petitorio */
    bool finished() override;

    /* Destructor */
    ~Messenger();

 private:
    /* Imprime por pantalla la primer linea del petitorio */
    void _printFirstLine();
};

#endif  // SERVER_SRC_SERVER_MESSENGER_H_
