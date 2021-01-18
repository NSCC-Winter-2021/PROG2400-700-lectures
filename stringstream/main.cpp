#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int main(int argc, char** argv) {

    char input[256];

    cout << "Enter a command and two numbers: ";
    cin.getline(input, 256);

    stringstream ss;
    ss << input;

    char command[256];
    ss >> command;

    if (strlen(command) > 1) {
        cout << "You entered some text" << endl;
    } else {
        cout << "You entered a " << command << " command" << endl;

        int start, end;
        ss >> start;
        ss >> end;

        cout << "The command is from line " << start << " to " << end << endl;
    }

    return 0;

}

