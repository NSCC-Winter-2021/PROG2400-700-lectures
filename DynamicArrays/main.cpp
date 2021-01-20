#include <iostream>

using namespace std;

int main() {

    int *nums = new int[5] {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; ++i) {
        cout << nums[i] << endl;
    }

    // add 6 to the array?
    int *nums2 = new int[6];
    memcpy(nums2, nums, 5*sizeof(int));
    delete[] nums;

    nums2[5] = 6;

    for (int i = 0; i < 6; ++i) {
        cout << nums2[i] << endl;
    }

    // remove 1 and 2 from the array
    int *nums3 = new int[4];
    memcpy(nums3, &nums2[2], 4*sizeof(int));
    delete[] nums2;

    for (int i = 0; i < 4; ++i) {
        cout << nums3[i] << endl;
    }
    delete[] nums3;

    return 0;
}
