#include <iostream>
#include "client_client.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Error: argumentos invalidos." << std::endl;
        return 1;
    }
    try{
        Client client(argv[1], argv[2]);
        client.sendPetition();
        client.receiveReply();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}

/*g++ client_src/client_main.cpp common_src/common_socket.cpp common_src/common_socket_exception.cpp client_src/client_client.cpp */