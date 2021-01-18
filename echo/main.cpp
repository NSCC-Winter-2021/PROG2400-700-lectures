#include <iostream>
#include <cstring>

using namespace std;

int main() {

    char buffer[256];

    bool done = false;

    while(!done) {

        cout << "Enter some text: ";
        cin.getline(buffer, 256);

        if( !cin ) {
            cin.clear();
            cin.ignore(1024, '\n');
        }

        if (!strcmp(buffer, "end")) {
            done = true;
        } else {
            cout << "You typed: " << buffer << endl;
        }
    }

    return 0;
}
