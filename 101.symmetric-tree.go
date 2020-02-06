/*
 * @lc app=leetcode id=101 lang=golang
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (44.53%)
 * Likes:    2860
 * Dislikes: 66
 * Total Accepted:    496.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 *
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 *
 *
 *
 *
 * But the following [1,2,2,null,3,null,3] is not:
 *
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 *
 *
 *
 *
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}

	queue := []*TreeNode{root}

	for {
		l := len(queue)
		if l <= 0 {
			break
		}

		i := 0
		j := l - 1
		for i <= j {
			if queue[i] == nil && queue[j] != nil ||
				queue[j] == nil && queue[i] != nil {
				return false
			}

			if queue[i] != nil && queue[j] != nil && queue[i].Val != queue[j].Val {
				return false
			}

			i++
			j--
		}

		var q []*TreeNode
		isAllNil := true
		for _, one := range queue {
			if one == nil {
				q = append(q, nil, nil)
			} else {
				q = append(q, one.Left, one.Right)
				if one.Left != nil || one.Right != nil {
					isAllNil = false
				}
			}
		}
		if isAllNil {
			queue = nil
		} else {
			queue = q
		}
	}

	return true
}

// @lc code=end

