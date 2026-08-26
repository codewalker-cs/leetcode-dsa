/*
    Intuition:
    We need to find the smallest positive multiple of k
    that does not exist in nums.

    Approach:
    1. Start with the first positive multiple, k.
    2. Check whether k exists in nums.
    3. If it exists, move to the next multiple: 2k, 3k, ...
    4. Return the first multiple that is not present.

    Example:
    nums = [2, 4, 6, 8]
    k = 2

    Multiples:
    2  -> present
    4  -> present
    6  -> present
    8  -> present
    10 -> missing

    Answer = 10

    Time Complexity:
    O(n * m)

    where:
    n = size of nums
    m = number of multiples checked

    Space Complexity:
    O(1)
*/

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int multiple = k;

        while (true) {
            if (find(nums.begin(), nums.end(), multiple) == nums.end()) {
                return multiple;
            }

            multiple += k;
        }
    }
};
