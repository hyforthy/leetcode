/*
 * @lc app=leetcode id=32 lang=golang
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (26.42%)
 * Likes:    2359
 * Dislikes: 108
 * Total Accepted:    222K
 * Total Submissions: 837.2K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 *
 * Example 1:
 *
 *
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 *
 *
 * Example 2:
 *
 *
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 *
 *
 */

// @lc code=start
func longestValidParentheses(s string) int {
	res := 0
	l1 := len(s)

	dp := make([]int, l1+1)
	cnt := 0

	for i := 1; i <= l1; i++ {
		if s[i-1] == '(' {
			cnt++
			continue
		}
		if cnt > 0 {
			cnt--
			dp[i] = 2
			if s[i-2] == ')' {
				dp[i] += dp[i-1]
			}

			dp[i] += dp[i-dp[i]]
			if dp[i] > res {
				res = dp[i]
			}
		}
	}

	return res
}

// @lc code=end
