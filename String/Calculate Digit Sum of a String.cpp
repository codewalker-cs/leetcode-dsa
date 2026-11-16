/*
Intuition:
We repeatedly divide the string into groups of k consecutive digits
and replace each group with the sum of its digits.

Approach:
1. Store the input string in ans.
2. While ans has more than k characters:
   - Create an empty temporary string.
   - Divide ans into groups of k characters.
   - Calculate the sum of digits in each group.
   - Append each sum to the temporary string.
3. Update ans with the temporary string.
4. Return ans when its length becomes at most k.

Time Complexity: O(n log_k(n)) approximately
Space Complexity: O(n)
*/

class Solution {
public:
    string digitSum(string s, int k) {
        string ans=s;
        while(ans.size()>k)
        {
            string temp="";
            for(int i=0;i<ans.size();i+=k)
            {
                int sum=0;
                for(int j=i;j<min(i+k,(int)ans.size());j++)
                {
                    sum+=ans[j]-'0';
                }
                temp+=to_string(sum);
            }
            ans=temp;
        }
        return ans;
    }
};
