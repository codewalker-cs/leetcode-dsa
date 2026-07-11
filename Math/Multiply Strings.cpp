/*
    Intuition:
    We cannot convert the given strings into integers because they may contain
    up to 200 digits. Instead, we simulate the multiplication exactly as we do
    on paper.

    Example:
        num1 = "123"
        num2 = "45"

              1 2 3
            x   4 5
            -------
                6 1 5
              4 9 2
            -------
              5 5 3 5

    We create a result array of size n + m.

    For every pair of digits:
        product = (num1[i]-'0') * (num2[j]-'0')

    If i and j are their indices:
        ones place  -> i + j + 1
        tens place  -> i + j

    We add the product to the current value, store the digit at i+j+1,
    and carry the remaining value to i+j.

    Finally, skip leading zeros and convert the result array into a string.

    Time Complexity: O(n * m)
    Space Complexity: O(n + m)
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";

        int n=num1.size(),m=num2.size();
        vector<int> res(n+m,0);

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int p=(num1[i]-'0')*(num2[j]-'0');
                int s=p+res[i+j+1];
                res[i+j+1]=s%10;
                res[i+j]+=s/10;
            }
        }
        string ans="";
        int i=0;
        while(i<res.size() && res[i]==0) i++;
        while(i<res.size())
        {
            ans+=res[i]+'0';
            i++;
        }
        return ans;
    }
};

// class Solution {
// public:
//     string multiply(string num1, string num2) {
//         long long n1=0,n2=0;

//         for(int i=0;i<num1.size();i++)
//         {
//             n1=(n1*10)+(num1[i]-'0');
//         }
        
//         for(int i=0;i<num2.size();i++)
//         {
//             n2=(n2*10)+(num2[i]-'0');
//         }

//         long long ans=n1*n2;
//         if(ans==0) return "0";
        
//         string an="";
//         while(ans)
//         {
//             int temp=ans%10;
//             ans=ans/10;
//             an=char(temp+'0')+an;
//         }

//         return an;
//     }
// };
