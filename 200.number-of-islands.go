/*
 * @lc app=leetcode id=200 lang=golang
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (43.04%)
 * Likes:    3359
 * Dislikes: 123
 * Total Accepted:    454.2K
 * Total Submissions: 1M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 *
 * Example 1:
 *
 *
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 *
 * Output: 3
 *
 */

// @lc code=start
func numIslands(grid [][]byte) int {
	l1 := len(grid)
	if l1 <= 0 {
		return 0
	}

	l2 := len(grid[0])
	res := 0

	for i := 0; i < l1; i++ {
		for j := 0; j < l2; j++ {
			if grid[i][j] == '1' {
				res++
			}
			eraseGrid(grid, l1, l2, i, j)
		}
	}

	return res
}

func eraseGrid(grid [][]byte, l1, l2, i, j int) {
	if i < 0 || i >= l1 || j < 0 || j >= l2 || grid[i][j] == '0' {
		return
	}
	grid[i][j] = '0'
	eraseGrid(grid, l1, l2, i-1, j)
	eraseGrid(grid, l1, l2, i+1, j)
	eraseGrid(grid, l1, l2, i, j-1)
	eraseGrid(grid, l1, l2, i, j+1)
}

// @lc code=end

