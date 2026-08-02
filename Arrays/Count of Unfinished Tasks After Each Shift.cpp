/*
    Intuition:
    We have a list of task durations that are completed sequentially.
    For each shift, work continues from where the previous shift ended.
    If the current shift has enough time to finish all remaining tasks,
    the process resets and the next shift starts from the beginning.

    Instead of simulating every task for every shift, we precompute
    prefix sums of task durations.

    The variable 'offset' stores the total time already spent on the
    current round of tasks.

    For each shift:
    1. Compute the remaining time needed to finish all tasks.
    2. If the shift can finish everything:
        - Answer is 0.
        - Reset offset to 0.
    3. Otherwise:
        - Increase offset by the current shift duration.
        - Use upper_bound on the prefix sums to find the first task
          that has not been completed.
        - Remaining tasks = total tasks - completed tasks.

    Example:
    tasks  = [2, 3, 4]
    shifts = [3, 2, 5]

    Prefix Sum:
    [2, 5, 9]

    Shift 1:
    offset = 0
    work = 3
    upper_bound(3) -> index = 1
    Remaining = 3 - 1 = 2

    Shift 2:
    offset = 3 + 2 = 5
    upper_bound(5) -> index = 2
    Remaining = 3 - 2 = 1

    Shift 3:
    Remaining time = 9 - 5 = 4
    work = 5 >= 4
    All tasks completed.
    Answer = 0
    Reset offset = 0

    Time Complexity:
    O(m + n log m)

    m = number of tasks
    n = number of shifts

    Space Complexity:
    O(m)

    Prefix sum array stores cumulative task durations.
*/

class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=shifts.size(),m=tasks.size();
        vector<int> ans;
        vector<long long> pre(m,0);
        pre[0]=tasks[0];

        for(int i=1;i<m;i++)
        {
            pre[i]=pre[i-1]+tasks[i];
        }

        long long ttime=pre[m-1],offset=0;

        for(int i=0;i<n;i++)
        {
            long long remtime=ttime-offset;

            if(shifts[i]>=remtime)
            {
                ans.push_back(0);
                offset=0;
            }
            else
            {
                offset+=shifts[i];
                int idx=upper_bound(pre.begin(),pre.end(),offset)-pre.begin();
                ans.push_back(m-idx);
            }
        }
        return ans;
    }
};
