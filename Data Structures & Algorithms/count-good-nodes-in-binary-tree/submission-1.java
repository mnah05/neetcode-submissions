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
    public static int dfs(TreeNode node, int maxi) {
        if (node == null) {
            return 0;
        }
        int res = (node.val >= maxi) ? 1 : 0;
        maxi = Math.max(maxi, node.val);
        res += dfs(node.left, maxi);
        res += dfs(node.right, maxi);
        return res;
    }
    public int goodNodes(TreeNode root) {
        return dfs(root, root.val);
    }
}
