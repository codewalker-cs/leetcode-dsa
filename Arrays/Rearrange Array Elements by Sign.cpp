/*
========================================================
2149. Rearrange Array Elements by Sign
========================================================

Intuition 1: Two Pointer Traversal (My Approach)
------------------------------------------------
We need to rearrange the array such that:
1. Positive and negative numbers appear alternately.
2. The relative order of positives remains the same.
3. The relative order of negatives remains the same.

Instead of separating the array first, we maintain:
- l -> points to the next positive number.
- r -> points to the next negative number.

Initially:
- Move l until it reaches the first positive.
- Move r until it reaches the first negative.

Then,
- Add nums[l] followed by nums[r] to the answer.
- Move both pointers forward.
- Skip unwanted elements until the next valid positive/negative is found.

Since every element is visited at most once by its respective pointer,
the overall complexity remains linear.

Example
-------
nums = [3,1,-2,-5,2,-4]

l -> 3
r -> -2

Answer:
3,-2
1,-5
2,-4

Final Answer:
[3,-2,1,-5,2,-4]

Time Complexity : O(n)
Space Complexity: O(n)

--------------------------------------------------------
Intuition 2: Even-Odd Index Placement (Optimal Approach)
--------------------------------------------------------
Observe that the answer always starts with a positive number.

Therefore,
- Positive numbers must occupy indices:
  0,2,4,...

- Negative numbers must occupy indices:
  1,3,5,...

Maintain two indices:
pos = 0
neg = 1

Traverse the original array once.

If current number is positive:
    place it at ans[pos]
    pos += 2

Else:
    place it at ans[neg]
    neg += 2

Because we process the array from left to right,
the relative order of positives and negatives is preserved automatically.

Example
-------
nums = [3,1,-2,-5,2,-4]

Initially

ans = [_,_,_,_,_,_]

3  -> ans[0]
1  -> ans[2]
-2 -> ans[1]
-5 -> ans[3]
2  -> ans[4]
-4 -> ans[5]

Result

[3,-2,1,-5,2,-4]

Time Complexity : O(n)
Space Complexity: O(n)

========================================================
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // int n=nums.size(),l=0,r=0;
        // while(l<n && nums[l]<0) l++;
        // while(r<n && nums[r]>=0) r++;

        // vector<int> ans;
        // while(l<n && r<n)
        // {
        //     ans.push_back(nums[l]);
        //     ans.push_back(nums[r]);
        //     l++;
        //     r++;
        //     while(l<n && nums[l]<0) l++;
        //     while(r<n && nums[r]>=0) r++;
        // }
        // if(l<n)
        // {
        //     ans.push_back(nums[l]);
        // }
        // else if(r<n)
        // {
        //     ans.push_back(nums[r]);
        // }

        // return ans;

        int n=nums.size();
        int i=0,j=1;
        vector<int> ans(n,0);
        
        for(int &u : nums)
        {
            if(u>=0)
            {
                ans[i]=u;
                i+=2;
            }
            else
            {
                ans[j]=u;
                j+=2;
            }
        }
        return ans;
    }
};
