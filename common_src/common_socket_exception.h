#ifndef COMMON_SRC_COMMON_SOCKET_EXCEPTION_H_
#define COMMON_SRC_COMMON_SOCKET_EXCEPTION_H_

#include <exception>
#include <string>

class SocketException : public std::exception {
 private:
    std::string error;

 public:
    explicit SocketException(std::string&& error);
    const char* what() const noexcept;
    ~SocketException();
};

#endif  // COMMON_SRC_COMMON_SOCKET_EXCEPTION_H_
