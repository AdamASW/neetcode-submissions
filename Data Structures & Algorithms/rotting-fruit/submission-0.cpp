class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q = {};

        // Mark all originally rotten fruit as visited and add to queue.
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            int dirs[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

            for (auto [di, dj] : dirs) {
                int ni = i + di;
                int nj = j + dj;
                
                // Don't visit a neighboring cell if out of bounds, no fruit (=0), already visited (<0),
                // or is originally rotten itself (2).
                if (ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size() ||
                    grid[ni][nj] <= 0 || grid[ni][nj] == 2) {
                    continue;
                }
                // If current cell is a source, neighbor starts at -1, otherwise add the negatives.
                grid[ni][nj] = (grid[i][j] == 2) ? -1 : -1 + grid[i][j];
                q.push({ni, nj});
            }
        }

        int max_time = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // Skip final answer consideration if a source.
                if (grid[i][j] == 2) { continue; }
                // Return in infeasible if a fresh fruit is encountered.
                else if (grid[i][j] == 1) { return -1; }
                // Otherwise, update the max_time / longest path encountered 
                // (equivalent to the minimum time).
                else if (-1*grid[i][j] > max_time) max_time = -1*grid[i][j];
            }
        }
        return max_time;
    }
};
