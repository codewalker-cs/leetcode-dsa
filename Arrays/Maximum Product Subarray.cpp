/*
    Intuition:
    ----------
    A negative number flips the sign of the product.
    Therefore, the maximum product subarray can either be:

    1. The product while traversing from left to right.
    2. The product while traversing from right to left.

    Why both directions?

    If there is an odd number of negative elements,
    removing either the prefix before the first negative
    or the suffix after the last negative gives the maximum product.

    Instead of explicitly finding these negatives,
    we simply calculate products from both directions.

    We also reset the running product whenever it becomes 0,
    because any subarray crossing a zero has product 0.

    --------------------------------------------------------------------

    Example:
    --------
    nums = [2, 3, -2, 4]

    Left to Right (Prefix Product)

        pre = 1

        2  -> pre = 2      ans = 2
        3  -> pre = 6      ans = 6
       -2  -> pre = -12    ans = 6
        4  -> pre = -48    ans = 6

    Right to Left (Suffix Product)

        suff = 1

        4   -> suff = 4     ans = 6
       -2   -> suff = -8    ans = 6
        3   -> suff = -24   ans = 6
        2   -> suff = -48   ans = 6

    Final Answer = 6

    --------------------------------------------------------------------

    Another Example:
    ----------------
    nums = [-2, 3, -4]

    Prefix:
        -2
        -6
         24

    Suffix:
        -4
       -12
        24

    Maximum Product = 24

    --------------------------------------------------------------------

    Time Complexity:
    ----------------
    O(N)

    Space Complexity:
    -----------------
    O(1)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0],pre=1,suff=1;

        for(int i=0;i<n;i++)
        {
            if(pre==0) pre=1;
            if(suff==0) suff=1;

            pre*=nums[i];
            suff*=nums[n-i-1];

            ans=max(ans,max(pre,suff));
        }

        return ans;
    }
};
