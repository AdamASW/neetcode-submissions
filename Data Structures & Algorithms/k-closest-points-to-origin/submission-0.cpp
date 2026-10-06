class Solution {
public:

    void heapUpdate(int k, priority_queue<pair<float,int>,vector<pair<float,int>>>& pq, pair<float,int> v) {
        // Of element {d, i}, top will be the largest of the current k elements. Pop only when new distance smaller.
        if (pq.size() >= k) {
            if (v.first < pq.top().first) {
                pq.pop();
                pq.push(v);
            }
        } else {
            pq.push(v);
        }
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,int>, vector<pair<float,int>>> pq = {};
        int x, y;
        float euclid;
        int i = 0;
        for (vector<int> point : points) {
            x = point[0], y = point[1];
            euclid = sqrt(pow(x,2) + pow(y,2));
            heapUpdate(k, pq, {euclid, i});
            i++;
        }
        vector<vector<int>> answer = {};
        while (!pq.empty()) {
            auto [d, idx] = pq.top();
            pq.pop();
            answer.push_back(points[idx]);
        }
        return answer;
    }
};
