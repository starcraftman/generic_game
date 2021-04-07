#include <iostream>
#include <csignal>
#include <cstdlib>

#include "game.hpp"
#include "util.hpp"
#include "actor.hpp"

using std::cout;
using std::endl;

void handler(int s) {
    cout << "Caught signal with value of: " << s << ". Closing this process. " << endl;
    exit(2);
}

int main(int argc, char *argv[]){
    struct sigaction sig_handler;
    sig_handler.sa_handler = handler;
    sigemptyset(&sig_handler.sa_mask);
    sig_handler.sa_flags = 0;
    sigaction(SIGINT, &sig_handler, NULL);

    Game game;

    return 0;
}
