#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    for (int i = 0; i < argc; ++i) {
        cout << (i+1) << ") " << argv[i] << endl;
    }

    cout << "Enter some info: ";

    int a, b;
    string name;
    cin >> name;
    cout << "Name: " << name << endl;
    cin.ignore(80, ' ');
    cin.ignore(80, ' ');
    //cout << cin.rdbuf();
    cin >> a;
    cout << "a = " << a << endl;
    cin >> b;
    cout << "b = " << b << endl;

    return 0;

}
