/*
    Intuition:
    ------------
    Each child has a minimum greed factor `g[i]`, and each cookie
    has a size `s[j]`.

    A child is content if the cookie size is at least their greed:

        s[j] >= g[i]

    To maximize the number of content children, we sort both arrays
    and always try to give the smallest cookie that can satisfy the
    least greedy remaining child.

    This greedy strategy avoids wasting large cookies on children
    who could be satisfied with smaller ones.

    Approach:
    ----------
    1. Sort the greed factors and cookie sizes.
    2. Use two pointers:
           i -> current child
           j -> current cookie
    3. If the current cookie can satisfy the current child:
           s[j] >= g[i]
       assign it and move to the next child.
    4. Always move to the next cookie.
    5. The number of satisfied children is `i`.

    Time Complexity:
    O(n log n + m log m)

    Space Complexity:
    O(1) extra space
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        int j = 0;

        while(i < g.size() && j < s.size()) {
            if(s[j] >= g[i]) {
                i++;
            }

            j++;
        }

        return i;
    }
};
