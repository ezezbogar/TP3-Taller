#ifndef COMMON_SRC_COMMON_SOCKET_H_
#define COMMON_SRC_COMMON_SOCKET_H_

#include "../common_src/common_socket_exception.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

class Socket {
 private:
    int fd;

 public:
    /* Constructor */
    Socket();

    /* Constructor por movimiento */
    Socket(Socket&& skt) noexcept;

    /* Asignacion por movimiento */
    Socket& operator=(Socket&& skt) noexcept;

    /* Constructor por copia borrado */
    Socket(const Socket& skt) = delete;

    /* Asignacion por copia borrado */
    Socket operator=(const Socket& skt) = delete;

    /* Hace el bind del socket para el puerto especificado */
    bool bind(const char *port);

    /* Conecta el socket a algun peer del servidor. Devuelve -1 ante algun
     * error, 0 en caso de exito */
    bool connect(const char *host, const char *port);

    /* Deja el socket a la espera de alguna conexion entrante hasta que algun
     * cliente se conecte. Devuelve un objeto Socket que es el peer que permite
     * la comunicacion con el cliente */
    Socket accept() const;

    /* Recibe size bytes (o menos) y los guarda en el array msg.
     * Devuelve la cantidad de bytes recibidos */
    int receive(char *msg, const int size);

    /* Envia por el socket size bytes del array msg. Devuelve la
     * cantidad de bytes enviados */
    int send(char *msg, const int size);

    /* Define la cantidad de clientes que pueden estar a la espera de
     * conectarse a algun peer */
    void listen();

    /* Cierra el canal de escritura */
    void ShutDownWR();

    /* Cierra el canal de lectura */
    void ShutDownRD();

    /* Finaliza la comunicacion y cierra el socket */
    void close();

    /* Devuelve true si el file descriptor del socket es distinto de
     * -1. False en caso contrario*/
    bool isValid();

    /* Destructor */
    ~Socket();

 private:
    explicit Socket(int Fd);

    /* Cliente */
    struct addrinfo* _getAddrInfo(const char *host, const char *port);

    /* Server */
    struct addrinfo* _getAddrInfo(const char *port);
};

#endif  // COMMON_SRC_COMMON_SOCKET_H_
