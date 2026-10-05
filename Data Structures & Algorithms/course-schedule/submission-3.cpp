class Solution {
public:
    bool canFinishDfs(unordered_map<int,vector<int>>& graph, set<int>& path, int s) {
        path.insert(s);
        if (!graph.count(s)) { 
            path.erase(s);
            return true; 
        }
        for (int t : graph[s]) {
            if (path.count(t)) { return false; }
            if (!canFinishDfs(graph, path, t)) { return false; }
        }
        path.erase(s);
        graph.erase(s);
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Think of graphs as G = (V,E) (DAG).
        // Construct adjacency list.
        unordered_map<int,vector<int>> graph = {};
        for (vector<int> edge : prerequisites) {
            int s = edge[1], t = edge[0];
            graph[s].push_back(t);
        }
        // If infeasible, there will be a cycle, so we must check for cycles:
        for (int c = 0; c < numCourses; c++) {
            set<int> curr_path = {};
            if (!canFinishDfs(graph, curr_path, c)) return false;
        }
        return true;
    }
};