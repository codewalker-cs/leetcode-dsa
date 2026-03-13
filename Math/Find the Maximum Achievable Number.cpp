/*
Intuition:
-----------
We are given an integer `num` and allowed to perform at most `t` operations.
In each operation:
    - x changes by +1 or -1
    - num changes by +1 or -1 simultaneously

The key observation is that in one operation we can increase x by 1 and
decrease num by 1. This increases the gap between them by 2.

To maximize x, we always choose:
    x = x + 1
    num = num - 1

Each operation effectively allows x to move 2 units ahead relative to num.

After t operations, the maximum achievable value of x becomes:
        x = num + 2*t

This works because the operations allow shifting both numbers while still
making it possible for them to become equal within the allowed moves.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + 2 * t;
    }
};
