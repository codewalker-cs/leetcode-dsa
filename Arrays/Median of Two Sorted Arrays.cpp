/*
    ------------------------------------------------------------
    🧠 Intuition:
    ------------------------------------------------------------

    We are given two sorted arrays and need to find the median 
    of the combined array.

    In this brute-force approach:

    1. Append nums2 into nums1.
    2. Sort the combined array.
    3. Find the median based on total size.

    Since both arrays are sorted, sorting again is not optimal,
    but this approach is simple and easy to understand.

    ------------------------------------------------------------
    ⏱ Time Complexity:
        - Insertion: O(m)
        - Sorting: O((n + m) log(n + m))
        - Total: O((n + m) log(n + m))

    📦 Space Complexity:
        - O(1) extra (modifies nums1 directly)

    ------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());

        int n=nums1.size();
        double median;
        if(n%2==0)
        {
            int mid=n/2;
            median=(nums1[mid-1]+nums1[mid])/2.0;
        }
        else
        {
            median=nums1[n/2];
        }
        return median;
    }
};
