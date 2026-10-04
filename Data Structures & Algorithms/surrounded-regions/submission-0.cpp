class Solution {
public:
    void markExtOsDFS(vector<vector<char>>& board, int i, int j) {
        // Out of bounds.
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return;
        }
        // Visited or non-traversable.
        if (board[i][j] == '#' || board[i][j] == 'X') { 
            return; 
        }
        board[i][j] = '#'; // Mark visited.
        markExtOsDFS(board, i + 1, j);
        markExtOsDFS(board, i - 1, j);
        markExtOsDFS(board, i, j + 1);
        markExtOsDFS(board, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if ((i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1) &&
                    board[i][j] == 'O') {
                    // Mark all reachable Os from this border O.
                    markExtOsDFS(board, i, j);
                } 
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // Update board.
                if (board[i][j] == '#') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
