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
    int maxi = Integer.MIN_VALUE;

    public int solve(TreeNode r) {
        if (r == null)
            return 0;

        int lSum = Math.max(0, solve(r.left));
        int rSum = Math.max(0, solve(r.right));

        maxi = Math.max(maxi, lSum + rSum + r.val);

        return r.val + Math.max(lSum, rSum);
    }

    public int maxPathSum(TreeNode root) {
        solve(root);
        return maxi;
    }
}
