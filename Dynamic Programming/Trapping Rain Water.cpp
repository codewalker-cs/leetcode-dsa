/*
Intuition:

We need to calculate how much rain water can be trapped between bars.

For any index i:

    trapped water = min(max height on left,
                        max height on right)
                    - height[i]

A bar can only store water if there are taller bars on both sides.

---------------------------------------------------------------
Approach 1 : Prefix/Suffix Maximum Arrays
---------------------------------------------------------------

We precompute:

1) lmax[i]
   = tallest bar from 0 to i

2) rmax[i]
   = tallest bar from i to n-1

Then for every index:

    water at i = min(lmax[i], rmax[i]) - height[i]

Time Complexity  : O(n)
Space Complexity : O(n)

---------------------------------------------------------------
Approach 2 : Two Pointer Optimization
---------------------------------------------------------------

Observation:

Water level depends on the smaller boundary.

If lmax < rmax:
    left side becomes the limiting boundary,
    so water at left index can be calculated safely.

Else:
    right side becomes the limiting boundary.

This removes the need for extra arrays.

Time Complexity  : O(n)
Space Complexity : O(1)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        // int n=height.size();
        // vector<int> lmax(n,0),rmax(n,0);
        // lmax[0]=height[0];
        // rmax[n-1]=height[n-1];

        // for(int i=1;i<n;i++) lmax[i]=max(lmax[i-1],height[i]);
        // for(int i=n-2;i>=0;i--) rmax[i]=max(rmax[i+1],height[i]);

        // int ans=0;
        // for(int i=0;i<n;i++) ans+=(min(lmax[i],rmax[i])-height[i]);
        
        // return ans;

        int n=height.size();
        int l=0,r=n-1,lmax=0,rmax=0,ans=0;

        while(l<r)
        {
            lmax=max(lmax,height[l]);
            rmax=max(rmax,height[r]);

            if(lmax<rmax)
            {
                ans+=(lmax-height[l]);
                l++;
            }
            else
            {
                ans+=(rmax-height[r]);
                r--;
            }
        }

        return ans;
    }
};
