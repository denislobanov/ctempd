#include <iostream>
#include <csignal>

#include "daemon.hpp"

using std::cout;
using std::endl;

daemon* d;

void signal_handler(int signum) {
    cout<<"stopping daemon"<<endl;
    d->kill();

    delete d;
    exit(signum);
}

int main(void) {
    cout<<"starting daemon"<<endl;
    d = new daemon();

    signal(SIGINT, signal_handler);

    d->run();
}

