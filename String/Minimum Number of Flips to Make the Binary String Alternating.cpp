/*
PROBLEM
-------
We are given a binary string s. We can perform two operations:

Type-1 : Rotate the string (remove first character and append it to the end).
Type-2 : Flip any character ('0' -> '1' or '1' -> '0').

Goal:
Return the minimum number of Type-2 flips needed so that the string becomes
an alternating string (no two adjacent characters equal).

------------------------------------------------------------

INTUITION 1 — BRUTE FORCE ROTATIONS (O(n^2))
--------------------------------------------
Key observations:

1. An alternating binary string can only be of two types:
      Pattern A : 010101...
      Pattern B : 101010...

2. Since rotations are allowed, we must check every rotation of the string.

3. Instead of manually rotating the string, we use a common trick:
      s2 = s + s

   Example:
      s  = "abc"
      s2 = "abcabc"

   All rotations of s appear as substrings of length n in s2.

4. For each starting index j from 0 to n-1:
      window = s2[j ... j+n-1]

   We compute flips needed to convert this window into:
      Pattern A
      Pattern B

5. Take the minimum flips among all rotations.

Complexity:
      Time  : O(n^2)
      Space : O(n)

------------------------------------------------------------

INTUITION 2 — OPTIMIZED SLIDING WINDOW (O(n))
---------------------------------------------
The brute force approach recomputes mismatches for every rotation.

But observe two consecutive rotations:

      rotation j     : [j ..... j+n-1]
      rotation j + 1 : [j+1 ... j+n]

Almost the entire window overlaps.

Only two characters change:
      s2[j]      -> leaves the window
      s2[j+n]    -> enters the window

So instead of recomputing the whole window, we update the mismatch counts.

Steps:

1. Maintain mismatch counts with two patterns:
      pat1 -> mismatches with "101010..."
      pat2 -> mismatches with "010101..."

2. Expand the window one character at a time.

3. When window size exceeds n, remove the contribution of the leftmost character.

4. Whenever window size becomes n, update the answer.

Because each character enters and leaves the window exactly once:

      Time Complexity  : O(n)
      Space Complexity : O(n)

This is the optimal solution.

------------------------------------------------------------
*/

class Solution {
public:
    int minFlips(string s) {
        // string s2=s+s;
        // int n=s.size(),n2=s2.size();
        // int ans=INT_MAX;

        // for(int j=0;j<n;j++)
        // {
        //     int pat1=0,pat2=0;
        //     for(int i=j;i<n+j;i++)
        //     {
        //         if(s2[i]!=(i%2 ? '0' : '1')) pat1++;
        //         if(s2[i]!=(i%2 ? '1' : '0')) pat2++;
        //     }
        //     int mi=min(pat1,pat2);
        //     ans=min(mi,ans);
        // }
        // return ans;

        string s2=s+s;
        int n=s.size(),n2=2*n;
        int ans=INT_MAX;
        int pat1=0,pat2=0;

        for(int i=0;i<n2;i++)
        {
            if(s2[i]!=(i%2 ? '0' : '1')) pat1++;
            if(s2[i]!=(i%2 ? '1' : '0')) pat2++;

            if(i>=n)
            {
                if(s2[i-n]!=((i-n)%2 ? '0' : '1')) pat1--;
                if(s2[i-n]!=((i-n)%2 ? '1' : '0')) pat2--;
            }
            if(i>=n-1) ans=min(min(pat1,pat2),ans);
        }
        return ans;
    }
};
