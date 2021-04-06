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

    friend istream& operator>>(istream& input, Person& p);

};

istream& operator>>(istream& input, Person& p) {

    getline(input, p.LastName, ',');
    getline(input, p.FirstName, ',');
    input >> p.Age;

    return input;
}

int main() {

    // load a string with comma separated values
    string data = "Smith,John,45";

    // create object based on string
    stringstream ss;
    ss << data;

    Person p;
    ss >> p;

    cout << p.FirstName << " " << p.LastName << ", Age: " << p.Age << endl;

    return 0;
}