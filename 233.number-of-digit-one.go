/*
 * @lc app=leetcode id=233 lang=golang
 *
 * [233] Number of Digit One
 *
 * https://leetcode.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (30.66%)
 * Likes:    199
 * Dislikes: 499
 * Total Accepted:    43.5K
 * Total Submissions: 141.8K
 * Testcase Example:  '13'
 *
 * Given an integer n, count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n.
 *
 * Example:
 *
 *
 * Input: 13
 * Output: 6
 * Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 *
 *
 */

// @lc code=start

// 对每个10进制位（个、拾...）计算。
// 小于等于n的整数中、1出现的总数，比如 n=11，则结果为3，因为含有1且小于等于11的数是1、11, 共3个1。
func countDigitOne(n int) int {
	result := 0
	for i := 1; i <= n; i = i * 10 {
		a := n / i
		b := n % i

		need := 0
		if a%10 == 1 { // 区分当前位是否为1
			need = b + 1
		}
		result += (a+8)/10*i + need // a+8 表示当前位小于2时，最后一个栅格要另外算（即need）
	}
	return result
}

// @lc code=end

