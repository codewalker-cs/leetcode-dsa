/*
    Intuition:
    ------------
    We have a circular dial containing digits from 0 to 9.

    The dial starts at digit 0. For every digit in the string, we
    need to move the dial from the current digit to the target digit.

    Since the dial is circular, there are two possible ways to move:

        1. Direct distance:
               abs(target - current)

        2. Wrap-around distance:
               10 - abs(target - current)

    We always choose the smaller of these two distances.

    After reaching the target digit, it becomes the current position
    for the next digit.

    Approach:
    ----------
    1. Start from digit 0.
    2. Traverse every digit in the string.
    3. Calculate the direct distance between the current and target
       digits.
    4. Take the minimum of the direct and wrap-around distances.
    5. Add it to the total answer.
    6. Update the current position.

    Example:
        Current = 0
        Target = 9

        Direct distance = |9 - 0| = 9
        Wrap-around     = 10 - 9 = 1

        Minimum = 1

    Time Complexity:
    O(n)

    Space Complexity:
    O(1)
*/

class Solution {
public:
    int minRotations(string s) {
        int ans=0;
        int curr=0;
        for(int i=0;i<10;i++)
        {
            int t=s[i]-'0';
            int diff=abs(t-curr);
            ans+=min(diff,10-diff);
            curr=t;
        }
        return ans;
    }
};
