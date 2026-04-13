/*
Intuition:
This problem simulates writing a string in a zigzag pattern across multiple rows.

Instead of actually building a 2D zigzag grid, we can observe the movement:
- We start from row 0 and move downward.
- Once we reach the last row, we reverse direction and move upward.
- When we reach the top again, we reverse direction and continue.

We maintain:
- A vector<string> where each index represents a row.
- A pointer `i` to track the current row.
- A direction variable `dir`:
    +1 → moving down
    -1 → moving up

For each character:
- Append it to the current row.
- Change direction only when we hit the top (row 0) or bottom (row numRows-1).
- Move to the next row using `i += dir`.

Finally, concatenate all rows to get the result.

Time Complexity:
O(n), where n = length of string

Space Complexity:
O(n), for storing rows
*/

#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     string convert(string s, int numRows) {
//         if(numRows==1) return s;
//         int i=0;
//         bool flag=true;
//         vector<vector<char>> ans(numRows);

//         for(char &c:s)
//         {
//             if(flag)
//             {
//                 ans[i].push_back(c);
//                 if(i<numRows-1)
//                 {
//                     i++;
//                 }
//                 else
//                 {
//                     flag=false;
//                     i--;
//                 }
//             }
//             else
//             {
//                 ans[i].push_back(c);
//                 if(i>0)
//                 {
//                     i--;
//                 }
//                 else
//                 {
//                     flag=true;
//                     i++;
//                 }
//             }    
//         }

//         string f;

//         for(int i=0;i<numRows;i++)
//         {
//             for(int j=0;j<ans[i].size();j++)
//             {
//                 f+=ans[i][j];
//             }
//         }
//         return f;
//     }
// };

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> rows(numRows);
        int i = 0, dir = 1;

        for (char c : s)
        {
            rows[i] += c;

            if (i == 0)
                dir = 1;
            else if (i == numRows - 1)
                dir = -1;

            i += dir;
        }

        string res;
        for (string &row : rows)
        {
            res += row;
        }

        return res;
    }
};
