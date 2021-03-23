#include <iostream>
#include <iomanip>

using namespace std;

void dumparray(int *array, int len) {
    for (int i = 0; i < len; ++i) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

void insertionsort(int *array, int len) {

    for (int i = 1; i < len; ++i) {

        int temp = array[i];

        int j;
        for (j = i; j >= 0 && temp < array[j-1]; j--) {
            array[j] = array[j-1];
        }

        array[j] = temp;
    }

}

int main() {

    int nums[] = {3,6,8,10,5,9,4,1,2,7};
    int len = sizeof(nums)/sizeof(int);

    cout << "Before Sorting..." << endl;
    dumparray(nums, len);

    insertionsort(nums, len);

    cout << "After Sorting..." << endl;
    dumparray(nums, len);

    return 0;
}