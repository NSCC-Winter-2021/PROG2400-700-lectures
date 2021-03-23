#include <iostream>
#include <iomanip>

using namespace std;

void dumparray(int *array, int len) {
    for (int i = 0; i < len; ++i) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

void bubblesort(int *array, int len) {

    for (int i = 0; i < len - 2; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (array[j+1] > array[j]) {
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }

}

int main() {

    int nums[] = {3,6,8,10,5,9,4,1,2,7};
    int len = sizeof(nums)/sizeof(int);

    cout << "Before Sorting..." << endl;
    dumparray(nums, len);

    bubblesort(nums, len);

    cout << "After Sorting..." << endl;
    dumparray(nums, len);

    return 0;
}