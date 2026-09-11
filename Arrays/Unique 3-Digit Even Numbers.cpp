/*
    Intuition:
    ------------
    We need to count all valid 3-digit even numbers that can be
    formed using the given digits.

    A valid 3-digit number must satisfy:
        1. The first digit cannot be 0.
        2. The last digit must be even.
        3. Each digit can only be used as many times as it appears
           in the input array.

    We use a frequency array to keep track of how many times each
    digit is available.

    We then choose:
        - `i` -> hundreds digit (1 to 9)
        - `j` -> tens digit (0 to 9)
        - `k` -> units digit (0, 2, 4, 6, 8)

    After choosing the first two digits, we check whether an
    available even digit can be used as the last digit.

    We temporarily decrease the frequency of selected digits so
    that repeated digits are handled correctly.

    Approach:
    ----------
    1. Store the frequency of every digit from 0 to 9.
    2. Choose the first digit from 1 to 9.
    3. Decrease its frequency.
    4. Choose the second digit from 0 to 9.
    5. Decrease its frequency.
    6. Check all possible even digits for the last position.
    7. If an even digit is available, count that number.
    8. Restore the frequencies before trying the next choice.

    Time Complexity:
    O(9 * 10 * 5) = O(1)

    Space Complexity:
    O(10) = O(1)
*/

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10,0);
        for(int i:digits) freq[i]++;
        int ans=0;

        for(int i=1;i<=9;i++)
        {
            if(freq[i]==0) continue;
            freq[i]--;
            for(int j=0;j<=9;j++)
            {
                if(freq[j]==0) continue;
                freq[j]--;
                for(int k=0;k<=8;k+=2)
                {
                    if(freq[k]>0) ans++;
                }
                freq[j]++;
            }
            freq[i]++;
        }
        return ans;
    }
};
