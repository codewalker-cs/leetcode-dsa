/*
============================================================
LeetCode 1461 - Check If a String Contains All Binary Codes of Size K
============================================================

PROBLEM:
Given a binary string s and an integer k, return true if all possible
binary codes of length k exist as substrings of s.

------------------------------------------------------------
APPROACH 1: Sliding Window + unordered_set<string>

INTUITION:
- Total possible binary codes of size k = 2^k
- Use sliding window of size k
- Extract each substring of length k
- Store it in unordered_set
- If set size becomes 2^k → return true

WHY THIS WORKS:
- Each substring represents a binary code
- unordered_set ensures uniqueness

TIME COMPLEXITY:
O(n * k)
- n windows
- substring creation costs O(k)

SPACE COMPLEXITY:
O(2^k * k)
- storing up to 2^k strings of length k

------------------------------------------------------------
APPROACH 2: Optimal Bitmask Sliding Window

INTUITION:
- Instead of storing substrings, convert each k-length window
  into an integer (binary representation).
- Maintain rolling binary value using bit shifting.
- Use vector<bool> of size 2^k to track seen patterns.
- Each update is O(1).

KEY IDEA:
If window = "101" → treat it as integer 5.
Update window using:
    hash = ((hash << 1) & mask) | new_bit

TIME COMPLEXITY:
O(n)

SPACE COMPLEXITY:
O(2^k)

This is the optimal approach.

============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int si=1<<k,l=0,r=0;
        unordered_set<string> val;
        while(r<s.size())
        {
            if((r-l+1)==k)
            {
                val.insert(s.substr(l,r-l+1));
                l++;
                r++;
                if(val.size()==si)
                {
                    return true;
                }
            }
            else
            {
                r++;
            }
        }
        return false;

        // if (s.size() < k) return false
    
        // unordered_set<string> st;
        // for(int i = 0; i <= s.size() - k; i++) {
        //     st.insert(s.substr(i, k));
        // }
        // return st.size() == (1 << k);
    }
};

// class Solution {
// public:
//     bool hasAllCodes(string s, int k) {
//         int n = s.size();
//         if (k > n) return false;

//         int total = 1 << k;
//         vector<bool> seen(total, false);
        
//         int mask = total - 1;
//         int hash = 0;
//         int count = 0;

//         for (int i = 0; i < n; i++) {
//             hash = ((hash << 1) & mask) | (s[i] - '0');

//             if (i >= k - 1) {
//                 if (!seen[hash]) {
//                     seen[hash] = true;
//                     count++;
//                     if (count == total)
//                         return true;
//                 }
//             }
//         }

//         return false;
//     }
// };
