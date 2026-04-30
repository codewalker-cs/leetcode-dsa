// Intuition:
// We use a greedy approach.
// maxReach stores the farthest index we can reach so far.
// If at any point our current index exceeds maxReach, we cannot proceed.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach=0;

        for(int i=0;i<nums.size();i++)
        {
            if(i>maxreach) return false;
            maxreach=max(maxreach,i+nums[i]);
            if(maxreach>=nums.size()-1) return true;
        }
        return true;
    }
};
