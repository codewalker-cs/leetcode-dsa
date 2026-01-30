/*
================================================================================
Majority Element (LeetCode 169)
--------------------------------------------------------------------------------
Problem:
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n/2⌋ times.
You may assume that the majority element always exists in the array.

--------------------------------------------------------------------------------
My Thought Process / Intuition Evolution:

1) Initial Intuition (Sorting-based approach):
   -----------------------------------------
   - If the array is sorted, the majority element must appear at index n/2
     because it occupies more than half of the array.
   - This approach is simple and correct.

   Code idea:
       sort(nums.begin(), nums.end());
       return nums[n/2];

   Complexity:
       Time  : O(n log n)
       Space : O(1) extra

   Issue:
       Not optimal — sorting is unnecessary.

2) Improved Intuition (Boyer–Moore Voting Algorithm):
   --------------------------------------------------
   - Treat the problem like an election.
   - Keep a candidate and a counter.
   - Same elements increase votes, different elements cancel votes.
   - Since the majority element appears more than n/2 times, it cannot
     be fully canceled out.

   Key Insight:
   - Only one pass is required because the problem guarantees that
     a majority element exists.

--------------------------------------------------------------------------------
Final Approach:
- Initialize the first element as the candidate.
- Traverse the array:
    - If current element == candidate → increment counter
    - Else → decrement counter
    - If counter becomes 0 → choose new candidate
- Return the final candidate.

--------------------------------------------------------------------------------
Complexity:
- Time  : O(n)
- Space : O(1)

================================================================================
*/

#include <vector>
using namespace std;
 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int mid=nums.size()/2;
        // return nums[mid];
        if(nums.empty()) return -1;
        int n=nums.size(),counter=1,maj=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]==maj)
            {
                counter++;
            }
            else
            {
                counter--;
            }
            if(counter==0)
            {
                counter=1;
                maj=nums[i];
            }
        }
        return maj;
    }
};
