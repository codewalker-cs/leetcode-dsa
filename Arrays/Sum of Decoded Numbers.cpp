/*
    Intuition:
    Each number contains an encoded value where:
    - The last digit represents the split position.
    - The remaining digits contain two numbers, x and y.
    - The first `w` digits represent x.
    - The remaining digits represent y.

    We need to calculate x^y for every encoded number and return
    the sum modulo 1e9 + 7.

    Approach:
    1. Extract `w` using the last digit.
    2. Remove the last digit to get the encoded string.
    3. Split the string at position `w` to obtain x and y.
    4. Calculate x^y using binary exponentiation.
    5. Add the result to the answer modulo 1e9 + 7.

    Binary Exponentiation:
    Instead of multiplying x exactly y times, we repeatedly square
    x and divide y by 2.

    Time Complexity:
    O(n * log(y))

    Space Complexity:
    O(n) in the worst case due to string conversion.
*/

class Solution {
public:
    int mod=1e9+7;
    int sumDecoded(vector<long long>& nums) {
        int n=nums.size();
        long long ans=0;
        
        for(int i=0;i<n;i++)
        {
            long long w=nums[i]%10;
            long long d=nums[i]/10;

            string s=to_string(d);
            string xs=s.substr(0,w),ys=s.substr(w,s.size()-w);
            long long x=stoll(xs),y=stoll(ys);
            
            long long a1=1;
            while(y>0)
            {
                if(y&1)
                {
                    a1=a1*x%mod;
                }
                x=x*x%mod;
                y>>=1;
            }
            ans=(ans+a1)%mod;
        }
        return ans;
    }
};
