// Intuition:
// A number has a trailing zero in binary if its last bit is 0.
// That means the number must be even.
//
// For the bitwise OR of two numbers to also end in 0,
// both chosen numbers must be even.
//
// Cases:
// even | even = even   -> trailing zero exists
// even | odd  = odd
// odd  | odd  = odd
//
// So the problem becomes:
// Check whether the array contains at least two even numbers.
//
// Approach:
// 1. Traverse the array once.
// 2. Count how many even numbers appear.
// 3. As soon as count reaches 2, return true.
// 4. If traversal ends before that, return false.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int ev=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                ev++;
            }

            if(ev==2)
            {
                return true;
            }
        }
        return false;
    }
};
