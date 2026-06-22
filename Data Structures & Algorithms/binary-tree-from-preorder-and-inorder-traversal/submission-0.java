/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    int idx = 0;
    HashMap<Integer, Integer> mpp = new HashMap<>();
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        for (int i = 0; i < inorder.length; i++) {
            mpp.put(inorder[i], i);
        }

        return dfs(preorder, 0, inorder.length - 1);
    }
    public TreeNode dfs(int[] pre, int l, int r) {
        if (l > r)
            return null;
        int val = pre[idx++];
        TreeNode root = new TreeNode(val);
        int m = mpp.get(val);
        root.left = dfs(pre, l, m - 1);
        root.right = dfs(pre, m + 1, r);
        return root;
    }
}
