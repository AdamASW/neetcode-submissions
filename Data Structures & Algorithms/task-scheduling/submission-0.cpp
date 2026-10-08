class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> remaining_tasks;
        priority_queue<pair<int,char>, vector<pair<int,char>>> pq;
        queue<char> q;
        char task;
        for (int i = 0; i <= n; i++) { q.push('#'); }
        for (char c : tasks) {
            remaining_tasks[c]++;
        }
        for (auto& [letter, count] : remaining_tasks) {
            pq.push({count,letter});
        }
        int time = 0;
        while(!remaining_tasks.empty()) {
            time++;
            if (pq.empty()) { 
                q.push('#');
            } else {
                task = pq.top().second;
                pq.pop();
                remaining_tasks[task]--;
                if (remaining_tasks[task] > 0) { q.push(task); }
                else { (remaining_tasks.erase(task)); q.push('#'); }
            }
            q.pop();
            if (!(q.front() == '#')) { 
                pq.push({remaining_tasks[q.front()], q.front()});
            }
        }
        return time;
    }
};