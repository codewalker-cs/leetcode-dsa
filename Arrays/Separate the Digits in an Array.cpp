// Intuition:
// We traverse every number in nums and extract its digits in the same order.
// Converting the number to string makes it easy to iterate digit by digit.
//
// Example:
// nums = [13,25]
// 13 -> '1','3'
// 25 -> '2','5'
//
// Final answer = [1,3,2,5]

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int num:nums)
        {
            string s = to_string(num);
            for (char ch : s)
            {
                ans.push_back(ch-'0');
            }
        }
        return ans;
    }
};
