/*
Intuition 1 (Mark Visited Cells)

Instead of maintaining four boundaries, we mark every visited cell with a special value
(INT_MIN). Starting from the top-left corner, we repeatedly move in the order:

Right → Down → Left → Up

Whenever we encounter a visited cell or go out of bounds, we change direction.
After completing one full cycle, we continue from the next inner layer.

Example:
Matrix:
1 2 3
4 5 6
7 8 9

Step 1: Move Right
1 → 2 → 3

Matrix:
X X X
4 5 6
7 8 9

Step 2: Move Down
6 → 9

Matrix:
X X X
4 5 X
7 8 X

Step 3: Move Left
8 → 7

Matrix:
X X X
4 5 X
X X X

Step 4: Move Up
4

Matrix:
X X X
X 5 X
X X X

Step 5: Move Right
5

Answer:
1 2 3 6 9 8 7 4 5

Time Complexity: O(n × m)

Space Complexity: O(1) (excluding the output array)

Note:
This approach modifies the original matrix and assumes INT_MIN is not already present.
*/


/*
Intuition 2 (Four Boundary Traversal)

Observe that spiral traversal always processes the outermost layer first and then
moves inward. Instead of marking cells as visited, maintain four boundaries:

top    -> first unvisited row
bottom -> last unvisited row
left   -> first unvisited column
right  -> last unvisited column

Traversal order:

1. Traverse Left → Right on the top row.
   Then increment top.

2. Traverse Top → Bottom on the right column.
   Then decrement right.

3. Traverse Right → Left on the bottom row
   (only if top <= bottom).
   Then decrement bottom.

4. Traverse Bottom → Top on the left column
   (only if left <= right).
   Then increment left.

Repeat until all boundaries cross.

Example:
Matrix:
1 2 3
4 5 6
7 8 9

Initial:
top = 0
bottom = 2
left = 0
right = 2

Round 1:
Top Row    : 1 2 3
Right Col  : 6 9
Bottom Row : 8 7
Left Col   : 4

Updated:
top = 1
bottom = 1
left = 1
right = 1

Round 2:
Top Row : 5

Answer:
1 2 3 6 9 8 7 4 5

Time Complexity: O(n × m)

Space Complexity: O(1)

Why this is better?
- Does not modify the input matrix.
- No special marker value is required.
- Cleaner and easier to reason about.
- Standard interview solution.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // int n=matrix.size(),m=matrix[0].size();
        // vector<int> ans;
        // bool flag=true;
        // int i=0,j=0;

        // while(flag)
        // {
        //     flag=false;
        
        //     while(j<m && matrix[i][j]!=INT_MIN)
        //     {
        //         ans.push_back(matrix[i][j]);
        //         matrix[i][j]=INT_MIN;
        //         j++;
        //         flag=true;
        //     }
        //     j--;
        //     i++;

        //     while(i<n && matrix[i][j]!=INT_MIN)
        //     {
        //         ans.push_back(matrix[i][j]);
        //         matrix[i][j]=INT_MIN;
        //         i++;
        //         flag=true;
        //     }
        //     i--;
        //     j--;

        //     while(j>=0 && matrix[i][j]!=INT_MIN)
        //     {
        //         ans.push_back(matrix[i][j]);
        //         matrix[i][j]=INT_MIN;
        //         j--;
        //         flag=true;
        //     }
        //     j++;
        //     i--;

        //     while(i>=0 && matrix[i][j]!=INT_MIN)
        //     {
        //         ans.push_back(matrix[i][j]);
        //         matrix[i][j]=INT_MIN;
        //         i--;
        //         flag=true;
        //     }
        //     i++;
        //     j++;
        // }
        // return ans;

        vector<int> ans;

        int top=0,right=matrix[0].size()-1,bottom=matrix.size()-1,left=0;

        while(top<=bottom && left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;

            for(int i=top;i<=bottom;i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;

            if(top<=bottom)
            {
                for(int i=right;i>=left;i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left<=right)
            {
                for(int i=bottom;i>=top;i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
