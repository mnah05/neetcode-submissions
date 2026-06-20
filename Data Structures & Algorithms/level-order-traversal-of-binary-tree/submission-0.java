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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            List<Integer> temp = new ArrayList<>();
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode tmp = q.poll();
                if(tmp != null) {
                    temp.add(tmp.val);
                    q.add(tmp.left);
                    q.add(tmp.right);
                }
            }
            if (temp.size() > 0){
                res.add(temp);
            }
        }
        return res;
    }
}
