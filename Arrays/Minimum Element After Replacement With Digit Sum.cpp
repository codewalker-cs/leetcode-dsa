/*
Intuition:
For each number in the array, compute the sum of its digits and keep
track of the minimum digit sum encountered.

Instead of converting numbers to strings, we extract digits using
modulo (%) and division (/). This avoids extra memory usage and is
more efficient in practice.

Algorithm:
1. Initialize answer as INT_MAX.
2. For every number in nums:
   - Repeatedly extract the last digit using x % 10.
   - Add it to the current digit sum.
   - Remove the last digit using x /= 10.
3. Update the minimum digit sum.
4. Return the minimum digit sum found.

Time Complexity: O(n * d)
    where d is the maximum number of digits in any number.

Space Complexity: O(1)
*/

// class Solution {
// public:
//     int minElement(vector<int>& nums) {
//         int n=nums.size(),mi=INT_MAX;
//         for(int &c : nums)
//         {
//             string s=to_string(c);
//             int sum=0;

//             for(char &t : s)
//             {
//                 sum+=(t-'0');
//             }
//             mi=min(mi,sum);
//         }
//         return mi;
//     }
// };

class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;

        for(int x : nums)
        {
            int sum=0;

            while(x>0)
            {
                sum+=x%10;
                x/=10;
            }
            ans=min(ans,sum);
        }

        return ans;
    }
};
