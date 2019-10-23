/*
 * @lc app=leetcode id=30 lang=golang
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (24.18%)
 * Likes:    640
 * Dislikes: 1026
 * Total Accepted:    149K
 * Total Submissions: 614.3K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 *
 *
 *
 * Example 1:
 *
 *
 * Input:
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 *
 *
 * Example 2:
 *
 *
 * Input:
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * Output: []
 *
 *
 */

// @lc code=start
func findSubstring(s string, words []string) []int {
	l1 := len(s)
	l2 := len(words)

	if l2 <= 0 {
		return nil
	}

	n1 := len(words[0])

	var res []int

	statistics := make(map[string]int)

	for _, v := range words {
		statistics[v]++
	}

	for i := 0; i <= l1-n1*l2; i++ {
		begin := i
		end := n1*l2 + i
		seen := make(map[string]int)

		for begin < end {
			if _, ok := statistics[s[begin:begin+n1]]; !ok {
				break
			}
			seen[s[begin:begin+n1]]++
			if seen[s[begin:begin+n1]] > statistics[s[begin:begin+n1]] {
				break
			}
			begin += n1
		}

		if begin >= end {
			res = append(res, i)
		}
	}
	return res
}

// @lc code=end

