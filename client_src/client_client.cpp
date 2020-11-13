#include "client_client.h"

#define BUFFER_SIZE 64

Client::Client(char *host, char *port) {
    this->host = host;
    this->port = port;
    this->connected = false;
}

void Client::sendPetition() {
    this->connected = this->ClientSocket.connect(this->host, this->port);

    if (this->connected == true) {
        char buffer[BUFFER_SIZE];
        while (!feof(stdin)) {
            size_t result = fread(buffer, sizeof(char), BUFFER_SIZE, stdin);
            this->ClientSocket.send(buffer, static_cast<int>(result));
        }
        this->ClientSocket.ShutDownWR();
    }
}

void Client::receiveReply() {
    if (this->connected == true) {
        int bytes_received;
        char buffer[BUFFER_SIZE];
        do {
            bytes_received = this->ClientSocket.receive(buffer, BUFFER_SIZE);
            fwrite(buffer, sizeof(char), bytes_received, stdout);
        } while (bytes_received != 0);
        this->ClientSocket.ShutDownRD();
    }
}

Client::~Client() {}
