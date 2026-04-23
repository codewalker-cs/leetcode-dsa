// Intuition:
// freq → stores number of losses for each player
// ans1 → players with 0 losses
// ans2 → players with exactly 1 loss
//
// Instead of re-looping over matches and doing find() checks,
// we directly iterate over freq map to avoid duplicates and inefficiency.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> freq;

        for(int i = 0; i < matches.size(); i++)
        {
            int winner = matches[i][0];
            int loser = matches[i][1];

            if(freq.find(winner) == freq.end())
            {
                freq[winner] = 0;
            }

            if(freq.find(loser) == freq.end())
            {
                freq[loser] = 0;
            }
            freq[loser]++;
        }

        vector<int> ans1, ans2;

        for(auto it : freq)
        {
            if(it.second == 0)
            {
                ans1.push_back(it.first);
            }
            else if(it.second == 1)
            {
                ans2.push_back(it.first);
            }
        }
        sort(ans1.begin(), ans1.end());
        sort(ans2.begin(), ans2.end());

        return {ans1, ans2};
    }
};
