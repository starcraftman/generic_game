#include <iostream>
#include "util.hpp"
#include "actor.hpp"

using std::cout;
using std::endl;

int main(int argc, char *argv[]){
    cout << "Args being printed: " << endl;
    for (int i = 0; i != argc; ++i) {
        cout << "Argv[" << i << "] = " << argv[i] << endl;
    }

    cout << "Generic game here." << endl;
    cout << "Rolled a d20: " << util::roll_d20() << endl;

    Actor a1;
    Actor a2("Player", 50, 5);
    a2.attack(a1);
    cout << "Player attacked " << a1.called() << ", they now have: " << a1.life_remains() << endl;
}
