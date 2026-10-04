class Solution {
public:
    // Data structure to store [i][j] --> current shorted chest distance.
    // struct PairHash {
    //     size_t operator()(const pair<int,int>& p) const {
    //         return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    //     }
    // };

    // unordered_map<pair<int,int>, int, PairHash> chestMap = {};

    // set<pair<int,int>> currVisited = {};

    // // Use DFS to update chest distance on land cells.
    // void chestUpdateDFS(vector<vector<int>>& grid, int i, int j, int steps) {
    //     // Base cases to ignore out of bounds or non-traversable cells.
    //     if ((i < 0) || (i >= grid.size()) || (j < 0) || (j >= grid[0].size())) {
    //         return;
    //     }
    //     if (grid[i][j] == -1) { return; }
    //     // If we've visited this node before and the path from origin chest isn't any better, ignore.
    //     if (currVisited.count({i,j}) && chestMap.count({i,j}) && (steps >= chestMap[{i,j}])) {
    //         return;
    //     }
    //     // Ignore the update if chest.
    //     if (grid[i][j] > 0) { 
    //         // Check if in chestMap, check if current step < stored value, update as needed:
    //         if (chestMap.count({i, j})) {
    //             chestMap[{i, j}] = (steps < chestMap[{i, j}]) ? steps : chestMap[{i, j}];
    //         } else {
    //             chestMap[{i, j}] = steps;
    //         }
    //         grid[i][j] = chestMap[{i,j}];
    //     } else {
    //         chestMap[{i,j}] = 0;
    //     }
    //     currVisited.insert({i,j});
    //     chestUpdateDFS(grid, i, j+1, steps+1);
    //     chestUpdateDFS(grid, i, j-1, steps+1);
    //     chestUpdateDFS(grid, i+1, j, steps+1);
    //     chestUpdateDFS(grid, i-1, j, steps+1);
    // }

    // void islandsAndTreasure(vector<vector<int>>& grid) {
    //     for (int i = 0; i < grid.size(); i++) {
    //         for (int j = 0; j < grid[0].size(); j++) {
    //             if (grid[i][j] == 0) {
    //                 // Call DFS to update treasure chest distance.
    //                 chestUpdateDFS(grid, i, j, 0);
    //                 currVisited = {};
    //             }
    //         }
    //     }
    // }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (auto& [di, dj] : dirs) {
                int ni = i + di;
                int nj = j + dj;

                if (ni < 0 || ni >= grid.size() ||
                    nj < 0 || nj >= grid[0].size() ||
                    grid[ni][nj] != 2147483647) {
                    continue;
                }

                grid[ni][nj] = grid[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }
};
