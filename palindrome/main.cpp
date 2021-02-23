#include <iostream>
#include <cstring>

using namespace std;

int main() {

    int len;
    char buffer[256];
    bool isPalindrome = true;

    cout << "Enter a word: ";
    cin.getline(buffer, 256);

    len = strlen(buffer);

    for (int i = 0; i < len / 2; ++i) {
        if (buffer[i] != buffer[len-i-1]) {
            isPalindrome = false;
        }
    }

    if (isPalindrome) {
        cout << buffer << " IS a palindrome!" << endl;
    } else {
        cout << buffer << " IS NOT a palindrome!" << endl;
    }

    return 0;
}