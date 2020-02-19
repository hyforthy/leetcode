import "math"

/*
 * @lc app=leetcode id=329 lang=golang
 *
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (41.10%)
 * Likes:    1323
 * Dislikes: 22
 * Total Accepted:    110.1K
 * Total Submissions: 265.5K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 *
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 *
 * Example 1:
 *
 *
 * Input: nums =
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 *
 *
 * Example 2:
 *
 *
 * Input: nums =
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 *
 *
 */

// @lc code=start
func longestIncreasingPath(matrix [][]int) int {
	rowN := len(matrix)
	if rowN == 0 {
		return 0
	}
	columnN := len(matrix[0])
	if columnN == 0 {
		return 0
	}
	dp := make([][]int, rowN)
	for i := 0; i < rowN; i++ {
		dp[i] = make([]int, columnN)
	}

	m := 0
	for i := 0; i < rowN; i++ {
		for j := 0; j < columnN; j++ {
			x := longestIncreasingPathDFS(matrix, dp, rowN, columnN, i, j)
			m = int(math.Max(float64(m), float64(x)))
		}
	}
	return m
}

func longestIncreasingPathDFS(matrix [][]int, dp [][]int, rowN, columnN, r, c int) int {
	if dp[r][c] > 0 {
		return dp[r][c]
	}
	m := 1

	if c-1 >= 0 && matrix[r][c-1] > matrix[r][c] {
		m = int(math.Max(float64(m), float64(longestIncreasingPathDFS(matrix, dp, rowN, columnN, r, c-1)+1)))
	}
	if c+1 < columnN && matrix[r][c+1] > matrix[r][c] {
		m = int(math.Max(float64(m), float64(longestIncreasingPathDFS(matrix, dp, rowN, columnN, r, c+1)+1)))
	}
	if r-1 >= 0 && matrix[r-1][c] > matrix[r][c] {
		m = int(math.Max(float64(m), float64(longestIncreasingPathDFS(matrix, dp, rowN, columnN, r-1, c)+1)))
	}
	if r+1 < rowN && matrix[r+1][c] > matrix[r][c] {
		m = int(math.Max(float64(m), float64(longestIncreasingPathDFS(matrix, dp, rowN, columnN, r+1, c)+1)))
	}

	dp[r][c] = m
	return m
}

// @lc code=end
