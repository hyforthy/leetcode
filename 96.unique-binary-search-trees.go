/*
 * @lc app=leetcode id=96 lang=golang
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (47.93%)
 * Likes:    2256
 * Dislikes: 85
 * Total Accepted:    232.8K
 * Total Submissions: 479.6K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 *
 * Example:
 *
 *
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
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
// func numTrees(n int) int {
// 	nums := make([]int, n)
// 	for i := 0; i < n; i++ {
// 		nums[i] = i
// 	}

// 	return numTrees_(nums)
// }

// func numTrees_(nums []int) int {
// 	l1 := len(nums)
// 	if l1 <= 0 {
// 		return 1
// 	}

// 	res := 0

// 	for i := 0; i < l1; i++ {
// 		left := numTrees_(nums[0:i])
// 		right := numTrees_(nums[i+1 : l1])

// 		res += left * right
// 	}
// 	return res
// }

func numTrees(n int) int {
	if n == 0 {
		return 1
	}
	if n == 1 {
		return 1
	}

	if n == 2 {
		return 2
	}

	dp := make([]int, n+1)
	dp[0] = 1
	dp[1] = 1
	dp[2] = 2
	for i := 3; i <= n; i++ {
		for j := 0; j < i; j++ {
			dp[i] += dp[j] * dp[i-j-1]
		}
	}
	return dp[n]
}

// @lc code=end

