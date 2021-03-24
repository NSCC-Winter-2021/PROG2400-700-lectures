#include <iostream>
#include <iomanip>

using namespace std;

void dumparray(int *array, int len) {
    for (int i = 0; i < len; ++i) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

void split(int *inarray, int len, int *outarray1, int *outsize1, int *outarray2, int *outsize2) {

    int subFiles = 0;
    int in = 0;
    *outsize1 = 0;
    *outsize2 = 0;

    // get first record
    int curr;
    int next = inarray[in++];

    // while there are records available, keep looping
    while (in <= len) {

        // extract one ordered sublist
        // and put into correct temp location
        do {
            curr = next;

            // get the next record
            if (in < len) {
                next = inarray[in];
            }
            in++;

            // put record in the correct location
            if (subFiles % 2 == 0) {
                outarray1[(*outsize1)++] = curr;
            } else {
                outarray2[(*outsize2)++] = curr;
            }

        } while ((in <= len) && (curr < next));

        subFiles++;
    }
}

int merge(int *outarray, int *outsize, int *inarray1, int insize1, int *inarray2, int insize2) {

    int subFiles = 0;

    int in1 = 0;
    int in2 = 0;
    *outsize = 0;

    int curr1;
    int curr2;

    int prev1;
    int prev2;

    // start at the beginning of each subarray
    curr1 = inarray1[in1++];
    curr2 = inarray2[in2++];

    // keep going while both arrays have elements
    while( in1 <= insize1 && in2 <= insize2 )
    {
        bool endOfSub1 = false;
        bool endOfSub2 = false;

        // move through both arrays until an ordered
        // sublist is completed
        while( !endOfSub1 && !endOfSub2 )
        {
            // use the element from array 1, if it is lower
            if( curr1 <= curr2 )
            {
                // store the element in the merged array
                outarray[(*outsize)++] = curr1;

                // move to next element
                prev1 = curr1;
                if( in1 < insize1 )
                {
                    curr1 = inarray1[in1];
                }
                in1++;

                // did we hit the end of a sublist?
                if( (in1 > insize1) || (prev1 > curr1) )
                {
                    endOfSub1 = true;
                }
            }

            // use the element from array 2, if it is lower
            if( curr2 <= curr1 )
            {
                // store the element in the merged array
                outarray[(*outsize)++] = curr2;

                // move to next element
                prev2 = curr2;
                if( in2 < insize2 )
                {
                    curr2 = inarray2[in2];
                }
                in2++;

                // did we hit the end of a sublist?
                if( (in2 > insize2) || (prev2 > curr2) )
                {
                    endOfSub2 = true;
                }
            }
        }

        // we finished with array 2, so dump the remaining ordered
        // elements from array 1 into the merged array
        while( !endOfSub1 )
        {
            // add to merged array
            outarray[(*outsize)++] = curr1;

            // move to next element
            prev1 = curr1;
            if( in1 < insize1 )
            {
                curr1 = inarray1[in1];
            }
            in1++;

            // are we at the end of the sublist yet?
            if( (in1 > insize1) || (prev1 > curr1) )
            {
                endOfSub1 = true;
            }
        }

        // we finished with array 1, so dump the remaining ordered
        // elements from array 2 into the merged array
        while( !endOfSub2 )
        {
            // add to merged array
            outarray[(*outsize)++] = curr2;

            // move to next element
            prev2 = curr2;
            if( in2 < insize2 )
            {
                curr2 = inarray2[in2];
            }
            in2++;

            // are we at the end of the ordered sublist yet?
            if( (in2 > insize2) || (prev2 > curr2) )
            {
                endOfSub2 = true;
            }
        }

        // we can now assume we have merged one complete sublist
        // so, let's move on to the next one, while we still have
        // elements in our arrays
        subFiles++;
    }

    // dump remaining elements from array 1
    while( in1 <= insize1 )
    {
        outarray[(*outsize)++] = curr1;

        // move to next element
        prev1 = curr1;
        if( in1 < insize1 )
        {
            curr1 = inarray1[in1];
        }
        in1++;

        // keep track of sublists within remaining elements
        if( (in1 > insize1) || (prev1 > curr1) )
        {
            subFiles++;
        }
    }

    // dump the remaining elements from array 2
    while( in2 <= insize2 )
    {
        outarray[(*outsize)++] = curr2;

        // move to next element
        prev2 = curr2;
        if( in2 < insize2 )
        {
            curr2 = inarray2[in2];
        }
        in2++;

        // we still need to keep track of sublists within the remaining elements
        if( (in2 > insize2) || (prev2 > curr2) )
        {
            subFiles++;
        }
    }

    return subFiles;
}

void mergesort(int* array, int len) {

    int subFiles = 0;
    int *temp1 = new int[len];
    int *temp2 = new int[len];
    int tempsize1;
    int tempsize2;

    // keep splitting and merging until you have 1 subfile
    do {
        split(array, len, temp1, &tempsize1, temp2, &tempsize2);

        subFiles = merge(array, &len, temp1, tempsize1, temp2, tempsize2);

    } while (subFiles != 1);

    delete [] temp1;
    delete [] temp2;
}

int main() {

    int nums[] = {3,6,8,10,5,9,4,1,2,7};
    int len = sizeof(nums)/sizeof(int);

    cout << "Before Sorting..." << endl;
    dumparray(nums, len);

    mergesort(nums, len);

    cout << "After Sorting..." << endl;
    dumparray(nums, len);

    return 0;
}
