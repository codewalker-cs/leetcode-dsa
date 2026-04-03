/*
 Pascal's Triangle (LeetCode 118)
 --------------------------------

 Approach used: DP (Pascal's Identity)

 ------------------------------------------------------------
 Intuition 1: DP (Pascal Identity)
 ------------------------------------------------------------

 Each element is formed using:

     value = top + top-left

 Mathematically:

     C(n, r) = C(n-1, r) + C(n-1, r-1)

 So:
 - First and last elements of every row are 1
 - Middle elements are sum of two values from previous row

 Example:
     [1, 2, 1]
        ↓ ↓
     [1, 3, 3, 1]

 ------------------------------------------------------------
 Intuition 2: nCr (Combinatorics)
 ------------------------------------------------------------

 Each row 'n' is:

     C(n,0), C(n,1), C(n,2), ..., C(n,n)

 Where:
     C(n, r) = number of ways to choose r elements from n

 Formula:
     C(n, r) = n! / (r! * (n - r)!)

 Optimized relation:
     C(n, r) = C(n, r-1) * (n - r + 1) / r

 This shows that Pascal's Triangle is a visual representation
 of combinations. The DP relation and nCr represent the same idea.

 ------------------------------------------------------------
 Complexity
 ------------------------------------------------------------

 Time:  O(n^2)
 Space: O(n^2)
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i = 0; i < numRows; i++) {
            vector<int> n;
            
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) {
                    n.push_back(1);
                }
                else {
                    n.push_back(ans[i-1][j] + ans[i-1][j-1]);
                }
            }
            
            ans.push_back(n);
        }
        
        return ans;
    }
};

// ------------- or ----------------


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i = 0; i < numRows; i++) {
            vector<int> row;
            long long val = 1;

            for(int j = 0; j <= i; j++) {
                row.push_back(val);
                val = val * (i - j) / (j + 1);
            }

            ans.push_back(row);
        }

        return ans;
    }
};
