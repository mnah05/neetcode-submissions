class Solution {
public:
    int ROWS, COLS;

    bool dfs(vector<vector<char>>& brd, string& w, int r, int c, int i) {
        if (i == w.size()) {
            return true;
        }

        if (r < 0 || r >= ROWS || c < 0 || c >= COLS ||
            brd[r][c] != w[i] || brd[r][c] == '#') {
            return false;
        }

        char temp = brd[r][c];
        brd[r][c] = '#';

        bool res =
            dfs(brd, w, r + 1, c, i + 1) ||
            dfs(brd, w, r - 1, c, i + 1) ||
            dfs(brd, w, r, c + 1, i + 1) ||
            dfs(brd, w, r, c - 1, i + 1);

        brd[r][c] = temp;

        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};