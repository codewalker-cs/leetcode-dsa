/*
    Problem: Next Greater Element I
    LeetCode: 496

    Intuition:
    ----------
    There are two approaches:

    1. Brute Force
       - For every element in nums2, search towards its right until a greater element is found.
       - Store this next greater element in a hashmap.
       - Then, for every element in nums1, simply fetch the answer from the hashmap.
       - Time Complexity: O(n²)

    2. Optimal (Monotonic Stack)
       - Maintain a decreasing stack.
       - Traverse nums2 from left to right.
       - Whenever the current element is greater than the stack top,
         it becomes the Next Greater Element for all smaller elements
         present at the top of the stack.
       - Store these mappings in a hashmap.
       - Elements left in the stack have no greater element, so map them to -1.
       - Finally, build the answer for nums1 using the hashmap.

    Time Complexity:
        Brute Force : O(n²)
        Optimal     : O(n)

    Space Complexity:
        Brute Force : O(n)
        Optimal     : O(n)
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // int n1=nums1.size(),n2=nums2.size();
        // vector<int> ans(n1,-1);
        // unordered_map<int,int> freq;
        // freq[nums2[n2-1]]=-1;

        // for(int i=n2-2;i>=0;i--)
        // {
        //     freq[nums2[i]]=-1;
        //     for(int j=i;j<n2;j++)
        //     {
        //         if(nums2[j]>nums2[i])
        //         {
        //             freq[nums2[i]]=nums2[j];
        //             break;
        //         }
        //     }
        // }

        // for(int i=0;i<n1;i++)
        // {
        //     for(int j=0;j<n2;j++)
        //     {
        //         if(nums1[i]==nums2[j])
        //         {
        //             ans[i]=freq[nums2[j]];
        //         }
        //     }
        // }

        // return ans;

        unordered_map<int,int> mp;
        stack<int> s;

        for(int &i : nums2)
        {
            while(!s.empty() && i>s.top())
            {
                mp[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }

        while(!s.empty())
        {
            mp[s.top()]=-1;
            s.pop();
        }

        vector<int> ans;
        for(int &i : nums1)
        {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};
