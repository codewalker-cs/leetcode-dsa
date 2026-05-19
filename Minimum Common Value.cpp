/*
Intuition:
Since both arrays are sorted in non-decreasing order,
we can use the two-pointer technique to efficiently
find the smallest common element.

Approach:
1. Initialize two pointers:
   - p1 for nums1
   - p2 for nums2

2. Compare elements at both pointers:
   - If equal, we found the smallest common element.
   - If nums1[p1] < nums2[p2], move p1 forward.
   - Otherwise, move p2 forward.

3. If traversal finishes without a match,
   return -1.

Time Complexity:
O(n + m)
where:
- n = size of nums1
- m = size of nums2

Space Complexity:
O(1)
*/

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int p1=0,p2=0;

        while(p1<n1 && p2<n2)
        {
            if(nums1[p1]==nums2[p2]) return nums1[p1];
            if(nums1[p1]<nums2[p2])
            {
                p1++;
            }
            else
            {
                p2++;
            }
        }
        return -1;
    }
};
