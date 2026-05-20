/*
Intuition:
For every index i, we need to find how many numbers are common
in prefixes:

A[0...i] and B[0...i]

We maintain two frequency arrays:
- a[x] -> whether x appeared in A's prefix
- b[x] -> whether x appeared in B's prefix

When processing:
1. Add A[i]
   - If it already existed in B's prefix,
     then it becomes a new common element.

2. Add B[i]
   - If it already existed in A's prefix,
     then it becomes a new common element.

Special Case:
If A[i] == B[i], both conditions count the same element twice,
so subtract one occurrence.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size(),c=0;
        vector<int> a(n+1,0),b(n+1,0),ans(n,0);
        
        a[A[0]]++;
        b[B[0]]++;
        if(A[0]==B[0])
        {
            c++;
        }
        ans[0]=c;

        for(int i=1;i<n;i++)
        {
            a[A[i]]++;
            b[B[i]]++;
            if(b[A[i]]==1)
            {
                c++;
            }
            if(a[B[i]]==1) c++;
            if(A[i]==B[i]) c--;
            ans[i]=c;
        }
        return ans;
    }
};
