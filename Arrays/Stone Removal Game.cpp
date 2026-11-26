/*
Intuition:
Alice and Bob take turns removing stones.
The first move removes 10 stones, and each subsequent move
removes one fewer stone than the previous move.

The player who cannot make a move loses.

Approach:
1. Initialize st = 10, representing the number of stones to remove.
2. Use a boolean variable a to track the current winner:
   - a = 0 means Bob.
   - a = 1 means Alice.
3. While n >= st:
   - Remove st stones.
   - Decrease st by 1.
   - Toggle the winner using XOR.
4. Return a.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    bool canAliceWin(int n) {
        bool a = 0;
        int st = 10;

        while (n >= st) {
            n -= st--;
            a ^= 1;
        }

        return a;
    }
};
