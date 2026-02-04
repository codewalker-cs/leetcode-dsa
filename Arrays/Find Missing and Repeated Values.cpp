/*
Problem: Find Missing and Repeated Values in n×n grid

We are given numbers from 1..n².
One number is repeated, one number is missing.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Approach 1 — Frequency Array (User Style)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Idea:
- Count how many times each number appears.
- The number with frequency 2 = repeated
- The number with frequency 0 = missing

Time:  O(n²)
Space: O(n²)

This is optimal in time (we must read the grid anyway).
Simple and safe approach.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Approach 2 — Mathematics (O(1) space)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Let:
x = repeated
y = missing
N = n²

Expected:
E  = sum(1..N)
E2 = sum of squares(1..N)

Actual:
S  = sum of grid
S2 = sum of squares of grid

We get equations:

x - y = S - E
x² - y² = S2 - E2 = (x-y)(x+y)

So:
x + y = (S2 - E2) / (S - E)

Now solve system:
x = ( (x-y) + (x+y) ) / 2
y = x - (x-y)

Time:  O(n²)
Space: O(1)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ─────────────────────────────
    // Approach 1: Frequency (User style)
    // ─────────────────────────────
    vector<int> freqMethod(vector<vector<int>>& grid) {
        int size=grid.size()*grid[0].size();
        vector<int> freq(size,0);
        for(int i=0;i<grid.size();i++)
        {
            for(int &c : grid[i])
            {
                freq[c-1]++;
            }
        }
        vector<int> ans(2);
        for(int j=0;j<size;j++)
        {
            if(freq[j]==0)
            {
                ans[1]=j+1;
            }
            else if(freq[j]==2)
            {
                ans[0]=j+1;
            }
        }
        return ans;
    }

    // ─────────────────────────────
    // Approach 2: Mathematics O(1) space
    // ─────────────────────────────
    vector<int> mathMethod(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long N = n*n;

        long long S = 0, S2 = 0;

        for (auto &row : grid) {
            for (long long x : row) {
                S += x;
                S2 += x*x;
            }
        }

        long long E  = N*(N+1)/2;
        long long E2 = N*(N+1)*(2*N+1)/6;

        long long diff = S - E;          // x - y
        long long sum  = (S2 - E2)/diff; // x + y

        long long x = (diff + sum)/2; // repeated
        long long y = x - diff;       // missing

        return {(int)x, (int)y};
    }

    // choose which one to return
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // return freqMethod(grid);
        return mathMethod(grid);
    }
};
