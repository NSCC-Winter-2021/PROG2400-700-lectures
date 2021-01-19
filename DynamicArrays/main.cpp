#include <iostream>

using namespace std;

int main() {

    int nums[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < sizeof(nums)/sizeof(nums[0]); ++i) {
        cout << nums[i] << endl;
    }

    // add 6 to the array?
    int nums2[6];
    memcpy(nums2, nums, sizeof(nums));

    nums2[5] = 6;

    for (int i = 0; i < sizeof(nums2)/sizeof(nums2[0]); ++i) {
        cout << nums2[i] << endl;
    }

    return 0;
}
