/*
Merge two sorted arrays in-place.

nums1 has size m+n with extra space at the end.
nums2 has n elements.

We merge from the back to avoid overwriting nums1.

Pointers:
i = last valid element in nums1
j = last element in nums2
k = write position from the end

Time: O(m+n)
Space: O(1)
*/

//=============================================
//---------------- My code --------------------
//=============================================

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++)
        {
            nums1[m+i]=nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }
};

//=============================================
// Optimized code for the space complexity
//=============================================
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
    }
};
