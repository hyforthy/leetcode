/*
 * @lc app=leetcode id=5 lang=golang
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.98%)
 * Likes:    4430
 * Dislikes: 402
 * Total Accepted:    669K
 * Total Submissions: 2.4M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 *
 * Example 1:
 *
 *
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: "cbbd"
 * Output: "bb"
 *
 *
 */

// @lc code=start
// func longestPalindrome(s string) string {
// 	l := len(s)
// 	if l > 1000 {
// 		l = 1000
// 	}
// 	for i := l; i > 0; i-- {
// 		for begin := 0; begin <= l-i; begin++ {
// 			cb := begin
// 			ce := begin + i - 1

// 			for cb < ce {
// 				if s[cb] != s[ce] {
// 					break
// 				}
// 				cb++
// 				ce--
// 			}
// 			if cb >= ce {
// 				return s[begin : begin+i]
// 			}
// 		}

// 	}
// 	return ""
// }

func longestPalindrome(s string) string {
	l := len(s)
	if l > 1000 {
		l = 1000
	}

	max := 0
	min := 0

	for i := 0; i < l; i++ {

		begin := i
		end := i

		for begin >= 0 && end < l && s[begin] == s[end] {
			begin--
			end++
		}

		if end-begin-1 > max-min {
			min = begin + 1
			max = end
		}

		begin = i
		end = i + 1

		for begin >= 0 && end < l && s[begin] == s[end] {
			begin--
			end++
		}

		if end-begin-1 > max-min {
			min = begin + 1
			max = end
		}

	}
	return s[min:max]

}

// @lc code=end

