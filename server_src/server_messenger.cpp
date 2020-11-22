#include "server_messenger.h"
#include <string>
#include <utility>

#define MEMORY_SIZE 1024

Messenger::Messenger(const std::string& rootFile, Socket&& peer,
                     System& system) : system(system){
    this->peer = std::move(peer);
    this->clientFinished = false;
    this->input = new char[MEMORY_SIZE];
    this->output = new char[MEMORY_SIZE];
}

void Messenger::solve() {
    int replyLen;
    int msgLen = this->peer.receive(this->input, MEMORY_SIZE);
    _printFirstLine();

    PetitionSolver petitionSolver(this->input,
                                  this->output, this->system, msgLen);
    replyLen = petitionSolver.solve();
    this->peer.send(this->output, replyLen);
    this->peer.ShutDownWR();
    this->clientFinished = true;
}

void Messenger::_printFirstLine() {
    std::string screenBuf;
    int i = 0;
    while (this->input[i] != '\n') {
        screenBuf.append(&this->input[i], 1);
        i++;
    }
    system.printOnScreen(screenBuf);
}

bool Messenger::finished() {
    return this->clientFinished;
}

Messenger::~Messenger() {
    delete[] this->input;
    delete[] this->output;
}
