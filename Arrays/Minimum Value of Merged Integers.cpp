/*
Intuition:
- We need to merge every pair of adjacent elements by concatenating
  their decimal representations.
- Convert both numbers into strings, concatenate them, and convert
  the result back into an integer.
- Keep track of the minimum merged integer.

Approach:
1. Initialize ans = INT_MAX.
2. Traverse the array in steps of 2.
3. Convert nums[i] and nums[i + 1] into strings.
4. Concatenate both strings.
5. Convert the concatenated string into an integer using stoi().
6. Update the minimum answer.
7. Return ans.

Time Complexity: O(n * d), where d is the maximum number of digits.
Space Complexity: O(d)
*/

class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i+=2)
        {
            string s1=to_string(nums[i]),s2=to_string(nums[i+1]);
            string s3=s1+s2;
            ans=min(ans,stoi(s3));
        }
        return ans;
    }
};
