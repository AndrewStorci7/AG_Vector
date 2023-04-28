#include <iostream>
using namespace std;
#include "classes/Razionale.h"
#include "classes/Vector.h"
#include "h/gblfun.h"


int main() {
    Razionale r;
    string s = "-45";
    cout << stoi( s );
    cout << s << endl;
    r = Razionale( s );
    cout << r;
    // start();

    return 0;
}
