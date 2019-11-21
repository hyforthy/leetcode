/*
 * @lc app=leetcode id=95 lang=golang
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (37.12%)
 * Likes:    1590
 * Dislikes: 131
 * Total Accepted:    159.4K
 * Total Submissions: 424.7K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 *
 * Example:
 *
 *
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 *
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
func generateTrees(n int) []*TreeNode {
	if n <= 0 {
		return nil
	}
	uSlice := generateTrees_(1, n)

	res := make([]*TreeNode, len(uSlice))

	for i, tree := range uSlice {
		for _, digit := range tree {

			cur := &res[i]
			for *cur != nil {
				if digit < (*cur).Val {
					cur = &(*cur).Left
				} else {
					cur = &(*cur).Right
				}
			}

			*cur = &TreeNode{
				Val:   digit,
				Left:  nil,
				Right: nil,
			}
		}
	}

	return res
}

func generateTrees_(begin, end int) [][]int {
	var res [][]int
	if begin > end {
		return [][]int{nil}
	}

	for i := begin; i <= end; i++ {
		leftSlice := generateTrees_(begin, i-1)
		rightSlice := generateTrees_(i+1, end)
		for _, left := range leftSlice {
			for _, right := range rightSlice {
				t := make([]int, len(left)+len(right)+1)
				t[0] = i
				copy(t[1:len(left)+1], left)
				copy(t[len(left)+1:len(left)+len(right)+1], right)
				res = append(res, t)
			}
		}
	}

	return res
}

// @lc code=end

