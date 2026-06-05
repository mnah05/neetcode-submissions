/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */


func invertTree(root *TreeNode) *TreeNode {
    if root == nil {
        return nil
    }

    someNode := root.Left
    root.Left = root.Right
    root.Right = someNode

    invertTree(root.Left)
    invertTree(root.Right)

    return root

}
