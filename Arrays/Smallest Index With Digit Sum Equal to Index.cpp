/*
    Intuition:
    ------------
    We need to find the smallest index `i` such that:

        sum of digits of nums[i] == i

    So for every element, we calculate its digit sum and compare it
    with its index.

    For example:

        nums = [1, 2, 3, 4]

        index 0 -> digit sum(1) = 1  -> not equal
        index 1 -> digit sum(2) = 2  -> not equal
        index 2 -> digit sum(3) = 3  -> not equal
        index 3 -> digit sum(4) = 4  -> not equal

    Therefore, return -1.

    Approach:
    ----------
    1. Calculate the digit sum of each number.
    2. Compare the digit sum with the current index.
    3. Return the first matching index.
    4. If no index satisfies the condition, return -1.

    Time Complexity:
    O(n * d)

    where d is the number of digits in the largest number.

    Space Complexity:
    O(1)
*/

class Solution {
public:
    int digitsum(int n)
    {
        int ans=0,temp=n;
        while(temp>0)
        {
            ans+=temp%10;
            temp/=10;
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            int s=digitsum(nums[i]);
            if(s==i) return i;
        }
        return -1;
    }
};
