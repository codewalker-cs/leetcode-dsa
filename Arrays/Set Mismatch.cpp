/*
Intuition:
----------
We are given an array of size n that should contain numbers from 1..n exactly once.
But due to an error:
- one number appears twice (duplicate)
- one number is missing

We use a frequency map to count how many times each number appears.

Steps:
1. Traverse the array and store frequency of each number.
2. Scan numbers from 1..n:
   - if frequency == 2 → duplicate
   - if frequency == 0 → missing
3. Return {duplicate, missing}

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size(),doub,miss;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
        {
            if(freq.find(nums[i])==freq.end())
            {
                freq[nums[i]]=1;
            }
            else
            {
                freq[nums[i]]++;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(freq[i]>1)
            {
                doub=i;
            }

            if(freq[i]==0)
            {
                miss=i;
            }
        }
        return {doub,miss};
    }
};
