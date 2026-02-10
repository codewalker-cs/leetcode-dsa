/*
Intuition:
We are asked to XOR all elements of a virtual array where:

nums[i] = start + 2*i

Instead of storing the entire array (which would take extra space),
we compute XOR on the fly.

We initialize the result with the first element,
then keep XOR-ing the remaining generated values.

This keeps space complexity O(1) and time complexity O(n).

Example:
n = 4, start = 3
nums = [3, 5, 7, 9]
result = 3 ^ 5 ^ 7 ^ 9
*/

class Solution {
public:
    int xorOperation(int n, int start) {
        int oro=start+2*0;
        for(int i=1;i<n;i++)
        {
            oro=oro^(start+2*i);
        }
        return oro;
    }
};
