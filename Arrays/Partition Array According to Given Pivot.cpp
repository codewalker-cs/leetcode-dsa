/*
Intuition:
We need to rearrange the array such that:
1. All elements smaller than pivot come first.
2. All elements equal to pivot come next.
3. All elements greater than pivot come last.

Additionally, the relative order within each group must remain unchanged.

A simple way is to iterate through the array three times:
- First collect elements < pivot.
- Then collect elements == pivot.
- Finally collect elements > pivot.

Since elements are pushed in their original order, stability is preserved.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot) ans.push_back(nums[i]);
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]==pivot) ans.push_back(nums[i]);
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]>pivot) ans.push_back(nums[i]);
        }

        return ans;
    }
};
