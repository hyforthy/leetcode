/*
 * @lc app=leetcode id=10 lang=golang
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (25.74%)
 * Likes:    3126
 * Dislikes: 581
 * Total Accepted:    345.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 *
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 *
 *
 * The matching should cover the entire input string (not partial).
 *
 * Note:
 *
 *
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 *
 * Example 2:
 *
 *
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 *
 *
 * Example 3:
 *
 *
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 *
 *
 * Example 4:
 *
 *
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
 * it matches "aab".
 *
 *
 * Example 5:
 *
 *
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 *
 *
 */

// @lc code=start
// func isMatch(s string, p string) bool {
// 	m, n := len(s), len(p)
// 	cur := make([]bool, n+1)

// 	for i := 0; i <= m; i++ {
// 		pre := cur[0]
// 		cur[0] = i == 0
// 		for j := 1; j <= n; j++ {
// 			temp := cur[j]
// 			if p[j-1] == '*' {
// 				cur[j] = cur[j-2] || (i != 0 && cur[j] && (s[i-1] == p[j-2] || p[j-2] == '.'))
// 			} else {
// 				cur[j] = i != 0 && pre && (s[i-1] == p[j-1] || p[j-1] == '.')
// 			}
// 			pre = temp
// 		}
// 	}
// 	return cur[n]
// }

func isMatch(s string, p string) bool {
	m, n := len(s), len(p)
	dp := make([][]bool, m+1)
	for i := 0; i < m+1; i++ {
		dp[i] = make([]bool, n+1)
	}
	dp[0][0] = true

	for i := 0; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if p[j-1] == '*' {
				dp[i][j] = j != 1 && (dp[i][j-2] || (i != 0 && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.')))
			} else {
				dp[i][j] = i != 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')
			}
		}
	}
	return dp[m][n]
}

// @lc code=end

