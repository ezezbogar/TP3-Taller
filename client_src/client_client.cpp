#include "client_client.h"

#define BUFFER_SIZE 64

Client::Client(char *host, char *port) {
    this->host = host;
    this->port = port;
}

void Client::sendPetition() {
    char buffer[BUFFER_SIZE];

    this->ClientSocket.connect(this->host, this->port);
    while (!feof(stdin)) {
        size_t result = fread(buffer, sizeof(char), BUFFER_SIZE, stdin);
        this->ClientSocket.send(buffer, static_cast<int>(result));
    }
    //cerrar canal de escritura
}

void Client::receiveReply() {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    do {
        bytes_received = this->ClientSocket.receive(buffer, BUFFER_SIZE);
        fwrite(buffer, sizeof(char), bytes_received, stdout);
    } while (bytes_received != 0);
    //cerrar algun canal del socket??
}

Client::~Client() {}