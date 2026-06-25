class Trie {
    Trie[] w;
    boolean flag;

    public Trie() {
        this.w = new Trie[26];
        this.flag = false;
    }
}

class WordDictionary {
    public Trie root;

    public WordDictionary() {
        root = new Trie();
    }

    public void addWord(String word) {
        Trie curr = root;

        for (char c : word.toCharArray()) {
            if (curr.w[c - 'a'] == null) {
                curr.w[c - 'a'] = new Trie();
            }
            curr = curr.w[c - 'a'];
        }

        curr.flag = true;
    }

    public boolean search(String word) {
        return dfs(word, 0, root);
    }

    private boolean dfs(String word, int j, Trie root) {
        Trie cur = root;

        for (int i = j; i < word.length(); i++) {
            char c = word.charAt(i);

            if (c == '.') {
                for (Trie child : cur.w) {
                    if (child != null && dfs(word, i + 1, child)) {
                        return true;
                    }
                }
                return false;
            }

            if (cur.w[c - 'a'] == null) {
                return false;
            }

            cur = cur.w[c - 'a'];
        }

        return cur.flag;
    }
}