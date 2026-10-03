class Solution {
public:
    int sumGlobal = 0;

    void dfsSumAreaUpdate(vector<vector<int>>& grid, int i, int j) {
        if (!(i < grid.size()) || !(i >= 0) || !(j < grid[0].size()) || !(j >= 0)) { 
            return;
        } else {
            if (grid[i][j] == 1) {
                grid[i][j] = 0; // Ensures not double counted.
                sumGlobal++;
                dfsSumAreaUpdate(grid, i, j + 1);
                dfsSumAreaUpdate(grid, i, j - 1);
                dfsSumAreaUpdate(grid, i + 1, j);
                dfsSumAreaUpdate(grid, i - 1, j);
            } else {
                return;
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int x = grid.size();
        int y = grid[0].size();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (grid[i][j] == 1) {
                    sumGlobal = 0;
                    dfsSumAreaUpdate(grid, i, j);
                    if (sumGlobal > max_area) {max_area = sumGlobal; }
                    sumGlobal = 0;
                }
            }
        }
        return max_area;
    }
};
