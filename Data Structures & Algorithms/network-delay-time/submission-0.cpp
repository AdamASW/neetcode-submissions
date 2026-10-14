class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // BFS with Shortest Path.
        set<int> visited;
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        dist[0] = 0;
        dist[k] = 0;
        pq.push({0, k});
        visited.insert(k);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            for (vector<int> time : times) {
                int ui = time[0];
                int vi = time[1];
                int ti = time[2];
                if (ui != u) continue;
                visited.insert(vi);
                int newDist = dist[ui] + ti;
                if (newDist < dist[vi]) {
                    dist[vi] = newDist;
                    pq.push({newDist, vi});
                }
            }
        }

        if (visited.size() != n) return -1;
        int max_dist = 0;
        for (int d : dist) {
            max_dist = (d > max_dist) ? d : max_dist;
        }
        return max_dist;
    }
};
