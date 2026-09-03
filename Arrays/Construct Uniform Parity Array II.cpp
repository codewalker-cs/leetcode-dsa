/*
    Intuition:
    ------------
    We need to check whether every even element can be made valid
    using the smallest odd element in the array.

    The smallest odd value gives us the best possible chance because
    we only need to check whether:

        even - minOdd >= 1

    If there is no odd element at all, the array is already uniform,
    so we can directly return true.

    Approach:
    ----------
    1. Find the smallest odd element in the array.
    2. If no odd element exists, return true.
    3. For every even element, check whether it is strictly greater
       than the smallest odd element.
    4. If any even element is smaller than or equal to minOdd,
       return false.
    5. Otherwise, return true.

    Time Complexity:
    O(n)

    Space Complexity:
    O(1)
*/

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        for(auto n : nums1){
            if(n%2){
                minOdd = min(minOdd, n);
            }
        }

        if(minOdd == INT_MAX){
            return true;
        }

        for(auto n : nums1){
            if(n%2 == 0 && !(n - minOdd >= 1))
                return false;
        }
        return true;
    }
};
