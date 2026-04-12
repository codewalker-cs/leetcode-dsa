// Intuition:
// Since the array is sorted, duplicates will be adjacent.
// We use two pointers:
// - i: scans through the array
// - j: keeps track of position to place next unique element
//
// Whenever nums[i] != nums[j-1], we found a new unique element.
// Place it at nums[j] and increment j.
//
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int j = 1;

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != nums[j - 1])
            {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};
