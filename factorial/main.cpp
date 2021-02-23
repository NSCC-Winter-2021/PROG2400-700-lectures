#include <iostream>

using namespace std;

// calculate factorial
//
// 5! = 1 * 2 * 3 * 4 * 5

int calculateFactorial( int factorial ) {

    if (factorial == 1) return 1;

    return factorial  * calculateFactorial( factorial - 1);
}

int main() {

    int factorial;

    cout << "Enter a number: ";
    cin >> factorial;

    int answer = 1;
    for (int i = factorial; i >= 1 ; --i) {
        answer *= i;
    }
    cout << factorial << "! = " << answer << endl;

    cout << factorial << "! = " << calculateFactorial(factorial) << endl;

    return 0;
}