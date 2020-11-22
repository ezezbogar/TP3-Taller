#include "server_server.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <utility>

#define ENDING_CHAR 'q'

Server::Server(const std::string& rootFile) : system(rootFile) {
    this->endAccepting = false;
    this->rootFile = rootFile;
}

void Server::operator()(const char *port) {
    this->_run(port);
}

void Server::_run(const char *port) {
    this->bindingSkt.bind(port);
    this->bindingSkt.listen();
    this->endCharThread = std::thread(&Server::_getEndChar, this);

    _acceptClients();
    _end();
}

void Server::_acceptClients() {
    Socket peer;
    while (this->endAccepting == false) {
        try {
            peer = this->bindingSkt.accept();
        } catch (const std::exception &e) {}
        if (peer.isValid()) {
            _createClient(peer);
        }
        _deleteFinishedClients();
    }
}

void Server::_createClient(Socket& peer) {
    this->clients.push_back(new Messenger(this->rootFile, std::move(peer), this->system));
    this->clients.back()->start();
}

/* Devuelve true si el Thread termino su ejecucion, false en
 * caso contrario */
bool _clientHasFinished(Thread* client) {
    if (client->finished() == true) {
        client->join();
        delete client;
        return true;
    }
    return false;
}

void Server::_deleteFinishedClients() {
    clients.erase(std::remove_if
    (clients.begin(), clients.end()
     , _clientHasFinished), clients.end());
}

void Server::_deleteAllClients() {
    for (long unsigned int i = 0; i < this->clients.size(); i++) {
        this->clients[i]->join();
        delete this->clients[i];
    }
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
    _deleteAllClients();
}

Server::~Server() {}
