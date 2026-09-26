/*
    Intuition:
    ------------
    A queen in chess can move any number of squares in one move
    along:

        1. The same row
        2. The same column
        3. The same diagonal

    Therefore, we only need to check whether the source and target
    positions can be connected in one queen move.

    Let:

        dx = |source[0] - target[0]|
        dy = |source[1] - target[1]|

    Cases:

    1. source == target
       The queen is already at the target.

       Answer = 0

    2. Same row:
           dx == 0

    3. Same column:
           dy == 0

    4. Same diagonal:
           dx == dy

       In all these cases, the queen can reach the target in one move.

    Otherwise, a queen can always reach any other square in at most
    two moves on a standard chess board.

    Approach:
    ----------
    1. If source and target are the same, return 0.
    2. If they share a row, column, or diagonal, return 1.
    3. Otherwise, return 2.

    Time Complexity:
    O(1)

    Space Complexity:
    O(1)
*/

class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        if(source==target) return 0;
        if((abs(source[0]-target[0]) == abs(source[1]-target[1])) || source[0]==target[0] || source[1]==target[1]) return 1;
        return 2;
    }
};
