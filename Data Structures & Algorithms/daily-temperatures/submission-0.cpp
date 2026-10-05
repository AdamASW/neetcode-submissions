class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> days(temperatures.size());
        stack<int> s = {};
        s.push(0);
        for (int t = 1; t < temperatures.size(); t++) {
            if (temperatures[t] <= temperatures[t-1]) {
                s.push(t);
            } else {
                while (!s.empty() && temperatures[s.top()] < temperatures[t]) {
                    days[s.top()] = t - s.top();
                    s.pop();
                }
                s.push(t);
            }
        }
        return days;
    }
};