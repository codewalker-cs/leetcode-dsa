/*
    Intuition:
    ----------
    An element x is "almost missing" if it appears in exactly one
    subarray of size k.

    Instead of checking every element against every subarray, we can
    count how many k-sized subarrays contain each distinct value.

    Important:
    If a value appears multiple times inside the same window, it still
    counts as appearing in only ONE subarray.

    So for every window of size k:
        1. Find the distinct elements present in that window.
        2. Increase their window-count by 1.

    Finally, among all values whose window-count is exactly 1,
    return the largest one.

    Example:
    nums = [1, 2, 3, 2, 4], k = 3

    Windows:
        [1, 2, 3] -> {1, 2, 3}
        [2, 3, 2] -> {2, 3}
        [3, 2, 4] -> {2, 3, 4}

    Window counts:
        1 -> 1
        2 -> 3
        3 -> 3
        4 -> 1

    Almost missing values = {1, 4}
    Answer = 4

    Time Complexity:
    ----------------
    O(n * k) in the worst case because we process each k-sized
    window and collect its distinct elements.

    Space Complexity:
    -----------------
    O(n) for storing the frequency of values across windows.
*/

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;

        for(int i=0;i+k<=n;i++)
        {
            unordered_set<int> s;
            for(int j=i;j<i+k;j++) s.insert(nums[j]);
            for(int l:s) freq[l]++;
        }

        int ans=-1;
        for(auto &[i,f]:freq)
        {
            if(f==1)
            {
                ans=max(ans,i);
            }
        }
        return ans;
    }
};
