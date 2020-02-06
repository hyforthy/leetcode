/*
 * @lc app=leetcode id=98 lang=golang
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (26.37%)
 * Likes:    2836
 * Dislikes: 413
 * Total Accepted:    543.5K
 * Total Submissions: 2M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 *
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 *
 * Input: [2,1,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 *
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
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
func isValidBST(root *TreeNode) bool {
	isBst, _, _, _ := isValidBST_(root)
	return isBst
}

func isValidBST_(root *TreeNode) (bool, bool, int, int) { // isBst, isNil, min, max
	if root == nil {
		return true, true, 0, 0
	}

	isLeftBst, isLeftNil, leftMin, leftMax := isValidBST_(root.Left)
	if !isLeftBst {
		return false, false, 0, 0
	}

	isRightBst, isRightNil, rightMin, rightMax := isValidBST_(root.Right)
	if !isRightBst {
		return false, false, 0, 0
	}

	if (!isLeftNil && leftMax >= root.Val) ||
		(!isRightNil && rightMin <= root.Val) {
		return false, false, 0, 0
	}

	min := root.Val
	if !isLeftNil {
		min = leftMin
	}
	max := root.Val
	if !isRightNil {
		max = rightMax
	}

	return true, false, min, max
}

// @lc code=end

