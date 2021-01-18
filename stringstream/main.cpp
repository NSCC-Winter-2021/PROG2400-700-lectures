#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    char command[256];
    int start;
    int end;

    cout << "Enter a command and two numbers: ";
    cin >> command >> start >> end;

    cout << "Command: " << command << endl;
    cout << "Start: " << start << endl;
    cout << "End: " << end << endl;

    return 0;

}

