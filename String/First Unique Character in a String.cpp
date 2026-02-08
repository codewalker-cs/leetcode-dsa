/*
Intuition / Explanation

We want to find the index of the first character in a string that appears exactly once.
Two main approaches:

------------------------------------------------------------
Approach 1: Brute Force using count()
------------------------------------------------------------
Idea:
For each character s[i], we count how many times it appears in the whole string.
If its count is 1, that means it’s unique → return i.

How it works:
- For every index i:
    count(s.begin(), s.end(), s[i]) scans the entire string
- If count == 1 → we found the first unique character

Time complexity:
O(n^2) because for each character we scan the whole string again.

This is simple and intuitive, but inefficient for large strings.

------------------------------------------------------------
Approach 2: Frequency array (optimized)
------------------------------------------------------------
Idea:
Instead of recounting repeatedly, we store frequency of each character first.

Steps:
1. Create a frequency array of size 26 (for lowercase letters)
2. First pass:
   Count how many times each character appears
3. Second pass:
   The first index whose frequency == 1 is the answer

Time complexity:
O(n) — only two linear passes
Space complexity:
O(1) — fixed size array (26)

This is optimal and commonly used in interviews.

------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {

        // -------- Approach 1 (Brute Force) --------
        // for(int i=0;i<s.size();i++)
        // {
        //     if(count(s.begin(), s.end(),s[i])==1)
        //     {
        //         return i;
        //     }
        // }
        // return -1;

        // -------- Approach 2 (Optimized) --------
        vector<int> freq(26,0);
        for(char x:s)
        {
            freq[x-'a']++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(freq[s[i]-'a']==1)
            {
                return i;
            }
        }
        return -1;
    }
};
