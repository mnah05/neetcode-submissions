#include <vector>
#include <queue>
using namespace std;

class Solution {
   public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isSafe(int r, int c, int ROWS, int COLS) {
        return r >= 0 && r < ROWS && c >= 0 && c < COLS;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0;

        int minutes = 0;

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                auto curr = q.front();
                q.pop();

                int r = curr.first;
                int c = curr.second;

                for (auto& di : dir) {
                    int new_r = r + di[0];
                    int new_c = c + di[1];

                    if (isSafe(new_r, new_c, ROWS, COLS) && grid[new_r][new_c] == 1) {
                        grid[new_r][new_c] = 2;
                        q.push({new_r, new_c});
                        fresh--;
                    }
                }
            }

            if (!q.empty()) minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};