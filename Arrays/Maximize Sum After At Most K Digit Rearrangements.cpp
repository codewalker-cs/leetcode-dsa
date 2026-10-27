/*
Intuition:
- Initially, the answer is the sum of all elements in nums.
- For each number, rearrange its digits in descending order to
  obtain the maximum possible number.
- The gain is the difference between the rearranged number and
  the original number.
- Sort all gains in descending order and add the largest k gains
  to maximize the sum.

Approach:
1. Calculate the sum of all elements in nums.
2. For each element:
   - Convert it to a string.
   - Sort its digits in descending order.
   - Convert the string back to an integer.
   - Store the gain (rearranged number - original number).
3. Sort the gains in descending order.
4. Add the largest k gains to the initial sum.
5. Return the final answer.

Time Complexity: O(n * d log d + n log n + k), where d is the maximum
number of digits in an element.
Space Complexity: O(n + d)
*/

class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=0;
        vector<int> g;

        for(int n:nums)
        {
            ans+=n;
            string s=to_string(n);
            sort(s.begin(),s.end(),greater<char>());

            int mx=stoi(s);
            g.push_back(mx-n);
        }
        sort(g.begin(),g.end(),greater<int>());
        for(int i=0;i<k;i++)
        {
            ans+=g[i];
        }
        return ans;
    }
};
