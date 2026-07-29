/*
    Problem: 1742. Maximum Number of Balls in a Box

    Intuition:
    Every ball is placed into a box whose number is equal to the sum of its digits.
    For every number from lowLimit to highLimit:
    1. Find its digit sum.
    2. Increase the count of that corresponding box.
    3. Keep track of the maximum balls in any box.

    Since the maximum possible digit sum for the given constraints is small
    (9 + 9 + 9 + 9 + 9 = 45), we only need an array of size 50.

    Example:
    lowLimit = 1, highLimit = 10

    Ball 1  -> digit sum = 1 -> Box 1
    Ball 2  -> digit sum = 2 -> Box 2
    Ball 3  -> digit sum = 3 -> Box 3
    ...
    Ball 9  -> digit sum = 9 -> Box 9
    Ball 10 -> digit sum = 1 -> Box 1

    Box counts:
    Box 1 = 2
    Box 2 = 1
    Box 3 = 1
    ...
    Box 9 = 1

    Answer = 2

    Algorithm:
    1. Create an array to store the count of each box.
    2. Iterate through every number from lowLimit to highLimit.
    3. Compute its digit sum.
    4. Increment that box's count.
    5. Update the maximum count.
    6. Return the maximum.

    Time Complexity:
    O((highLimit - lowLimit + 1) * D)
    where D is the number of digits (at most 5).

    Space Complexity:
    O(1)
    Only a fixed-size array of 50 elements is used.
*/

class Solution {
public:
    int digitSum(int n) {
        int sum = 0;

        while (n) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int countBalls(int lowLimit, int highLimit) {
        vector<int> box(50, 0);
        int maxBall = 0;

        for (int i = lowLimit; i <= highLimit; i++) {
            int idx = digitSum(i);

            box[idx]++;
            maxBall = max(maxBall, box[idx]);
        }

        return maxBall;
    }
};
