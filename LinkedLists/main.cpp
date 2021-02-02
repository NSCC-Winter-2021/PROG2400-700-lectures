#include <iostream>

using namespace std;
int main() {

    LinkedList list;

    // test 1
    list.Add(1);
    list.Add(4);
    list.Add(3);
    list.Add(2);
    list.Add(5);

    cout << "Test 1" << endl;
    cout << "------" << endl;
    cout << list << endl;

    // test 2
    list.Delete(3);

    cout << "Test 2" << endl;
    cout << "------" << endl;
    cout << list << endl;

    // test 3
    list.Insert(6, 2);  // case 1: insert 6 before the value of 2
    list.Insert(0, 1);  // case 2: insert 0 at the beginning

    cout << "Test 3" << endl;
    cout << "------" << endl;
    cout << list << endl;

    return 0;
}
