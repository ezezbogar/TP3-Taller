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

    void bind(const char *port);

    bool connect(const char *host, const char *port);

    Socket accept() const;

    int receive(char *msg, const int size);

    int send(char *msg, const int size);

    void listen();

    void ShutDownWR();

    void ShutDownRD();

    void close();

    bool isValid();

    ~Socket();

 private:
    Socket(int Fd);

    /* Cliente */
    struct addrinfo* _getAddrInfo(const char *host, const char *port);

    /* Server */
    struct addrinfo* _getAddrInfo(const char *port);
};
#endif  // COMMON_SRC_COMMON_SOCKET_H_
