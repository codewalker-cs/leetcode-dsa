/*
 * Problem: Minimum Absolute Difference between indices of 1 and 2
 *
 * Intuition:
 * ------------------------------------------------------------
 * We need to find the minimum distance between occurrences of
 * values 1 and 2 in the array.
 *
 * Key idea:
 * - Traverse the array once.
 * - Track the last seen index of either 1 or 2.
 * - Whenever we encounter a different value (1 after 2 or 2 after 1),
 *   compute the absolute difference between indices.
 * - Update the minimum distance accordingly.
 *
 * Why this works:
 * - The closest pair will always be formed by consecutive relevant
 *   elements (1 or 2), so a single pass is enough.
 *
 * Variables:
 * - i1 → stores last index of 1 or 2
 * - i2 → current index when different element is found
 * - c  → minimum absolute difference
 *
 * Edge case:
 * - If no valid pair (1 and 2 both present), return -1
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int c=INT_MAX,i1=-1,i2=-1;
        for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==1 || nums[i]==2)
                {
                    if(i1==-1)
                    {
                        i1=i;
                    }
                    else if(nums[i1]!=nums[i])
                    {
                        i2=i;
                        c=min(c,abs(i2-i1));
                        i1=i;
                    }
                    else
                    {
                        i1=i;
                    }
                }
            }
        return (c==INT_MAX)?-1:c;
    }
};
