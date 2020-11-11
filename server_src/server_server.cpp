#include "server_server.h"
#include <iostream>

#define ENDING_CHAR 'q'

Server::Server(std::string rootFile) {
    this->endAccepting = false;
    this->totalClients = 0;
    this->rootFile = rootFile;
}

void Server::run(const char *port) {
    this->bindingSkt.bind(port);
    this->bindingSkt.listen();

    this->endCharThread = std::thread(&Server::_getEndChar, this);

    //clientes

    _end();
}

void Server::_acceptClients() {
    Socket peer;
    while (this->endAccepting == false) {
        try{
            peer = this->bindingSkt.accept();
        } catch (const std::exception &e){}
        if (peer.isValid()) {
            _createClient();
        }
    }
}

void Server::_createClient() {

}

void Server::_getEndChar() {
    char c;
    do {
        std::cin >> c;
    } while (c != ENDING_CHAR);
    this->endAccepting = true;
    this->bindingSkt.close();
}

void Server::_end() {
    this->endCharThread.join();
}

Server::~Server() {}