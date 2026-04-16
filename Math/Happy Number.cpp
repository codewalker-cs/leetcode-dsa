// Happy Number - Floyd Cycle Detection (Optimal)
//
// Intuition:
// Instead of storing visited numbers, we detect a cycle using two pointers:
// - slow moves one step (sum of squares once)
// - fast moves two steps (sum of squares twice)
//
// If there's a cycle (not including 1), slow and fast will meet at some number ≠ 1.
// If the number is happy, both pointers will eventually meet at 1.

class Solution {
public:
    int getNext(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n;
        int fast = n;

        do
        {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        } while (slow != fast);

        return slow == 1;
    }
};
