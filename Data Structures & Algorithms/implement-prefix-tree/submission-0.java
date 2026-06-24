public class Node {
    Node[] w = new Node[26];
    boolean end = false;
}

class PrefixTree {
    public Node root;

    public PrefixTree() {
        root = new Node();
    }

    public void insert(String word) {
        Node curr = root;
        for (char c : word.toCharArray()) {
            int i = c - 'a';
            if (curr.w[i] == null) {
                curr.w[i] = new Node();
            }
            curr = curr.w[i];
        }
        curr.end = true;
    }

    public boolean search(String word) {
        Node curr = root;
        for (char c : word.toCharArray()) {
            int i = c - 'a';
            if (curr.w[i] == null) {
                return false;
            }
            curr = curr.w[i];
        }
        return curr.end;
    }

    public boolean startsWith(String prefix) {
        Node curr = root;
        for (char c : prefix.toCharArray()) {
            int i = c - 'a';
            if (curr.w[i] == null) {
                return false;
            }
            curr = curr.w[i];
        }
        return true;
    }
}