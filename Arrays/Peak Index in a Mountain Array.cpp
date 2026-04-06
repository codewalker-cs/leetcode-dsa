/*
Peak Index in a Mountain Array (LeetCode 852)
--------------------------------------------

Approach: Binary Search (3-condition check)

------------------------------------------------------------
Intuition:
------------------------------------------------------------

A mountain array strictly increases, reaches a peak,
and then strictly decreases.

We use binary search to find the peak efficiently:

For a given mid:

1. If arr[mid] > arr[mid-1] AND arr[mid] > arr[mid+1]
   mid is the peak → return it

2. If arr[mid] is part of increasing slope:
   arr[mid] > arr[mid-1] AND arr[mid] < arr[mid+1]
   move right (l = mid + 1)

3. Else:
   we are in decreasing slope → move left (r = mid - 1)

------------------------------------------------------------
Important Boundary Fix:
------------------------------------------------------------

Since we access arr[mid-1] and arr[mid+1],
we restrict search space:

l = 1, r = n - 2

This ensures no out-of-bounds access.

------------------------------------------------------------
Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=1,r=arr.size()-2;
        while(l<=r)
        {
            int mid=l+((r-l)/2);
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            {
                return mid;
            }
            else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return -1;
    }
};

//-----------Smarter Pattern------------
// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int l = 0, r = arr.size() - 1;

//         while (l < r) {
//             int mid = l + (r - l) / 2;

//             if (arr[mid] < arr[mid + 1]) {
//                 l = mid + 1;
//             } else {
//                 r = mid;
//             }
//         }

//         return l;
//     }
// };
