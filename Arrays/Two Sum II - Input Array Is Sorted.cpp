/*
    Problem: Two Sum II - Input Array Is Sorted
    Platform: LeetCode

    ------------------------------------------------------------
    Approach 1: Hash Map
    ------------------------------------------------------------
    Intuition:
    - Traverse the array from right to left.
    - Store each number and its index in a hash map.
    - For every element, check if its complement
          (target - currentNumber)
      already exists in the map.
    - If found, return their 1-based indices.

    Time Complexity: O(n)
    Space Complexity: O(n)

    ------------------------------------------------------------
    Approach 2: Two Pointers (Optimal)
    ------------------------------------------------------------
    Intuition:
    - Since the array is already sorted, use two pointers.
    - Place one pointer at the beginning and the other at the end.
    - Calculate their sum:
        * If sum == target → answer found.
        * If sum < target → move the left pointer right to increase the sum.
        * If sum > target → move the right pointer left to decrease the sum.
    - Continue until the pair is found.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // unordered_map<int,int> need;
        // int n=numbers.size();
        // for(int i=n-1;i>=0;i--)
        // {
        //     if(need.find(target-numbers[i])!=need.end())
        //     {
        //         return {i+1,need[target-numbers[i]]+1};
        //     }
        //     need[numbers[i]]=i;
        // }
        // return {};

        int n=numbers.size();
        int l=0,r=n-1;
        while(l<r)
        {
            int s=numbers[l]+numbers[r];
            
            if(s==target)
            {
                return {l+1,r+1};
            }
            else if(s>target)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        return {};
    }
};
