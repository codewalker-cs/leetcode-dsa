/*
    Intuition:
    ------------
    We are interested in adjacent pairs.

    There are two types of adjacent pairs:

    1. Already equal:
           nums[i] == nums[i - 1]

       These pairs are already contributing to the answer, so we
       count them in `eq`.

    2. Different:
           nums[i] != nums[i - 1]

       For these pairs, we store the unordered pair of values:

           (min(nums[i], nums[i - 1]),
            max(nums[i], nums[i - 1]))

       Using min/max ensures that:

           (2, 5) and (5, 2)

       are treated as the same pair.

    The pair that occurs most frequently among the unequal adjacent
    pairs can contribute the maximum additional number of equal
    adjacent pairs.

    Therefore:

        answer = already_equal + maximum_frequency

    Approach:
    ----------
    1. Traverse all adjacent pairs.
    2. Count pairs that are already equal.
    3. For unequal pairs, normalize them using min/max and store
       their frequency.
    4. Find the maximum frequency among these pairs.
    5. Return `eq + maximum_frequency`.

    Time Complexity:
    O(n log n)

    The map operations take O(log n).

    Space Complexity:
    O(n)

    In the worst case, there can be O(n) distinct adjacent pairs.
*/

class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n=nums.size(),eq=0;
        map<pair<int,int>,int> freq;

        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            {
                eq++;
            }
            else
            {
                int x=min(nums[i],nums[i-1]);
                int y=max(nums[i],nums[i-1]);
                freq[{x,y}]++;
            }
        }

        int b=0;
        for(auto &[p,c]:freq)
        {
            b=max(b,c);
        }
        return eq+b;
    }
};
