/*
 Judge Route Circle (LeetCode 657)
 --------------------------------

 Approach: Count Net Displacement

 ------------------------------------------------------------
 Intuition:
 ------------------------------------------------------------

 The robot starts at (0, 0).

 Each move changes position:
   'R' → x + 1
   'L' → x - 1
   'U' → y + 1
   'D' → y - 1

 To return to origin:
   - Total 'R' must equal total 'L'
   - Total 'U' must equal total 'D'

 Instead of counting separately, we track final (x, y).

 If (x == 0 && y == 0), robot is back at origin.

 ------------------------------------------------------------
 Time Complexity: O(n)
 Space Complexity: O(1)
 ------------------------------------------------------------
*/

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;

        for (char move : moves)
        {
            if (move == 'R') x++;
            else if (move == 'L') x--;
            else if (move == 'U') y++;
            else if (move == 'D') y--;
        }

        return (x == 0 && y == 0);
    }
};
