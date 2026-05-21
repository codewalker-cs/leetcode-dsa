/*
Intuition:
-----------
A common prefix means the starting digits of two numbers are the same.

Example:
12345 and 12399
Common prefixes -> 1, 12, 123

The longest common prefix length here is 3.

Approach:
---------
1. Convert every number from arr1 into a string.
2. Generate all prefixes of each number and store them in a hash set.
   Example:
   1234 -> "1", "12", "123", "1234"

3. Traverse every number in arr2.
4. Generate its prefixes one by one and check whether that prefix
   exists in the hash set.
5. Keep updating the maximum prefix length found.

Why this works:
---------------
If a prefix from arr2 exists in the set,
then there exists at least one number in arr1
having the same starting digits.

Time Complexity:
----------------
O(D)

D = total number of digits across both arrays.

Space Complexity:
-----------------
O(D)
*/

class Solution {
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
        unordered_set<string> prefixes;
        for (int num : arr1)
        {
            string s=to_string(num);
            string pref="";
            for (char ch : s)
            {
                pref+=ch;
                prefixes.insert(pref);
            }
        }

        int ans=0;
        for (int num : arr2)
        {
            string s=to_string(num);
            string pref="";
            for (int i = 0; i < s.size(); i++)
            {
                pref += s[i];
                if (prefixes.count(pref))
                {
                    ans=max(ans,i+1);
                }
            }
        }
        return ans;
    }
};
