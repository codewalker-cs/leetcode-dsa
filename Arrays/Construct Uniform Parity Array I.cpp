/*
    Intuition:

    We need to determine whether the array can become uniform,
    meaning all elements have the same parity.

    For every element:
        - If it is even, we check whether there is at least one
          odd element that can be used with it.
        - If it is odd, we check whether there is at least one
          even element that can be used with it.

    `odd` represents whether it is possible to make the array
    uniform with respect to odd elements.

    `even` represents whether it is possible to make the array
    uniform with respect to even elements.

    For two numbers:
        - even - odd = odd
        - odd - even = odd
        - even - even = even
        - odd - odd = even

    Therefore, the parity of the difference tells us whether
    two elements have different parity.

    Approach:
    1. Traverse every element.
    2. For an even element, search for an odd element.
    3. For an odd element, search for an even element.
    4. If the required opposite-parity element does not exist,
       mark that possibility as invalid.
    5. Return true if either possibility remains valid.

    Time Complexity:
        O(n^2)

    Space Complexity:
        O(1)
*/

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        bool odd = true;
        bool even = true;

        for (int i = 0; i < n; i++) {

            if (nums1[i] % 2 == 0) {
                // Check whether an odd element exists.
                bool valid = false;

                for (int j = 0; j < n; j++) {
                    if (i != j &&
                        abs(nums1[i] - nums1[j]) % 2 == 1) {
                        valid = true;
                    }
                }

                if (!valid) {
                    odd = false;
                }
            }
            else {
                // Check whether an even element exists.
                bool valid = false;

                for (int j = 0; j < n; j++) {
                    if (i != j &&
                        abs(nums1[i] - nums1[j]) % 2 == 0) {
                        valid = true;
                    }
                }

                if (!valid) {
                    even = false;
                }
            }
        }

        return odd | even;
    }
};
