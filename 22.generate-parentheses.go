/*
 * @lc app=leetcode id=22 lang=golang
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (57.29%)
 * Likes:    3409
 * Dislikes: 202
 * Total Accepted:    403.4K
 * Total Submissions: 702.4K
 * Testcase Example:  '3'
 *
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 *
 * For example, given n = 3, a solution set is:
 *
 *
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 *
 */

// @lc code=start
func generateParenthesis(n int) []string {

	var res []string
	generateParenthesis_(n, "", n, &res)
	return res
}

func generateParenthesis_(n int, path string, totalN int, res *[]string) {
	l1 := len(path)
	if l1 == (totalN << 1) {
		*res = append(*res, path)
		return
	}

	if n > 0 {
		generateParenthesis_(n-1, path+"(", totalN, res)
	}
	if l1 < ((totalN - n) << 1) {
		generateParenthesis_(n, path+")", totalN, res)
	}
}

// func generateParenthesis(n int) []string {
// 	res := [][]string{{""}}
// 	for i := 1; i <= n; i++ {
// 		for j := 0; j < i; j++ {
// 			for _, s1 := range res[j] {
// 				for _, s2 := range res[i-1-j] {
// 					if len(res) < i+1 {
// 						res = append(res, []string{})
// 					}
// 					res[i] = append(res[i], "("+s1+")"+s2)
// 				}
// 			}
// 		}
// 	}

// 	return res[n]
// }

// @lc code=end
