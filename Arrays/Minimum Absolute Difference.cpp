/*
LeetCode: Minimum Absolute Difference

Intuition:
After sorting the array, the minimum absolute difference must occur
between two adjacent elements. Any non-adjacent pair will have a
difference greater than or equal to the adjacent difference.

Algorithm:
1. Sort the array.
2. Initialize minDiff as INT_MAX.
3. Traverse the array and compute the difference between adjacent elements.
4. If a smaller difference is found:
   - Clear the result vector.
   - Update minDiff.
   - Store the current pair.
5. If the difference equals minDiff:
   - Store the current pair.
6. Return the result vector.

Time Complexity:
O(n log n)
Sorting takes O(n log n) and the traversal takes O(n).

Space Complexity:
O(1) extra space (excluding output).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> sol;
        sort(arr.begin(),arr.end());
        int n=arr.size()-1,diff=INT_MAX,diff2;
        for(int i=0;i<n;i++)
        {
            diff2=arr[i+1]-arr[i];

            if(diff>diff2)
            {
                sol.clear();
                diff=diff2;
                sol.push_back({arr[i],arr[i+1]});
            }
            else if(diff==diff2)
            {
                sol.push_back({arr[i],arr[i+1]});
            }
        }
        return sol;
    }
};
