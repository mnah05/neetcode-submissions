class Solution {
   public:
    vector<vector<int>> dp;

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        dp.resize(m, vector<int>(n, -1));

        return dfs(0, 0, m, n, obstacleGrid);
    }

    int dfs(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid) {
        // Out of bounds OR blocked cell
        if (i >= m || j >= n || obstacleGrid[i][j] == 1) return 0;

        // Reached destination
        if (i == m - 1 && j == n - 1) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = dfs(i, j + 1, m, n, obstacleGrid) + dfs(i + 1, j, m, n, obstacleGrid);
    }
};