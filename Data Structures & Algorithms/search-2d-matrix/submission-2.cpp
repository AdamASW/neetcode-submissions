class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = matrix.size();
        int y = (matrix[0]).size();
        int x_mid; int y_mid;
        if (x == 1) { 
            if (y == 1) {
                if (matrix[0][0] == target) { return true; }
                else { return false; }
            } else if (y == 2) {
                if (matrix[0][0] == target) { return true; }
                else if (matrix[0][1] == target) { return true; }
                else { return false; }
            } else {
                y_mid = ceil(y/2.0);
                if (target < matrix[0][y_mid]) {
                    matrix[0].erase(matrix[0].begin() + y_mid, matrix[0].end());
                } else {
                    matrix[0].erase(matrix[0].begin(), matrix[0].begin() + y_mid);
                }
                return searchMatrix(matrix, target);
            }
        }
        // Binary search along the specific row.
        x_mid = ceil(x/2.0);
        if (target < matrix[x_mid][0]) {
            matrix.erase(matrix.begin() + x_mid, matrix.end());
        } else {
            matrix.erase(matrix.begin(), matrix.begin() + x_mid);
        }
        return searchMatrix(matrix, target);
    }
};
