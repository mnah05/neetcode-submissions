class Solution {
public:
    void markRow(vector<vector<int>>& row, int n, int m, int i) {
        for (int j = 0; j < m; j++) {
            if (row[i][j] != 0) {
                row[i][j] = -99;
            }
        }
    }
    void markCol(vector<vector<int>>& col, int n, int m, int j) {
        for (int i = 0; i < n; i++) {
            if (col[i][j] != 0) {
                col[i][j] = -99;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    markRow(matrix, n, m, i);
                    markCol(matrix, n, m, j);
                }
            }
        }

        // Finally, mark all -99 as 0:
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == -99) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};