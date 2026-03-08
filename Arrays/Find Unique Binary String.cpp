/*
Intuition
---------
We are given n unique binary strings, each of length n. We must construct a binary
string of length n that does NOT appear in the given array.

A very elegant solution comes from Cantor's Diagonal Argument.

Idea:
Consider the i-th string and its i-th character (nums[i][i]).
If we flip this bit while constructing our answer string, we guarantee that
our new string differs from nums[i] at index i.

Construction:
For each i from 0 → n-1:
    if nums[i][i] == '0' → put '1'
    else → put '0'

Why this works:
The constructed string differs from:
- nums[0] at index 0
- nums[1] at index 1
- nums[2] at index 2
...
- nums[n-1] at index n-1

Therefore, it cannot be equal to any string in nums.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";

        for(int i = 0; i < n; i++)
        {
            if(nums[i][i] == '0')
                ans += '1';
            else
                ans += '0';
        }

        return ans;
    }
};
