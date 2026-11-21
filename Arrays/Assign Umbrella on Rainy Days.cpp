/*
Intuition:
We maintain the number of rainy days assigned to Alice and Bob.
The assignment depends on whether the next day is also rainy
and the current assignment counts.

Approach:
1. Initialize counters a and b for Alice and Bob.
2. Iterate through the rain array.
3. If the current day is rainy:
   - If the next day is also rainy and Alice has been assigned
     no more rainy days than Bob, assign it to Alice.
   - Otherwise, assign it to Bob.
4. If it is not rainy, assign "None".
5. Return the resulting assignment.

Time Complexity: O(n)
Space Complexity: O(n) for the answer vector.
*/

class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int b=0,a=0,n=rain.size();
        vector<string> ans;
        for(int i=0;i<n;i++)
        {
            if(rain[i]==1)
            {
                if(i<n-1 && rain[i+1]==1 && a<=b)
                {
                    ans.push_back("Alice");
                    a++;
                }
                else
                {
                    ans.push_back("Bob");
                    b++;
                }
            }
            else
            {
                ans.push_back("None");
            }
        }
        return ans;
    }
};
