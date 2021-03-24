#include <iostream>
#include <iomanip>

using namespace std;

void dumparray(int *array, int len) {
    for (int i = 0; i < len; ++i) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

int split(int *array, int first, int last) {

    // pick a pivot point
    int pivot = array[first];

    int left = first;
    int right = last;

    while (left < right) {

        // move all less than the pivot to the left
        while (pivot < array[right]) {
            right--;
        }

        // move all greater than the pivot to the right
        while (pivot >= array[left]) {
            left++;
        }

        // if right didn't cross left, swap the elements
        if (left < right) {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }

    // now move the pivot to its correct spot
    array[first] = array[right];
    array[right] = pivot;

    return right;
}

void quicksort(int *array, int first, int last) {

    if (first < last) {
        // split into sublists
        int pos = split(array, first, last);

        // quicksort the left sublist
        quicksort(array, first, pos - 1);

        // quicksort the right sublist
        quicksort(array, pos + 1, last);
    }
}

int main() {

    int nums[] = {3,6,8,10,5,9,4,1,2,7};
    int len = sizeof(nums)/sizeof(int);

    cout << "Before Sorting..." << endl;
    dumparray(nums, len);

    quicksort(nums, 0, 9);

    cout << "After Sorting..." << endl;
    dumparray(nums, len);

    return 0;
}