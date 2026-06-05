func helper(p, q *TreeNode) bool {
    if p == nil || q == nil {
        return p == q  
    }
    
    if p.Val != q.Val {
        return false
    }

    return helper(p.Left, q.Left) && helper(p.Right, q.Right)
}

func isSameTree(p *TreeNode, q *TreeNode) bool {
    if p == nil && q == nil {
        return true
    }
    return helper(p,q)
}
