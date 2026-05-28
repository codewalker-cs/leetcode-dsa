// Intuition:
// We simulate the execution of functions using a stack.
//
// The stack always stores the currently active functions.
//
// Key idea:
// - When a new function starts,
//   the current function pauses.
//
// - When a function ends,
//   execution returns to the previous function.
//
// We use prevTime to track from where the current execution segment began.
//
// Important:
// End timestamps are INCLUSIVE.
// So for an "end" log:
// duration = endTime - prevTime + 1

class Solution {
public:
    vector<string> split(string &s, char delim)
    {
        vector<string> parts;
        string temp = "";
        for(char ch : s)
        {
            if(ch == delim)
            {
                parts.push_back(temp);
                temp = "";
            }
            else
            {
                temp += ch;
            }
        }
        parts.push_back(temp);
        return parts;
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;
        int prevTime = 0;

        for(string &log : logs)
        {
            vector<string> parts = split(log, ':');
            int id = stoi(parts[0]);
            string type = parts[1];
            int time = stoi(parts[2]);

            if(type == "start")
            {
                if(!st.empty())
                {
                    ans[st.top()] += time - prevTime;
                }
                st.push(id);
                prevTime = time;
            }
            else
            {
                ans[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }
        return ans;
    }
};
