/*
    Problem: Minimum Operations to Make the String Alternating

    Intuition:
    A binary alternating string can only have two possible patterns:

        Pattern 1 : 010101...
        Pattern 2 : 101010...

    Any valid alternating string must match one of these patterns.
    Therefore, instead of modifying the string greedily, we simply
    count how many positions differ from each pattern.

    Steps:
    1. Traverse the string once.
    2. Count mismatches with:
            Pattern1 → even index = '0', odd index = '1'
            Pattern2 → even index = '1', odd index = '0'
    3. The minimum mismatches among the two patterns is the answer.

    Example:
        s = "0100"

        Compare with 0101
        0 1 0 0
        0 1 0 1
              ^
        mismatches = 1

        Compare with 1010
        0 1 0 0
        1 0 1 0
        ^ ^ ^
        mismatches = 3

        Minimum = 1

    Time Complexity: O(n)
        We traverse the string once.

    Space Complexity: O(1)
        Only counters are used.
*/

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int p1 = 0, p2 = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] != (i % 2 ? '1' : '0')) p1++;
            if(s[i] != (i % 2 ? '0' : '1')) p2++;
        }

        return min(p1, p2);
    }
};
