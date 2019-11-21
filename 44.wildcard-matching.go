/*
 * @lc app=leetcode id=44 lang=golang
 *
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (23.44%)
 * Likes:    1420
 * Dislikes: 82
 * Total Accepted:    205.6K
 * Total Submissions: 869.1K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*'.
 *
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 *
 * The matching should cover the entire input string (not partial).
 *
 * Note:
 *
 *
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like ? or *.
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
 * p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 *
 *
 * Example 3:
 *
 *
 * Input:
 * s = "cb"
 * p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not
 * match 'b'.
 *
 *
 * Example 4:
 *
 *
 * Input:
 * s = "adceb"
 * p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*'
 * matches the substring "dce".
 *
 *
 * Example 5:
 *
 *
 * Input:
 * s = "acdcb"
 * p = "a*c?b"
 * Output: false
 *
 *
 */

// @lc code=start
// func isMatch(s string, p string) bool {
// 	l1 := len(s)
// 	l2 := len(p)

// 	dp := make([][]bool, l1+1)
// 	for k, _ := range dp {
// 		dp[k] = make([]bool, l2+1)
// 	}

// 	dp[0][0] = true

// 	for i := 0; i <= l1; i++ {
// 		for j := 0; j <= l2; j++ {
// 			if j == 0 {
// 				continue
// 			}

// 			if p[j-1] == '*' {
// 				dp[i][j] = (j != 0 && dp[i][j-1]) || (i != 0 && dp[i-1][j])
// 			} else {
// 				dp[i][j] = i != 0 && j != 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?')
// 			}
// 		}
// 	}

// 	return dp[l1][l2]
// }

func isMatch(s, p string) bool {
	i, j, star, si := 0, 0, -1, 0
	l1, l2 := len(s), len(p)

	for i < l1 {
		if j >= l2 {
			if star >= 0 {
				si++
				i = si
				j = star + 1
				continue
			}
			return false
		}

		if p[j] == '?' || s[i] == p[j] {
			i++
			j++
		} else if p[j] == '*' {
			star = j
			j++
			si = i
		} else if star >= 0 {
			si++
			i = si
			j = star + 1
		} else {
			return false
		}
	}

	for j < l2 {
		if p[j] != '*' {
			return false
		}
		j++
	}
	return true
}

// @lc code=end

