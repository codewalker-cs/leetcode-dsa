/*
    Problem: Count Prime Set Bits

    Intuition:
    1. For every number in range [left, right]:
        - Count number of set bits in its binary representation.
    2. Check if that count is a prime number.
    3. If prime → increase answer.

    Important Fixes Made:
    - Correct prime checking logic.
    - Handle case when set bit count <= 1.
    - Loop condition corrected to include 'right'.

    Time Complexity:
        O(N * log(num))
        N = (right - left + 1)
        log(num) for counting bits

    Space Complexity:
        O(1)
*/

class Solution {
public:
    bool checkprime(int num)
    {
        int countset=0;
        while(num!=0)
        {
            int bit=num&1;
            if(bit==1)
            {
                countset++;
            }
            num=num>>1;
        }
        if(countset <= 1)
        {
            return false;
        }
        
        for(int i=2;i<countset;i++)
        {
            if(countset%i==0)
            {
                return false;
            }
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int count=0;
        while(left<=right)
        {
            int num=left;
            if(checkprime(num))
            {
                count++;
            }
            left++;
        }
        return count;
    }
};
