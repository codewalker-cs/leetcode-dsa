/*
Intuition:
We need to generate a string for every number from 1 to n
based on its divisibility by 3 and 5.

Approach:
1. Iterate from 1 to n.
2. If the number is divisible by both 3 and 5, append "FizzBuzz".
3. If divisible only by 3, append "Fizz".
4. If divisible only by 5, append "Buzz".
5. Otherwise, convert the number to a string and append it.

Time Complexity: O(n * log n)
Space Complexity: O(n * log n)
    - Stores n strings, with total output size O(n log n).
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;

        for(int i=1;i<=n;i++)
        {
            if(i%3==0 && i%5==0)
            {
                ans.push_back("FizzBuzz");
            }
            else if(i%3==0)
            {
                ans.push_back("Fizz");
            }
            else if(i%5==0)
            {
                ans.push_back("Buzz");
            }
            else
            {
                ans.push_back(to_string(i));
            }
        }
        return ans;
    }
};
