/*
    Problem: Top K Frequent Elements

    Intuition:
    ----------
    We need to return the k most frequent elements from the array.

    Steps:
    1. Count frequency of each number using a hashmap.
    2. Store (frequency, number) pairs in a vector.
       - We store frequency first so sorting becomes easier.
    3. Sort the vector in descending order of frequency.
    4. Pick the first k elements from the sorted vector.

    Why this works:
    ----------------
    Sorting ensures the most frequent elements come first.
    So we just take the first k elements.

    Complexity:
    ------------
    Time: O(N log N) due to sorting
    Space: O(N) for hashmap + vector

    Note:
    -----
    This is a straightforward approach.
    Can be optimized to O(N log K) using a min-heap.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<int> ans;

        for(int i:nums)
        {
            if(freq.find(i)==freq.end())
            {
                freq[i]=0;
            }
            freq[i]++;
        }

        vector<pair<int,int>> temp;
        for(auto &it : freq)
        {
            temp.push_back({it.second, it.first});
        }

        sort(temp.begin(),temp.end(),greater<pair<int,int>>());
        for(int i=0;i<k;i++)
        {
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};
