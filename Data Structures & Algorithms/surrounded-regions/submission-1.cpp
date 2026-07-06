class Solution {
public:
    //[1] visited each component from boundary
    // mark them true in vis
    //[2] once that is done any other component which is not marked in vis
    // will get converted to X
    int n, m;
    vector<vector<bool>> vis;
    void dfs(int i, int j, vector<vector<char>>& b) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return;
        }
        if (vis[i][j] || b[i][j] == 'X') {
            return;
        }
        vis[i][j] = true;
        dfs(i - 1, j, b);
        dfs(i + 1, j, b);
        dfs(i, j + 1, b);
        dfs(i, j - 1, b);
    }
    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        n = board.size();
        m = board[0].size();
        vis.assign(n, vector<bool>(m, false));
        // top row
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                dfs(0, j, board);
            }
        }
        // bottom row
        if (n > 1) {
            for (int j = m - 2; j >= 0; j--) {
                if (board[n - 1][j] == 'O') {
                    dfs(n - 1, j, board);
                }
            }
        }
        // left col
        if (m > 1) {
            for (int i = n - 2; i >= 1; i--) {
                if (board[i][0] == 'O') {
                    dfs(i, 0, board);
                }
            }
        }
        // right col
        for (int i = 1; i < n; i++) {
            if (board[i][m - 1] == 'O') {
                dfs(i, m - 1, board);
            }
        }
        // changing non border O's to X
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};