class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,set<int>> rows;
        unordered_map<int,set<int>> cols;
        unordered_map<int,set<int>> boxes;
        int n;
        int box;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                n = board[i][j];
                box = 9*(i/3) + (j/3);
                if (rows[i].count(n) || cols[j].count(n) || boxes[box].count(n)) {
                    return false;
                }
                // Row insert:
                rows[i].insert(n);
                // Col insert:
                cols[j].insert(n);
                // Box insert:
                boxes[box].insert(n);
            }
        }
        return true;
    }
};
