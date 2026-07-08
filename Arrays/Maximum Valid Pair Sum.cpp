/*
    ============================================================
    LeetCode: Maximum Valid Pair Sum
    ============================================================

    Intuition:
    ----------
    We need to find the maximum value of:
        nums[i] + nums[j]

    such that:
        j - i >= k

    A brute force solution would check every valid pair,
    resulting in O(N²) time.

    ------------------------------------------------------------
    Observation
    ------------------------------------------------------------

    While iterating from left to right, for every index i,
    we only need the maximum value that appears from
    index (i + k) to the end.

    Instead of searching this range every time,
    precompute it.

    ------------------------------------------------------------
    Suffix Maximum Array
    ------------------------------------------------------------

    Let
        mx[i] = maximum element from i to n-1.

    Build it from right to left.

    Example:
        nums = [5,1,8,3,7]
        mx = [8,8,8,7,7]

    Now for every i,
        best partner = mx[i+k]

    because mx[i+k] already stores the largest element
    in every valid position.

    ------------------------------------------------------------
    Dry Run
    ------------------------------------------------------------

    nums = [5,1,8,3,7]
    k = 2

    Suffix Maximum
        mx = [8,8,8,7,7]

    i = 0
        partner = mx[2] = 8
        answer = 5 + 8 = 13
    i = 1
        partner = mx[3] = 7
        answer = max(13,1+7)=13
    i = 2
        partner = mx[4] = 7
        answer = max(13,8+7)=15
    Final Answer = 15

    ------------------------------------------------------------
    Time Complexity
    ------------------------------------------------------------
    
    Building suffix maximum : O(N)
    Traversing array        : O(N)
    Total                   : O(N)

    ------------------------------------------------------------
    Space Complexity
    ------------------------------------------------------------
    O(N)
    ============================================================
*/

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=0;
        vector<int> mx(n,0);
        mx[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            mx[i]=max(nums[i],mx[i+1]);
        }
      

        for(int i=0;i<n-k;i++)
        {
            ans=max(ans,(long long)nums[i]+mx[i+k]);
        }
        return ans;
    }
};

/*
    ============================================================
    Optimal Approach
    ============================================================

    Intuition:
    ----------
    Instead of storing the suffix maximum array,
    maintain the maximum element seen so far while
    traversing from right to left.

    While processing index i,
        currentMax

    already represents the maximum value among
        nums[i+k ... n-1]
    because we update it before using it.

    ------------------------------------------------------------
    Dry Run
    ------------------------------------------------------------

    nums = [5,1,8,3,7]
    k = 2
    Start
        currentMax = 7
    i = 2
        answer = 8 + 7 = 15
        currentMax = max(7, nums[2]) = 8
    i = 1
        answer = max(15,1+8)=15
        currentMax = max(8, nums[1]) = 8
    i = 0
        answer = max(15,5+8)=15
    Final Answer = 15

    ------------------------------------------------------------
    Time Complexity
    ------------------------------------------------------------
    O(N)
    ------------------------------------------------------------
    Space Complexity
    ------------------------------------------------------------
    O(1)
    ============================================================
*/

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int currentMax = nums[n - 1];
      
        for (int i = n - k - 1; i >= 0; i--) {
            ans = max(ans, 1LL * nums[i] + currentMax);
            currentMax = max(currentMax, nums[i + k]);
        }
        return ans;
    }
};
