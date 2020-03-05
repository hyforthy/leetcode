import "math"

/*
 * @lc app=leetcode id=687 lang=golang
 *
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (34.55%)
 * Likes:    1159
 * Dislikes: 302
 * Total Accepted:    69.8K
 * Total Submissions: 201.6K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given a binary tree, find the length of the longest path where each node in
 * the path has the same value. This path may or may not pass through the
 * root.
 *
 * The length of path between two nodes is represented by the number of edges
 * between them.
 *
 *
 *
 * Example 1:
 *
 * Input:
 *
 *
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 *
 *
 * Output: 2
 *
 *
 *
 * Example 2:
 *
 * Input:
 *
 *
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 *
 *
 * Output: 2
 *
 *
 *
 * Note: The given binary tree has not more than 10000 nodes. The height of the
 * tree is not more than 1000.
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func longestUnivaluePath(root *TreeNode) int {
	res := 0
	longestUnivaluePath_(root, &res)
	return res
}

func longestUnivaluePath_(root *TreeNode, maxLen *int) int {
	if root == nil {
		return 0
	}
	// 可以认为是节点数
	left := longestUnivaluePath_(root.Left, maxLen)
	right := longestUnivaluePath_(root.Right, maxLen)
	if root.Left == nil || root.Left.Val != root.Val {
		left = 0
	}
	if root.Right == nil || root.Right.Val != root.Val {
		right = 0
	}

	*maxLen = int(math.Max(float64(*maxLen), float64(left+right)))
	return int(math.Max(float64(left), float64(right))) + 1
}

// @lc code=end
