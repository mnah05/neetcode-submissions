class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = grid[0][0];

        //fill first row
        for (int i = 1; i < m; i++) {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }


        //fill first col
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }


        for (int r = 1; r < n; r++) {
            for (int c = 1; c < m; c++) {
                //take min from up or right and fill the table
                dp[r][c] = grid[r][c] + min(dp[r - 1][c], dp[r][c - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};