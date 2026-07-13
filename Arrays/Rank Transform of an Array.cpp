/*
    ------------------------------------------------------------
    Intuition
    ------------------------------------------------------------
    We need to replace every number with its rank.

    Rules:
    - Smallest unique number gets rank 1.
    - Equal numbers receive the same rank.
    - Larger unique numbers receive increasing ranks.

    The easiest approach is:
    1. Create a copy of the array.
    2. Sort the copy.
    3. Traverse the sorted array and assign ranks only to the first
       occurrence of every unique value.
    4. Traverse the original array and replace every element with
       its stored rank using a hash map.

    ------------------------------------------------------------
    Example
    ------------------------------------------------------------
    arr = [40, 10, 20, 30]

    Copy after sorting:
    [10, 20, 30, 40]

    Rank Map:
    10 -> 1
    20 -> 2
    30 -> 3
    40 -> 4

    Final Answer:
    [4, 1, 2, 3]

    ------------------------------------------------------------
    Algorithm
    ------------------------------------------------------------
    1. Copy the original array.
    2. Sort the copied array.
    3. Assign ranks to unique elements.
    4. Replace every original element with its rank.
    5. Return the transformed array.

    ------------------------------------------------------------
    Time Complexity
    ------------------------------------------------------------
    Sorting : O(n log n)
    Mapping : O(n)

    Overall : O(n log n)

    ------------------------------------------------------------
    Space Complexity
    ------------------------------------------------------------
    O(n)
*/
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty())
            return {};

        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> rank;
        int currentRank = 1;

        rank[sorted[0]] = currentRank;

        for (int i = 1; i < sorted.size(); i++) {
            if (sorted[i] != sorted[i - 1]) {
                currentRank++;
            }
            rank[sorted[i]] = currentRank;
        }

        vector<int> ans;

        for (int num : arr) {
            ans.push_back(rank[num]);
        }

        return ans;
    }
};
