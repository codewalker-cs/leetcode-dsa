/*
    Intuition:
    -----------
    Two strings are isomorphic if there exists a one-to-one mapping between
    their characters.

    We maintain two hash maps:
    1. map1 : Maps characters from string 's' to string 't'.
    2. map2 : Maps characters from string 't' back to string 's'.

    Why two maps?
    - map1 ensures that a character in 's' always maps to the same character in 't'.
    - map2 ensures that two different characters in 's' cannot map to the same
      character in 't'.

    If either condition is violated, the strings are not isomorphic.

    --------------------------------------------------------------------

    Example:
    --------
    s = "egg"
    t = "add"

    Initially:
    map1 = {}
    map2 = {}

    i = 0
    s[i] = 'e', t[i] = 'a'

    'e' not present in map1.
    'a' not present in map2.

    map1 = { e -> a }
    map2 = { a -> e }

    ------------------------------------------------

    i = 1
    s[i] = 'g', t[i] = 'd'

    'g' not present.
    'd' not present.

    map1 = { e -> a, g -> d }
    map2 = { a -> e, d -> g }

    ------------------------------------------------

    i = 2
    s[i] = 'g', t[i] = 'd'

    'g' already maps to 'd'.

    Mapping is consistent.

    Return true.

    --------------------------------------------------------------------

    Counter Example:
    ----------------
    s = "ab"
    t = "aa"

    i = 0
    map1 = { a -> a }
    map2 = { a -> a }

    i = 1
    'b' is new.
    But 'a' already exists in map2,
    meaning another character is already mapped to it.

    Return false.

    --------------------------------------------------------------------

    Time Complexity: O(n)
    - Each character is processed once.
    - Hash map operations are O(1) on average.

    Space Complexity: O(1)
    - At most 256 unique ASCII characters (or O(k) where k is the character set size).
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        unordered_map<char,char> map1,map2;

        for(int i=0;i<n;i++)
        {
            if(map1.find(s[i])==map1.end())
            {
                if(map2.find(t[i])!=map2.end()) return false;
                map1[s[i]]=t[i];
                map2[t[i]]=s[i];
            }
            else
            {
                if(map1[s[i]]!=t[i]) return false;
            }
        }
        return true;
    }
};
