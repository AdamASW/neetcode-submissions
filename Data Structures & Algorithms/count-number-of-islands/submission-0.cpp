class Solution {
public:

    void update_grid_dfs(vector<vector<char>>& grid, int i, int j, int i_dim, int j_dim) {
        if ((i >= 0) && (i < i_dim) && (j >= 0) && (j < j_dim)) {
            if (grid[i][j] == '1') {
                grid[i][j] = '0';
                // search:
                update_grid_dfs(grid, i-1, j, i_dim, j_dim);
                update_grid_dfs(grid, i, j-1, i_dim, j_dim);
                update_grid_dfs(grid, i+1, j, i_dim, j_dim);
                update_grid_dfs(grid, i, j+1, i_dim, j_dim);
            } else {
                grid[i][j] = '0';
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // Strategy: Once we land on a 1, eliminate all reachable 1s
        // using a search algorithm and make them a 0.
        int sum_islands = 0;
        int i_dim = grid.size();
        int j_dim = (grid[0]).size();
        for (int i = 0; i < i_dim; i++) {
            for (int j = 0; j < j_dim; j++) {
                if (grid[i][j] == '1') {
                    sum_islands += 1;
                    update_grid_dfs(grid, i, j, i_dim, j_dim);
                }
            }
        }
        return sum_islands;
    }
};
