/*
Intuition:
-----------
We use a prefix sum array where:
    pre[i] = sum of elements from index 0 to i

For each index i:
- If pre[i] == k → subarray from 0 to i has sum = k
- If there exists a previous prefix sum = pre[i] - k,
  then the subarray between those indices sums to k

We store frequencies of prefix sums in a hashmap.

Steps:
-------
1. Build prefix sum array
2. Traverse prefix array:
   - Check if pre[i] == k
   - Check if (pre[i] - k) exists in hashmap
   - Update hashmap with current prefix sum

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),count=0;
        vector<int> pre(n,0);
        pre[0]=nums[0];

        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }

        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
        {
            if(pre[i]==k) count++;
            int f=pre[i]-k;

            if(freq.find(f)!=freq.end())
            {
                count+=freq[f];
            }
            
            if(freq.find(pre[i])==freq.end())
            {
                freq[pre[i]]=0;
            }
            freq[pre[i]]++;
        }
        return count;
    }
};
