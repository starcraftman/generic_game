#include <iostream>
#include "util.hpp"

using std::cout;
using std::endl;

int main(int argc, char *argv[]){
    cout << "Args being printed: " << endl;
    for (int i = 0; i != argc; ++i) {
        cout << "Argv[" << i << "] = " << argv[i] << endl;
    }

    cout << "Generic game here." << endl;
    cout << "Rolled: " << util::d6() << endl;
}
