class Solution {
   public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int land = 0, shared = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    land++;
                    if (i > 0 && grid[i - 1][j] == 1) {
                        shared++;
                    }
                    if (j > 0 && grid[i][j - 1] == 1) {
                        shared++;
                    }
                }
            }
        }

        return 4 * land - 2 * shared;
    }
};