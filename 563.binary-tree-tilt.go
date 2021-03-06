import "math"

/*
 * @lc app=leetcode id=563 lang=golang
 *
 * [563] Binary Tree Tilt
 *
 * https://leetcode.com/problems/binary-tree-tilt/description/
 *
 * algorithms
 * Easy (47.27%)
 * Likes:    372
 * Dislikes: 888
 * Total Accepted:    61.3K
 * Total Submissions: 129.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a binary tree, return the tilt of the whole tree.
 *
 * The tilt of a tree node is defined as the absolute difference between the
 * sum of all left subtree node values and the sum of all right subtree node
 * values. Null node has tilt 0.
 *
 * The tilt of the whole tree is defined as the sum of all nodes' tilt.
 *
 * Example:
 *
 * Input:
 * ⁠        1
 * ⁠      /   \
 * ⁠     2     3
 * Output: 1
 * Explanation:
 * Tilt of node 2 : 0
 * Tilt of node 3 : 0
 * Tilt of node 1 : |2-3| = 1
 * Tilt of binary tree : 0 + 0 + 1 = 1
 *
 *
 *
 * Note:
 *
 * The sum of node values in any subtree won't exceed the range of 32-bit
 * integer.
 * All the tilt values won't exceed the range of 32-bit integer.
 *
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
func findTilt(root *TreeNode) int {
	_, tilt := findTilt_(root)

	return tilt
}

func findTilt_(root *TreeNode) (int, int) {
	if root == nil {
		return 0, 0
	}

	lSum, lTilt := findTilt_(root.Left)
	rSum, rTilt := findTilt_(root.Right)

	return lSum + rSum + root.Val, lTilt + rTilt + int(math.Abs(float64(lSum-rSum)))
}

// @lc code=end
