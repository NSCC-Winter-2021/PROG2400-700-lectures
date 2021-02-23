#include <iostream>

using namespace std;

int count = 0;

void recursiveFunction() {
    cout << "Hello World!" << endl;

    count++;
    if (count < 100) {
        recursiveFunction(); //???? recursion!
    }
}

int main() {

    // STATUS_STACK_OVERFLOW
    recursiveFunction();

    return 0;
}