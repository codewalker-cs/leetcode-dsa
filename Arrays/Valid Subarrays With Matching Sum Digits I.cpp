/*
    LeetCode Style Solution
    Problem:
    
    Count subarrays whose:
    1. First digit of subarray sum = x
    2. Last digit of subarray sum = x

    Approach:
    - Build a prefix sum array to obtain any subarray sum in O(1).
    - Enumerate all possible subarrays [l, r].
    - Compute sum using prefix sums.
    - Check whether the last digit of the sum equals x.
    - Extract the first digit by repeatedly dividing by 10.
    - If both first and last digits are x, increment the answer.
    
    Time Complexity: O(n² * log(S))
        where S is the maximum subarray sum.

    Space Complexity: O(n)
*/

class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size();

        vector<long long> prefixsum(n+1,0);
        for(int i=0;i<n;i++)
        {
            prefixsum[i+1]=prefixsum[i]+nums[i];
        }

        long long ans=0;
        
        for(int l=0;l<n;l++)
        {
            for(int r=l;r<n;r++)
            {
                long long sum=prefixsum[r+1]-prefixsum[l];

                if((sum%10)!=x) continue;

                long long temp=sum;
                while(temp>=10)
                {
                    temp/=10;
                }

                if(temp==x) ans++;  
            }
        }
        return ans;
    }
};
