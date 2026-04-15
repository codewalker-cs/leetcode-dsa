// Remove Element (LeetCode)
//
// Intuition:
// Instead of deleting elements (which is costly),
// we overwrite the elements equal to 'val' by shifting valid elements forward.
// We maintain a pointer 'k' which keeps track of the position where
// the next valid element should be placed.
//
// Steps:
// 1. Traverse the array
// 2. If current element != val → place it at index k
// 3. Increment k
// 4. Return k as the new length

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
