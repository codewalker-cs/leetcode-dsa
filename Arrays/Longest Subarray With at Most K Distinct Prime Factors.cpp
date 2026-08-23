/*
    Intuition:
    For every number, we only care about its distinct prime factors.

    We use a sliding window to maintain a subarray whose combined
    set of prime factors contains at most k distinct primes.

    `freq[p]` stores how many elements in the current window contain
    the prime factor p.

    Approach:
    1. Find the distinct prime factors of each number.
    2. Expand the window by moving `i` to the right.
    3. Add the prime factors of nums[i] to the frequency map.
    4. If the number of distinct prime factors exceeds k, shrink
       the window from the left.
    5. Update the maximum valid window length.

    Example:
    nums = [6, 10, 15], k = 2

    6  -> {2, 3}
    10 -> {2, 5}
    15 -> {3, 5}

    Window [6, 10] has {2, 3, 5}, so it is invalid for k = 2.
    We shrink the window until at most 2 distinct primes remain.

    Time Complexity:
    O(n * sqrt(max(nums)))

    Space Complexity:
    O(n)
*/

class Solution {
public:
    vector<int> fac(int n)
    {
        vector<int> ans;

        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                ans.push_back(i);
                while(n%i==0) n/=i;
            }
        }

        if(n>1) ans.push_back(n);
        return ans;
    }
    
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size(),l=0,ans=0,dis=0;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
        {
            vector<int> factor=fac(nums[i]);

            for(int p:factor)
            {
                if(freq[p]==0)
                {
                    dis++;
                }
                freq[p]++;
            }

            while(dis>k)
            {
                vector<int> lf=fac(nums[l]);
                for(int p:lf)
                {
                    freq[p]--;
                    if(freq[p]==0)
                    {
                        dis--;
                    }
                }
                l++;
            }
                ans=max(ans,i-l+1);
        }
        return ans;
    }
};
