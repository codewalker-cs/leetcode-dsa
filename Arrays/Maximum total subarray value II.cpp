/*
Intuition:
- For every starting index l, consider the longest subarray [l, n - 1].
- The value of a subarray is:
      max(subarray) - min(subarray)

- We need to repeatedly pick the subarray with the largest value.
- To answer max/min queries on any range efficiently, build two Sparse Tables:
      1. Range Maximum Query (RMQ-Max)
      2. Range Minimum Query (RMQ-Min)

- For each starting index l:
      Push the subarray [l, n - 1] into a max-heap.

- Each heap node stores:
      (value, left, right)

- When the current best subarray [l, r] is chosen:
      1. Add its value to the answer.
      2. Remove it from consideration.
      3. Insert its next candidate [l, r - 1].

- Repeat exactly k times.

Time Complexity:
- Sparse Table Construction:
      O(n log n)

- Each heap operation:
      O(log n)

- Performed k times:
      O(k log n)

Overall:
      O(n log n + k log n)

Space Complexity:
      O(n log n)
*/

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        int logn = 32 - __builtin_clz(n);

        vector<vector<int>> stMax(n, vector<int>(logn));
        vector<vector<int>> stMin(n, vector<int>(logn));

        for (int i = 0; i < n; i++) {
            stMax[i][0] = nums[i];
            stMin[i][0] = nums[i];
        }

        for (int j = 1; j < logn; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                stMax[i][j] =
                    max(stMax[i][j - 1],
                        stMax[i + (1 << (j - 1))][j - 1]);

                stMin[i][j] =
                    min(stMin[i][j - 1],
                        stMin[i + (1 << (j - 1))][j - 1]);
            }
        }

        auto queryMax = [&](int l, int r) -> int {
            int j = 31 - __builtin_clz(r - l + 1);

            return max(
                stMax[l][j],
                stMax[r - (1 << j) + 1][j]
            );
        };

        auto queryMin = [&](int l, int r) -> int {
            int j = 31 - __builtin_clz(r - l + 1);

            return min(
                stMin[l][j],
                stMin[r - (1 << j) + 1][j]
            );
        };

        priority_queue<tuple<int, int, int>> pq;

        for (int l = 0; l < n; l++) {
            int value =
                queryMax(l, n - 1) -
                queryMin(l, n - 1);

            pq.emplace(value, l, n - 1);
        }

        long long answer = 0;

        while (k--) {
            auto [value, l, r] = pq.top();
            pq.pop();

            answer += value;

            if (r > l) {
                int nextValue =
                    queryMax(l, r - 1) -
                    queryMin(l, r - 1);

                pq.emplace(nextValue, l, r - 1);
            }
        }

        return answer;
    }
};
