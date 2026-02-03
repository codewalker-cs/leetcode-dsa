/*
Intuition:
-----------
A trionic array must follow 3 strict phases:

1) strictly increasing
2) strictly decreasing
3) strictly increasing

Each phase must exist (at least one step), and the array must end
exactly after the third phase.

We walk the array once using two pointers (l, r) that represent
adjacent elements. We advance through each phase and record the
boundaries to ensure no phase is skipped.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:

    // -------------------------------
    // Version 1: My implementation
    // -------------------------------
    bool isTrionic_user(vector<int>& nums) {
        int l = 0, r = 1, n = nums.size() - 1, p, q;
        if (n + 1 < 3) return false;

        // phase 1: increasing
        while (r < n + 1 && nums[l] < nums[r]) {
            l++;
            r++;
        }

        p = r;
        if (r > n || p == 1) return false;

        // phase 2: decreasing
        while (r < n + 1 && nums[l] > nums[r]) {
            l++;
            r++;
        }

        q = r;
        if (r > n || p == q) return false;

        // phase 3: increasing
        int start = r;
        while (r < n + 1 && nums[l] < nums[r]) {
            l++;
            r++;
        }

        return (r == n + 1 && start != r);
    }


    // -------------------------------------
    // Version 2: Cleaner optimized version
    // -------------------------------------
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int i = 1;

        // phase 1: increasing
        while (i < n && nums[i] > nums[i-1]) i++;
        if (i == 1 || i == n) return false;

        // phase 2: decreasing
        int downStart = i;
        while (i < n && nums[i] < nums[i-1]) i++;
        if (i == downStart || i == n) return false;

        // phase 3: increasing
        int upStart = i;
        while (i < n && nums[i] > nums[i-1]) i++;

        return i == n && i != upStart;
    }
};
