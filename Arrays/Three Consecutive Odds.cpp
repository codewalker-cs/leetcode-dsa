/*
Intuition:
We need to check whether the array contains 3 consecutive odd numbers.

Approach:
- Maintain a counter `an` to track consecutive odd numbers.
- Traverse the array:
    - If current number is odd:
        increment the counter.
    - Otherwise:
        reset the counter to 0.
- If counter becomes 3 at any point,
  return true immediately.

Example:
arr = [2,6,4,1,3,5]

1 -> odd  -> count = 1
3 -> odd  -> count = 2
5 -> odd  -> count = 3

Hence return true.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size(),an=0;

        for(int i=0;i<n;i++)
        {
            if(arr[i]%2!=0)
            {
                an++;
            }
            else
            {
                an=0;
            }

            if(an==3) return true;
        }

        return false;
    }
};
