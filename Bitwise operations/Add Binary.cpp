/*
    Intuition:
    ------------
    We need to add two binary strings without converting them into
    decimal numbers.

    Just like normal addition, we start from the rightmost bit and
    keep track of a `carry`.

    For every position:
        sum = current bit of a + current bit of b + carry

    The resulting bit is:

        sum % 2

    And the carry for the next position is:

        sum / 2

    Since the strings can have different lengths, we continue while
    either string still has digits or a carry remains.

    Approach:
    ----------
    1. Start from the last character of both strings.
    2. Add the current bits and the carry.
    3. Store `sum % 2` in the answer.
    4. Update the carry using `sum / 2`.
    5. Continue until both strings are processed and there is no carry.
    6. The answer is built backwards, so reverse it before returning.

    Time Complexity:
    O(max(n, m))

    Space Complexity:
    O(max(n, m))
*/

class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
      if (i >= 0)
        carry += a[i--] - '0';
    
      if (j >= 0)
        carry += b[j--] - '0';
    
      ans += carry % 2 + '0';
      carry /= 2;
    }

    reverse(begin(ans), end(ans));
    return ans;
  }
};
