/*
Intuition:
We are given a string where:
- 'L' means move left
- 'R' means move right
- '_' means we can choose either 'L' or 'R'

To maximize the distance from origin:
1. Count total 'L' moves → x
2. Count total 'R' moves → y
3. Count total '_' moves → z

The current displacement without '_' is |x - y|.
Since '_' can be assigned optimally, we use all of them to
increase this difference further.

So, final answer = |x - y| + z

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int x = 0, y = 0, z = 0;

        for(char &c : moves)
        {
            if(c == 'L') x++;
            else if(c == 'R') y++;
            else z++;
        }

        int diff = (x > y) ? x - y : y - x;
        return diff + z;
    }
};
