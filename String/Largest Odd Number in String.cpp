/*
    Intuition:
    ------------------------------------------------------------
    We need to find the largest-valued odd integer that is a
    substring of num.

    Since the substring must be contiguous, we want to keep as
    many digits from the left as possible.

    An integer is odd if and only if its last digit is odd.

    Therefore, we only need to find the rightmost odd digit.

    If the rightmost odd digit is at index i, then:

        num[0...i]

    is odd because its last digit is odd.

    It is also the largest possible odd substring because any
    substring ending before i contains fewer digits, while a
    substring ending after i would have an even last digit.

    ------------------------------------------------------------
    Example 1:
    
        num = "35427"

        Odd digits:
            3 -> odd
            5 -> odd
            4 -> even
            2 -> even
            7 -> odd

        Rightmost odd digit = 7

        Answer = "35427"

    ------------------------------------------------------------
    Example 2:

        num = "4206"

        There is no odd digit.

        Therefore, no odd integer exists.

        Answer = ""

    ------------------------------------------------------------
    Example 3:

        num = "123456"

        Rightmost odd digit = 5

        Answer = "12345"

    ------------------------------------------------------------
    Time Complexity:
        O(n)

    We scan the string from right to left.

    ------------------------------------------------------------
    Space Complexity:
        O(1)

    Ignoring the space required for the returned string.
*/

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i=num.size()-1;i>=0;i--)
        {
            if((num[i]-'0')%2==1)
            {
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};
