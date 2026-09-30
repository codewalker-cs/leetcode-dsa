/*
    Intuition:
    ------------
    We need to split the parentheses sequence into two valid
    sequences such that the maximum nesting depth is minimized.

    We can divide the parentheses based on their nesting depth:

        Odd depth  -> sequence 1
        Even depth -> sequence 0

    This distributes the nested parentheses between the two
    sequences and keeps their maximum depths balanced.

    We maintain the current nesting depth using `depth`.

    For '(':
        - We first enter a deeper level.
        - Assign it to `depth % 2`.

    For ')':
        - It belongs to the current depth.
        - Assign it to `depth % 2`.
        - Then decrease the depth.

    Example:

        seq = "((()))"

        Depths:
            ( -> 1 -> group 1
            ( -> 2 -> group 0
            ( -> 3 -> group 1
            ) -> 3 -> group 1
            ) -> 2 -> group 0
            ) -> 1 -> group 1

        Result:
            [1, 0, 1, 1, 0, 1]

    Approach:
    ----------
    1. Maintain the current nesting depth.
    2. For '(':
        - Increase depth.
        - Assign `depth % 2`.
    3. For ')':
        - Assign `depth % 2`.
        - Decrease depth.
    4. Return the resulting assignment array.

    Time Complexity:
    O(n)

    Space Complexity:
    O(n)

    The answer array contains one value for every parenthesis.
*/

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int d=0;

        for(char &c:seq)
        {
            if(c=='(')
            {
                d++;
                ans.push_back(d%2);
            }
            else
            {
                ans.push_back(d%2);
                d--;
            }
        }
        return ans;
    }
};
