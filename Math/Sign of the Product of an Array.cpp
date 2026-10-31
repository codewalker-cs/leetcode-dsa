/*
Intuition:
- We need to find the sign of the product of all elements.
- If any element is zero, the product is zero.
- A product is negative if it contains an odd number of negative
  elements and positive if it contains an even number.

Approach:
1. Initialize a counter to track negative numbers.
2. Traverse the array:
   - If an element is zero, immediately return 0.
   - If an element is negative, increment the counter.
3. If the count of negative numbers is even, return 1.
4. Otherwise, return -1.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt=0;
        for(int x:nums)
        {
            if(x==0) return 0;
            if(x<0) cnt++;
        }
        return (cnt%2==0)?1:-1;
    }
};
