#include <iostream>
#include <sstream>

using namespace std;

class Person {
public:
    string FirstName;
    string LastName;
    int Age;

    Person() : FirstName(""), LastName(""), Age(0) {

    }

    Person& operator<<(string data) {

        stringstream ss;
        ss << data;

        getline(ss, FirstName, ',');
        getline(ss, LastName, ',');
        ss >> Age;

        return *this;
    }

};

int main() {

    // load a string with comma separated values
    string data = "Smith,John,45";

    // create object based on string
    Person p;
    p << data;

    cout << p.FirstName << " " << p.LastName << ", Age: " << p.Age << endl;

    return 0;
}