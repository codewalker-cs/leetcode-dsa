/*
Intuition 1 (Brute Force):
--------------------------
For every element nums[i], we compare it with all other elements.
We count how many numbers are strictly smaller than nums[i].

This works because the problem literally asks us to count
smaller elements for each position.

Time Complexity: O(n^2)
Space Complexity: O(1) extra


Intuition 2 (Optimized - Sorting + Ranking):
---------------------------------------------
Instead of comparing every pair, we sort a copy of the array.

In a sorted array:
the first index where a value appears = number of elements smaller than it.

Example:
nums   = [8,1,2,2,3]
sorted = [1,2,2,3,8]

value 2 first appears at index 1
→ so 1 element is smaller than 2

We store this "rank" in a map and build the answer using
the original order.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // int n=nums.size();
        // vector<int> ans;
        // for(int i=0;i<n;i++)
        // {
        //     int count=0;
        //     for(int j=0;j<n;j++)
        //     {
        //         if(j==i)
        //         {
        //             continue;
        //         }
        //         if(nums[j]<nums[i])
        //         {
        //             count++;
        //         }
        //     }
        //     ans.push_back(count);
        // }
        // return ans;
        int n=nums.size();
        vector<int> ans,num=nums;
        sort(num.begin(),num.end());
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
        {
            if(freq.find(num[i])==freq.end())
            {
                freq[num[i]]=i;
            }
        }
        for(int i=0;i<n;i++)
        {
            ans.push_back(freq[nums[i]]);
        }
        return ans;
    }
};
