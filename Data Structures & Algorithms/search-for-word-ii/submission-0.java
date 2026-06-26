class Trie {
    String word;
    boolean eow;
    Trie[] ch;

    Trie() {
        word = "";
        eow = false;
        ch = new Trie[26];
    }

    public void addWord(String w) {
        Trie curr = this;

        for (char c : w.toCharArray()) {
            int i = c - 'a';
            if (curr.ch[i] == null) {
                curr.ch[i] = new Trie();
            }
            curr = curr.ch[i];
        }

        curr.eow = true;
        curr.word = w;
    }
}

class Solution {
    Set<String> res;
    boolean[][] visit;

    public List<String> findWords(char[][] board, String[] words) {
        Trie root = new Trie();

        for (String w : words) {
            root.addWord(w);
        }

        int ROWS = board.length;
        int COLS = board[0].length;

        res = new HashSet<>();
        visit = new boolean[ROWS][COLS];

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                dfs(board, r, c, root);
            }
        }

        return new ArrayList<>(res);
    }

    private void dfs(char[][] board, int r, int c, Trie node) {
        if (r < 0 || c < 0 || r >= board.length || c >= board[0].length)
            return;

        if (visit[r][c])
            return;

        char ch = board[r][c];
        Trie next = node.ch[ch - 'a'];

        if (next == null)
            return;

        if (next.eow) {
            res.add(next.word);
        }

        visit[r][c] = true;

        dfs(board, r + 1, c, next);
        dfs(board, r - 1, c, next);
        dfs(board, r, c + 1, next);
        dfs(board, r, c - 1, next);

        visit[r][c] = false;
    }
}