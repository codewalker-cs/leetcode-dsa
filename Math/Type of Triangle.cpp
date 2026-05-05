// Intuition:
// We are given three side lengths of a triangle.
// First, we must check whether these sides can form a valid triangle.
// A triangle is valid only if the sum of any two sides is strictly greater than the third.
// If this condition fails, we return "none".
//
// If the triangle is valid:
// - If all three sides are equal, it is an equilateral triangle.
// - If any two sides are equal, it is an isosceles triangle.
// - Otherwise, all sides are different, so it is a scalene triangle.
//
// Note:
// The isosceles condition can be simplified to (a == b || b == c || a == c)
// because the equilateral case is already handled before it.

class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        if (a + b <= c || b + c <= a || a + c <= b) return "none";
        if (a == b && b == c) return "equilateral";
        if ((a == b && b != c) || (b == c && a != c) || (a == c && b != c)) return "isosceles";
        return "scalene";
    }
};
