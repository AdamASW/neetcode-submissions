class Solution {
public:
    void reachableCells(vector<vector<int>>& heights, set<pair<int,int>>& oceanPairs,
        queue<pair<int,int>>& q) {
        // Reachable pacific cells:
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            int dirs[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

            for (auto [di, dj] : dirs) {
                int ni = i + di, nj = j + dj; 
                // Only visit an inbound, unvisited cell that is at-or-greater elevation.
                if (ni < 0 || ni >= heights.size() || nj < 0 || nj >= heights[0].size() || 
                    oceanPairs.count({ni, nj}) || heights[ni][nj] < heights[i][j]) { 
                        continue; 
                }
                oceanPairs.insert({ni,nj});
                q.push({ni,nj});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<pair<int,int>> pacificPairs;
        set<pair<int,int>> atlanticPairs;
        // Start from pacific edge cells:
        queue<pair<int,int>> q;
        queue<pair<int,int>> q2;
        // Add left and right edge cells to queue:
        int x = heights.size();
        int y = heights[0].size();
        for (int i = 0; i < x; i++) {
            pacificPairs.insert({i,0});
            q.push({i, 0});
            atlanticPairs.insert({i, y-1});
            q2.push({i, y-1});
        }
        // Add top and bottom edge cells to queue:
        for (int j = 0; j < y; j++) {
            pacificPairs.insert({0,j});
            q.push({0, j});
            atlanticPairs.insert({x-1,j});
            q2.push({x-1,j});
        }
        // Run atlantic and pacific mines:
        reachableCells(heights, pacificPairs, q);
        reachableCells(heights, atlanticPairs, q2);

        // Record final answer:
        vector<pair<int,int>> oceanPairs;
        vector<vector<int>> answer;
        set_intersection(pacificPairs.begin(), pacificPairs.end(),
            atlanticPairs.begin(), atlanticPairs.end(),
            back_inserter(oceanPairs));
        for (auto [i, j] : oceanPairs) {
            answer.push_back({i,j});
        }
        return answer;
    }
};
