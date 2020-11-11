#ifndef COMMON_SOCKET_H_
#define COMMON_SOCKET_H_

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

    void bind(const char *port);

    void connect(const char *host, const char *port);

    Socket accept() const;

    int receive(char *msg, const int size);

    int send(char *msg, const int size);

    void listen();

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
#endif  // COMMON_SOCKET_H_
