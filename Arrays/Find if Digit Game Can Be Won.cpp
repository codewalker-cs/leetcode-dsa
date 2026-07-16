/*
    Intuition:
    ----------
    Alice has two possible strategies:
    1. Take all single-digit numbers (0 to 9).
    2. Take all double-digit numbers (10 to 99).

    Let:
    - singleDigitSum = sum of all single-digit numbers.
    - doubleDigitSum = sum of all remaining numbers.

    If both sums are equal, no matter which strategy Alice chooses,
    she cannot end up with a strictly larger total than Bob.

    If the sums are different, Alice simply chooses the group with
    the larger sum and wins.

    Therefore, Alice can win if and only if:
        singleDigitSum != doubleDigitSum

    Example:
    --------
    nums = [1, 2, 10, 20]

    singleDigitSum = 1 + 2 = 3
    doubleDigitSum = 10 + 20 = 30

    Since 3 != 30,
    Alice chooses the double-digit numbers and wins.

    Time Complexity:
    ----------------
    O(n)

    Space Complexity:
    -----------------
    O(1)
*/

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int s1=0,s2=0;
        for(int i:nums)
        {
            if(i<=9 && i>=0)
            {
                s1+=i;
            }
            else
            {
                s2+=i;
            }
        }
        return s1!=s2;
    }
};
