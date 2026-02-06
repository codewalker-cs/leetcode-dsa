/*
Intuition:
We scan the array and store frequencies in a hash map.
If any element appears more than once, a duplicate exists.

We return immediately when we detect freq > 1.

Time: O(n)
Space: O(n)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++)
        {
            if(freq.find(nums[i])==freq.end())
            {
                freq[nums[i]]=1;
            }
            else
            {
                freq[nums[i]]++;
            }
            if(freq[nums[i]]>1)
            {
                return true;
            }
        }
        return false;
    }
};
