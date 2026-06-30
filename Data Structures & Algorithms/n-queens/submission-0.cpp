class Solution {
   public:
    vector<string> board;
    vector<bool> col, pos, neg;
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        col.resize(n, false);
        pos.resize(2 * n, false);
        neg.resize(2 * n, false);

        board.resize(n, string(n, '.'));

        dfs(0, n);
        return res;
    }
    void dfs(int r, int n) {
        if (r == n) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || pos[r + c] || neg[r - c + n]) {
                continue;
            }
            col[c] = true;
            pos[r + c] = true;
            neg[r - c + n] = true;
            board[r][c] = 'Q';
            dfs(r + 1, n);
            col[c] = false;
            pos[r + c] = false;
            neg[r - c + n] = false;
            board[r][c] = '.';
        }
    }
};
