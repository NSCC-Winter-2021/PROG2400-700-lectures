#include <iostream>
#include <iomanip>

using namespace std;

void dumparray(int *array, int len) {
    for (int i = 0; i < len; ++i) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

void selectionsort(int *array, int len) {

    for (int i = 0; i < len - 1; ++i) {

        int highest = i;
        for (int j = i; j < len; ++j) {
            if (array[j] > array[highest]) {
                highest = j;
            }
        }

        if (array[highest] > array[i]) {
            int temp = array[highest];
            array[highest] = array[i];
            array[i] = temp;
        }
    }

}

int main() {

    int nums[] = {3,6,8,10,5,9,4,1,2,7};
    int len = sizeof(nums)/sizeof(int);

    cout << "Before Sorting..." << endl;
    dumparray(nums, len);

    selectionsort(nums, len);

    cout << "After Sorting..." << endl;
    dumparray(nums, len);

    return 0;
}