/*
    Intuition:
    ------------
    We want to maximize the alternating sum of squares:

        nums[0]² - nums[1]² + nums[2]² - nums[3]² + ...

    Since squaring makes every value non-negative, the sign of the
    original number does not matter. We can sort the elements by
    decreasing absolute value.

    The key idea is to place larger absolute values at positive
    positions and smaller absolute values at negative positions.

    After sorting:
        - The largest absolute values are at the beginning.
        - The smallest absolute values are at the end.

    We use two pointers:
        l = beginning of the array
        r = end of the array

    For every pair:
        - Add the square of nums[l].
        - Subtract the square of nums[r], if they are different
          positions.
        - Move both pointers toward the center.

    This pairs larger squares with smaller squares to maximize the
    alternating sum.

    Approach:
    ----------
    1. Sort the array by decreasing absolute value.
    2. Initialize two pointers at the beginning and end.
    3. Add the square of the left element.
    4. Subtract the square of the right element if l != r.
    5. Move both pointers toward the center.
    6. Return the accumulated result.

    Time Complexity:
    O(n log n)

    Sorting takes O(n log n), and the two-pointer traversal takes O(n).

    Space Complexity:
    O(log n) auxiliary space for sorting, depending on the sort
    implementation.
*/

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a,int b) {
            return abs(a)>abs(b);
        });
        long long ans=0;
        int l=0,r=nums.size()-1;

        while(l<=r)
        {
            ans+=1LL*nums[l]*nums[l];
            if(l!=r)
            {
                ans-=1LL*nums[r]*nums[r];
            }

            l++;
            r--;
        }

        return ans;
    }
};
