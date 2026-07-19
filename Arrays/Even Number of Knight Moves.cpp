/*
    -------------------------------------------------------
    Intuition:
    -------------------------------------------------------
    A bishop can only move diagonally, which means it always
    stays on the same colored squares throughout the game.

    The color of a square is determined by the parity of
    (row + column):
        - Even  -> One color (e.g., Black)
        - Odd   -> Other color (e.g., White)

    Therefore, the bishop can reach the destination if and
    only if both the starting and ending squares have the
    same parity of (row + column).

    -------------------------------------------------------
    Example:
    -------------------------------------------------------
    start = [1, 1]
    end   = [3, 3]

    Start Color:
        (1 + 1) % 2 = 0

    End Color:
        (3 + 3) % 2 = 0

    Both squares have the same color, so the bishop can
    reach the destination.

    -------------------------------------------------------
    Algorithm:
    -------------------------------------------------------
    1. Compute the parity of the starting square.
    2. Compute the parity of the ending square.
    3. If both parities are equal, return true.
    4. Otherwise, return false.

    -------------------------------------------------------
    Time Complexity:
    -------------------------------------------------------
    O(1)

    -------------------------------------------------------
    Space Complexity:
    -------------------------------------------------------
    O(1)
*/

class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& end) {
        if ((start[0] + start[1]) % 2 == (end[0] + end[1]) % 2) {
            return true;
        }

        return false;
    }
};
