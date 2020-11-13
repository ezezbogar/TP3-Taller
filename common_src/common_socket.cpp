#include "common_socket.h"
#include <cstring>
#include <iostream>

#define MAX_LISTENERS 10

Socket::Socket() {
    this->fd = -1;
}

Socket::Socket(int fd) {
    this->fd = fd;
}

Socket::Socket(Socket &&skt) noexcept {
    this->fd = skt.fd;
    skt.fd = -1;
}

Socket& Socket::operator=(Socket&& skt)  noexcept {
    this->fd = skt.fd;
    skt.fd = -1;
    return *this;
}

void Socket::bind(const char *port) {
    struct addrinfo* rp = _getAddrInfo(port);

    for (; rp != NULL; rp = rp->ai_next) {
        this->fd = ::socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);

        if (this->fd == -1) {
            std::cerr << strerror(errno) << std::endl;
        } else {
            int val = 1;
            ::setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));

            if (::bind(this->fd, rp->ai_addr, rp->ai_addrlen) == 0) {
                break;
            } else {
                std::cerr << strerror(errno) << std::endl;
                ::close(this->fd);
            }
        }
    }
    ::freeaddrinfo(rp);
}

bool Socket::connect(const char *host, const char *port) {
    struct addrinfo* rp = _getAddrInfo(host, port);
    int connected = false;

    for (; rp != NULL; rp = rp->ai_next) {
        this->fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);

        if (this->fd == -1) {
            std::cout << strerror(errno) << std::endl;
        } else if (::connect(this->fd , rp->ai_addr, rp->ai_addrlen) == -1) {
            std::cout << strerror(errno) << std::endl;
            ::close(this->fd);
        } else {
            connected = true;
            break;
        }
    }
    ::freeaddrinfo(rp);
    return connected;
}
Socket Socket::accept() const {
    int peerSktFd;
    peerSktFd = ::accept(this->fd, NULL, NULL);
    if (peerSktFd == -1) {
        throw SocketException(strerror(errno));
    }
    return Socket(peerSktFd);
}

int Socket::receive(char *msg, const int size) {
    int received = 0;

    while (received < size) {
        int s = ::recv(this->fd, msg + received, size - received, 0);
        if (s == -1) {
            throw SocketException(strerror(errno));
        } else if (s == 0) {
            break;
        } else {
            received += s;
        }
    }
    return received;
}

int Socket::send(char *msg, const int size) {
    int sent = 0;

    while (sent < size) {
        int s = ::send(this->fd, msg + sent, size - sent, MSG_NOSIGNAL);
        if (s == -1) {
            throw SocketException(strerror(errno));
        }
        sent += s;
    }
    return sent;
}

void Socket::listen() {
    int s = ::listen(this->fd, MAX_LISTENERS);
    if (s == -1) {
        throw SocketException(strerror(errno));
    }
}

void Socket::ShutDownWR() {
    ::shutdown(this->fd, SHUT_WR);
}

void Socket::ShutDownRD() {
    ::shutdown(this->fd, SHUT_RD);
}

/* Cliente */
struct addrinfo* Socket::_getAddrInfo(const char* host, const char* port) {
    struct addrinfo hints, *result;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;    		/* IPv4 (or AF_INET6 for IPv6)     */
    hints.ai_socktype = SOCK_STREAM; 	/* TCP  (or SOCK_DGRAM for UDP)    */
    hints.ai_protocol = 0;          	/* Any protocol */

    int s = getaddrinfo(host, port, &hints, &result);
    if (s != 0) {
        throw SocketException(strerror(errno));
    }
    return result;
}

/* Server */
struct addrinfo* Socket::_getAddrInfo(const char *port) {
    struct addrinfo hints, *result;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;    		/* IPv4 (or AF_INET6 for IPv6)     */
    hints.ai_socktype = SOCK_STREAM; 	/* TCP  (or SOCK_DGRAM for UDP)    */
    hints.ai_flags = AI_PASSIVE;    	/* AI_PASSIVE for server           */
    hints.ai_protocol = 0;          	/* Any protocol */

    int s = ::getaddrinfo(NULL, port, &hints, &result);
    if (s != 0) {
        throw SocketException(strerror(errno));
    }
    return result;
}

void Socket::close() {
    ::shutdown(this->fd, SHUT_RDWR);
    ::close(this->fd);
}

bool Socket::isValid() {
    return this->fd != -1;
}

Socket::~Socket() {
    if (this->fd != -1) {
        this->close();
    }
}
