#include "server_messenger.h"
#include <iostream>
#include <string>
#include <utility>

#define MEMORY_SIZE 1024

Messenger::Messenger(const std::string& rootFile, Socket&& peer) {
    this->peer = std::move(peer);
    this->rootFile = rootFile;
    this->clientFinished = false;
    this->input = new char[MEMORY_SIZE];
    this->output = new char[MEMORY_SIZE];
}

void Messenger::solve() {
    int replyLen;
    int msgLen = this->peer.receive(this->input, MEMORY_SIZE);
    _printFirstLine();

    PetitionSolver petitionSolver(this->input,
                                  this->output, this->rootFile, msgLen);
    replyLen = petitionSolver.solve();
    this->peer.send(this->output, replyLen);
    this->peer.ShutDownWR();

    this->clientFinished = true;
}

void Messenger::_printFirstLine() {
    int i = 0;
    while (this->input[i] != '\n') {
        std::cout << this->input[i];
        i++;
    }
    std::cout << std::endl;
}

bool Messenger::finished() {
    return this->clientFinished;
}

Messenger::~Messenger() {
    delete[] this->input;
    delete[] this->output;
}
