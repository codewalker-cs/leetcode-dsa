/*
Intuition:
- To reverse a string, swap the first character with the last,
  the second character with the second-last, and so on.
- We only need to perform swaps for the first half of the array.
- Recursion can be used to move inward after every swap.

Approach:
1. Start with index l = 0.
2. If l reaches n / 2, stop the recursion.
3. Swap s[l] with s[n - l - 1].
4. Recursively call the function with l + 1.
5. The string gets reversed after all swaps are completed.

Time Complexity: O(n)
Space Complexity: O(n) due to the recursion stack.
*/

class Solution {
public:
    void rev(int l,vector<char>& s,int n)
    {
        if(l==n/2)
        {
            return ;
        }
        swap(s[n-l-1],s[l]);
        rev(l+1,s,n);
    }

    void reverseString(vector<char>& s) {
        int n=s.size();
        rev(0,s,n);
    }
};
