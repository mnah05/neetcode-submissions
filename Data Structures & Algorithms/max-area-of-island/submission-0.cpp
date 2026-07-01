class Solution {
   public:
    int dfs(vector<vector<int>>& g, int r, int c) {
        if (r < 0 || c < 0 || r >= g.size() || c >= g[0].size() || g[r][c] == 0) {
            return 0;
        }

        g[r][c] = 0;
        int res = 1;

        res += dfs(g, r + 1, c);
        res += dfs(g, r - 1, c);
        res += dfs(g, r, c + 1);
        res += dfs(g, r, c - 1);

        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int area = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    area = max(area, dfs(grid, i, j));
                }
            }
        }
        return area;
    }
};