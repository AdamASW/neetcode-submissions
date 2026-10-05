class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Data structures.
        queue<int> q;
        vector<int> answer;
        unordered_map<int,int> indegrees;
        unordered_map<int,vector<int>> reverseGraph;
        unordered_map<int,vector<int>> graph;
        vector<int> empty = {};

        // Build adjacency list to represent graph.
        // Build reverse graph to represent indegree counts.
        for (vector<int> req : prerequisites) {
            int t = req[0], s = req[1];
            reverseGraph[t].push_back(s);
            graph[s].push_back(t);
        }

        // Compute indegree mapping:
        for (int c = 0; c < numCourses; c++) {
            if (!reverseGraph.count(c)) { 
                q.push(c); // Source course.
                indegrees[c] = 0;
            } else {
                indegrees[c] = reverseGraph[c].size();
            }
        }

        // Perform multi-source bfs using nodes where indegree==0 as sopurces 
        // for topological sort to find ordering.
        while (!q.empty()) {
            int s = q.front();
            q.pop();
            answer.push_back(s);

            if (!graph.count(s)) { continue; }
            for (int t : graph[s]) {
                indegrees[t]--;
                if (indegrees[t] == 0) {
                    q.push(t);
                }
            }
        }
        return (answer.size() == numCourses) ? answer : empty;
    }
};
