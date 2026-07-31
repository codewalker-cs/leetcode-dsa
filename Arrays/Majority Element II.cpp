/*
    --------------------------------------------------------------------
    Problem: Majority Element II (LeetCode 229)
    Algorithm: Boyer-Moore Voting Algorithm
    --------------------------------------------------------------------

    Intuition:
    ----------
    A number appearing more than n/3 times can only have at most two
    candidates.

    Why?
    - Suppose there were three different numbers occurring more than n/3
      times each.
    - Their total occurrences would exceed n, which is impossible.

    Therefore, we only need to track two potential majority elements.

    Algorithm:
    ----------
    1. First Pass (Find Potential Candidates)
       - Maintain two candidates and their counts.
       - If the current number matches a candidate, increment its count.
       - If a count becomes zero, replace that candidate.
       - Otherwise, decrement both counts.

    2. Second Pass (Verification)
       - Count the actual occurrences of both candidates.
       - Return the candidates whose frequency is greater than n/3.

    --------------------------------------------------------------------
    Example:
    --------------------------------------------------------------------
    nums = [2, 2, 1, 3, 2, 1, 1, 1]

    First Pass:

    num = 2
    cand1 = 2, cnt1 = 1

    num = 2
    cand1 = 2, cnt1 = 2

    num = 1
    cand2 = 1, cnt2 = 1

    num = 3
    Different from both candidates.
    cnt1--, cnt2--

    cand1 = 2, cnt1 = 1
    cand2 = 1, cnt2 = 0

    num = 2
    cnt1++

    cand1 = 2, cnt1 = 2

    num = 1
    cnt2 == 0
    cand2 = 1, cnt2 = 1

    num = 1
    cnt2++

    num = 1
    cnt2++

    Potential candidates:
    cand1 = 2
    cand2 = 1

    Verification:
    2 occurs 3 times.
    1 occurs 4 times.

    Since n = 8,
    n/3 = 2

    Both occur more than 2 times.

    Answer = [2, 1]

    --------------------------------------------------------------------
    Time Complexity:
    O(n)
    - One pass to find candidates.
    - One pass to verify them.

    Space Complexity:
    O(1)
    - Only constant extra variables are used.
    --------------------------------------------------------------------
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums;
        vector<int> ans;
        int count1=0,count2=0,maj1=-1,maj2=-1,n=nums.size();

        for(int i:nums)
        {
            if(i==maj1)
            {
                count1++;
            }
            else if(i==maj2)
            {
                count2++;
            }
            else if(count1==0)
            {
                maj1=i;
                count1++;
            }
            else if(count2==0)
            {
                maj2=i;
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;

        for(int i:nums)
        {
            if(i==maj1)
            {
                count1++;
            }
            else if(i==maj2)
            {
                count2++;
            }
        }

        if(count1>(n/3))
        {
            ans.push_back(maj1);
        }
        if(count2>(n/3))
        {
            ans.push_back(maj2);
        }

        return ans;
    }
};
