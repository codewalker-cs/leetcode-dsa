/*
Intuition:
We need to find the minimum distance for any number that appears at least 3 times.
For each unique number, we store all its indices in the array.

Key Idea:
If a number appears at indices [i, j, k], the cost is:
    2 * (k - i)

Why?
Because we consider the distance between the first and third occurrence.

Steps:
1. Use a hashmap to store indices of each number.
2. For each number:
   - If it appears less than 3 times, skip it.
   - Otherwise, check every group of 3 consecutive indices.
3. Compute:
   2 * (v[j+2] - v[j])
4. Keep track of the minimum value.
5. If no valid triplet exists, return -1.

Time Complexity:
O(n), since we iterate through the array and then through grouped indices.

Space Complexity:
O(n), for storing indices in the hashmap.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> fr;

        for(int i=0;i<nums.size();i++)
        {
            fr[nums[i]].push_back(i);
        }

        int ans=INT_MAX;
        for(auto &i : fr)
        {
            vector<int> &v=i.second;
            if(v.size()<3) continue;

            for(int j=0;j<v.size()-2;j++)
            {
                ans=min(ans,2*(v[j+2]-v[j]));
            }
        }

        if(ans==INT_MAX)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};
