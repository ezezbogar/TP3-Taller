#include "server_server.h"
#include <iostream>
#include <cstring>

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Error: argumentos invalidos." << std::endl;
        return 1;
    }
    try {
        // Ejecutar
        Server server(std::string(argv[2], strlen(argv[2])));
        server.run(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}
