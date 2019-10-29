/*
 * @lc app=leetcode id=336 lang=golang
 *
 * [336] Palindrome Pairs
 *
 * https://leetcode.com/problems/palindrome-pairs/description/
 *
 * algorithms
 * Hard (31.93%)
 * Likes:    969
 * Dislikes: 130
 * Total Accepted:    82.1K
 * Total Submissions: 255.7K
 * Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
 *
 * Given a list of unique words, find all pairs of distinct indices (i, j) in
 * the given list, so that the concatenation of the two words, i.e. words[i] +
 * words[j] is a palindrome.
 *
 * Example 1:
 *
 *
 *
 * Input: ["abcd","dcba","lls","s","sssll"]
 * Output: [[0,1],[1,0],[3,2],[2,4]]
 * Explanation: The palindromes are
 * ["dcbaabcd","abcddcba","slls","llssssll"]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: ["bat","tab","cat"]
 * Output: [[0,1],[1,0]]
 * Explanation: The palindromes are ["battab","tabbat"]
 *
 *
 *
 *
 */

// @lc code=start
func palindromePairs(words []string) [][]int {
	var res [][]int

	l1 := len(words)

	for i := 0; i < l1-1; i++ {
		for j := i + 1; j < l1; j++ {

			if checkPalindrome(words, i, j) {
				res = append(res, []int{i, j})
			}

			if checkPalindrome(words, j, i) {
				res = append(res, []int{j, i})
			}
		}
	}

	return res
}

func checkPalindrome(words []string, i, j int) bool {
	s := words[i] + words[j]
	begin := 0
	end := len(s) - 1

	for begin < end {
		if s[begin] != s[end] {
			return false
		}
		begin++
		end--
	}
	return true
}

// @lc code=end

