// LeetCode 128 - Longest Consecutive Sequence

/*
    Intuition:
    - Duplicate numbers do not help in forming a longer consecutive sequence,
      so we first store all elements in a set.
    - A set keeps elements unique and sorted.
    - Once sorted, consecutive numbers will appear next to each other.
    - Traverse the set and count the length of each consecutive streak.
    - Update the maximum streak length whenever the sequence breaks.

    Example:
    nums = [100,4,200,1,3,2]

    set = {1,2,3,4,100,200}

    Consecutive sequence:
    1 -> 2 -> 3 -> 4  (length = 4)

    Answer = 4
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return 0;
        }

        // Store unique elements in sorted order
        set<int> st;

        for (int num : nums) {
            st.insert(num);
        }

        int currLength = 1;
        int maxLength = 1;

        auto prev = st.begin();
        auto curr = next(st.begin());

        while (curr != st.end()) {

            // Consecutive element found
            if ((*prev + 1) == *curr) {
                currLength++;
            }
            else {
                maxLength = max(maxLength, currLength);
                currLength = 1;
            }

            prev = curr;
            curr = next(curr);
        }

        maxLength = max(maxLength, currLength);

        return maxLength;
    }
};
