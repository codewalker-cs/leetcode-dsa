/*
    Intuition:
    ------------
    We consider every possible rotation of the string.

    Instead of actually rotating the string each time, we observe
    that a rotation only changes which adjacent pair is considered
    the boundary of the string.

    First, count how many adjacent equal pairs exist in the original
    circular string:

        s[i] == s[(i + 1) % n]

    Let this count be `cnt`.

    For a rotation starting at index i, the only pair that changes
    compared to the original circular arrangement is the pair
    crossing the new boundary:

        s[i - 1] and s[i]

    If these two characters are equal, that pair is no longer an
    adjacent pair inside the rotated string, so we subtract one.

    Therefore:

        same = cnt - (s[i - 1] == s[i])

    If `same == k`, this rotation is valid.

    Approach:
    ----------
    1. Count equal adjacent pairs in the circular string.
    2. Try every possible rotation starting at index i.
    3. Identify the pair crossing the new boundary using:
           prev = (i - 1 + n) % n
    4. Subtract that pair if its characters are equal.
    5. Count rotations where the remaining equal adjacent pairs
       are exactly k.

    Time Complexity:
    O(n)

    Space Complexity:
    O(1)
*/

class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==s[(i+1)%n]) c++;
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            int p=(i-1+n)%n;
            int su=c;
            if(s[p]==s[i]) su--;
            if(su==k) ans++;
        }
        return ans;
    }
};
