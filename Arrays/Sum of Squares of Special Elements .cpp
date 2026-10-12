/*
    Intuition:
    ------------
    We need to calculate the sum of squares of elements whose
    1-indexed positions divide the length of the array.

    An index i is valid if:

        n % i == 0

    For every valid index, we add the square of the corresponding
    element:

        nums[i - 1] * nums[i - 1]

    We use `i - 1` because array indices are 0-based, while the
    problem uses 1-based positions.

    Approach:
    ----------
    1. Find the size of the array n.
    2. Iterate through all positions from 1 to n.
    3. If n is divisible by i, add the square of nums[i - 1].
    4. Return the total sum.

    Time Complexity:
    O(n)

    Space Complexity:
    O(1)
*/

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            if(n%i==0) ans+=(nums[i-1]*nums[i-1]);
        }
        return ans;
    }
};
