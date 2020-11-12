#include "server_thread.h"

Thread::Thread() {}

void Thread::start() {
    thread = std::thread(&Thread::solve, this);
}

void Thread::join() {
    thread.join();
}

Thread::~Thread() {}
