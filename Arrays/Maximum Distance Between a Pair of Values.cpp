/*
Intuition:
We need to find the maximum value of (j - i) such that:

1. i <= j
2. nums1[i] <= nums2[j]

Both arrays are sorted in non-increasing order (descending).

Because of this sorted property:
- If nums1[i] <= nums2[j], then current pair is valid.
  We try to increase j to get a larger distance.
- Otherwise nums1[i] > nums2[j], so current i cannot work with this j.
  Move i forward to reduce nums1[i].

We use two pointers:
i -> index for nums1
j -> index for nums2

Also ensure j >= i because valid pairs require i <= j.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,ans=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(i>j) j=i;
            
            if(nums1[i]<=nums2[j])
            {
                ans=max(ans,j-i);
                j++;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};
