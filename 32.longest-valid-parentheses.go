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

	posNum := make([]int, l1)

	leftNum := 0
	nowNum := 0
	for i := 0; i < l1; i++ {
		if s[i] == '(' {
			leftNum++
			nowNum = 0
			continue
		}
		if s[i] == ')' {
			if leftNum > 0 {
				leftNum--
				if i-nowNum-2 >= 0 {
					nowNum = posNum[i-nowNum-2] + nowNum + 2
				} else {
					nowNum = nowNum + 2
				}

				posNum[i] = nowNum
				if nowNum > res {
					res = nowNum
				}
			} else {
				nowNum = 0
			}
		}
	}

	return res
}

// @lc code=end

