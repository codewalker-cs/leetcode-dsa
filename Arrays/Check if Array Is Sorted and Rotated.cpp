/*
    Intuition:
    A sorted and rotated array can have at most one "drop".

    Example:
    [3,4,5,1,2]

    Here:
    5 > 1  --> one drop

    If the number of drops becomes more than one,
    then the array cannot be sorted and rotated.
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int drops=0;
        for (int i=0;i<n;i++)
        {
            if (nums[i]>nums[(i+1)%n]) 
            {
                drops++;
            }
        }
        return drops<=1;
    }
};
