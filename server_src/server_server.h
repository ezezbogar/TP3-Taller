#ifndef SERVER_SRC_SERVER_SERVER_H_
#define SERVER_SRC_SERVER_SERVER_H_

#include "../common_src/common_socket.h"
#include "server_thread.h"
#include "server_messenger.h"
#include <vector>
#include <atomic>
#include <string>

class Server {
 private:
    Socket bindingSkt;
    std::vector<Thread*> clients;
    std::thread endCharThread;
    std::string rootFile;
    std::atomic<bool> endAccepting;

 public:
    /* Constructor */
    explicit Server(const std::string& rootFile);

    /* Comienza la ejecucion del server */
    void operator()(const char* port);

    /* Destructor */
    ~Server();

 private:
    /* Ejecuta el server */
    void _run(const char* port);

    /* Lee la entrada estandar hasta que se introduce el
     * caracter finalizador */
    void _getEndChar();

    /* El socket listener (bindingSkt) se pone a la espera de
     * conexiones entrantes */
    void _acceptClients();

    /* Crea un nuevo Messenger que se va a encargar en un hilo aparte
     * de resolver el petitorio del cliente */
    void _createClient(Socket& peer);

    /* Recorre el vector de Threads y elimina los elementos cuya
     * ejecucion ya haya terminado */
    void _deleteFinishedClients();

    /* Espera que todos los hilos de ejecucion Messenger
     * finalicen y libera sus recursos */
    void _deleteAllClients();

    /* Finaliza la ejecucion del server */
    void _end();
};

#endif  // SERVER_SRC_SERVER_SERVER_H_
