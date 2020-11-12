#include "server_messenger.h"
#include <iostream>//borrar

Messenger::Messenger(std::string rootFile, Socket&& peer) {
    this->peer = std::move(peer);
    this->rootFile = rootFile;
    this->clientFinished = false;
}

void Messenger::solve() {
    std::cout << "New Client!" << std::endl;//borrar
    int msgLen = this->peer.receive(this->input, MEMORY_SIZE);
    PetitionSolver(this->input, this->output, this->rootFile, msgLen); //debe devolver un entero para saber
    //la cantidad de bytes que tengoo que enviar

    this->clientFinished = true;
}

bool Messenger::finished() {
    return this->clientFinished;
}

Messenger::~Messenger() {}