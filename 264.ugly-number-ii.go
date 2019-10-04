import "math"

/*
 * @lc app=leetcode id=264 lang=golang
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (37.59%)
 * Likes:    1120
 * Dislikes: 73
 * Total Accepted:    117.5K
 * Total Submissions: 312.2K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5.
 *
 * Example:
 *
 *
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 *
 * Note:
 *
 *
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 *
 */

// @lc code=start
func nthUglyNumber(n int) int {
	if n <= 0 {
		return 0
	}
	if n == 1 {
		return 1
	}

	t2, t3, t5 := 0, 0, 0

	k := make([]int, n)
	k[0] = 1

	for i := 1; i < n; i++ {
		k[i] = int(math.Min(float64(k[t2]*2), math.Min(float64(k[t3]*3), float64(k[t5]*5))))
		if k[i] == k[t2]*2 {
			t2++
		}
		if k[i] == k[t3]*3 {
			t3++
		}
		if k[i] == k[t5]*5 {
			t5++
		}
	}
	return k[n-1]
}

// @lc code=end

