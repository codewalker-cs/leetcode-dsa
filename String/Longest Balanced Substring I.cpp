/*
Intuition:
----------
We want the longest substring where all distinct characters
appear the same number of times.

Brute-force approach:
- Try every possible substring
- Maintain frequency array of 26 characters
- For each substring, check if all non-zero frequencies are equal

If yes → it's balanced.

Key idea:
A substring is balanced if every character that appears
has identical frequency.

We separate the logic into:
1. checkbalance() → verifies if freq array is balanced
2. nested loops → generate all substrings

Time Complexity:  O(26 * n^2) ≈ O(n^2)
Space Complexity: O(1) (fixed 26-size array)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkbalance(vector<int>& freq)
    {
        int n=freq.size(),bal=0;
        for(int i=0;i<n;i++)
        {
            if(freq[i]!=0 && bal==0)
            {
                bal=freq[i];
            }
            else if(freq[i]!=0 && bal!=0)
            {
                if(bal!=freq[i])
                {
                    return false;
                }
            }
        }
        return true;
    }

    int longestBalanced(string s) {
        int maxcount=0;
        for(int i=0;i<s.size();i++)
        {
            vector<int> freq(26,0);
            int count=0;
            for(int j=i;j<s.size();j++)
            {
                freq[s[j]-'a']++;
                if(checkbalance(freq))
                {
                    count=j-i+1;
                    maxcount=max(count,maxcount);
                }
            }
        }
        return maxcount;
    }
};
