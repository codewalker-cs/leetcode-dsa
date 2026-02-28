/*
====================================================================
PROBLEM: Median of Two Sorted Arrays
====================================================================

We are given two sorted arrays nums1 and nums2.
We must return the median of the combined sorted order.

--------------------------------------------------------------------
APPROACH 1 — Brute Force (Sorting Approach)
--------------------------------------------------------------------

Intuition:
1. Append nums2 into nums1.
2. Sort the combined array.
3. Compute the median from the sorted array.

Since sorting guarantees correct order, the median is simply:
- If total size is even:
      average of elements at indices n/2 - 1 and n/2
- If total size is odd:
      element at index n/2

Time Complexity:
    O((n + m) log(n + m))

Space Complexity:
    O(1) extra (modifies nums1 directly)

--------------------------------------------------------------------
APPROACH 2 — Optimal Binary Search Partition
--------------------------------------------------------------------

Intuition:
Instead of merging both arrays, we divide them into two halves:

        LEFT HALF | RIGHT HALF

Such that:
1. Left half contains (n1 + n2 + 1) / 2 elements.
2. Every element in the left half is <= every element in the right half.

We binary search on the smaller array to decide how many
elements to take from it into the left partition.

Let:
    cut1 = number of elements taken from nums1
    cut2 = totalLeft - cut1

We compute boundary elements:
    l1 = element just before cut1 in nums1
    r1 = element at cut1 in nums1
    l2 = element just before cut2 in nums2
    r2 = element at cut2 in nums2

If:
    l1 <= r2 AND l2 <= r1
then partition is correct.

Median:
- If total length is odd:
      max(l1, l2)
- If total length is even:
      (max(l1, l2) + min(r1, r2)) / 2

Time Complexity:
    O(log(min(n1, n2)))

Space Complexity:
    O(1)

====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        // sort(nums1.begin(),nums1.end());

        // int n=nums1.size();
        // double median;
        // if(n%2==0)
        // {
        //     int mid=n/2;
        //     median=(nums1[mid-1]+nums1[mid])/2.0;
        // }
        // else
        // {
        //     median=nums1[n/2];
        // }
        // return median;

        if(nums1.size()>nums2.size())
        {
            return findMedianSortedArrays(nums2,nums1);
        }

        int n1=nums1.size(),n2=nums2.size();
        int n=(n1+n2+1)/2,l=0,r=n1;

        while(l<=r)
        {
            int mid1=(l+r)>>1,mid2=n-mid1;

            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

            if(l1<=r2 && l2<=r1)
            {
                if((n1+n2)%2==0)
                {
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else
                {
                    return max(l1,l2);
                }
            }
            else if(l1>r2)
            {
                r=mid1-1;
            }
            else if(l2>r1)
            {
                l=mid1+1;
            }
        }
    return 0.0;
    }
};
