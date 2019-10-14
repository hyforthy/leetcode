/*
 * @lc app=leetcode id=17 lang=golang
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (43.17%)
 * Likes:    2647
 * Dislikes: 339
 * Total Accepted:    457.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 *
 * Example:
 *
 *
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 *
 */

// @lc code=start

func letterCombinations(digits string) []string {
	dMap := map[int][]int8{
		2: {'a', 'b', 'c'},
		3: {'d', 'e', 'f'},
		4: {'g', 'h', 'i'},
		5: {'j', 'k', 'l'},
		6: {'m', 'n', 'o'},
		7: {'p', 'q', 'r', 's'},
		8: {'t', 'u', 'v'},
		9: {'w', 'x', 'y', 'z'},
	}

	l1 := len(digits)
	if l1 <= 0 {
		return nil
	}

	var res []string
	letterCombinationsDfs_(digits, l1, 0, "", dMap, &res)
	return res
}

func letterCombinationsDfs_(digits string, digitsL, pos int, path string, dMap map[int][]int8, res *[]string) {
	if pos == digitsL {
		*res = append(*res, path)
		return
	}

	l1 := len(dMap[int(digits[pos]-'0')])

	for i := 0; i < l1; i++ {
		reserve := path
		path += string(dMap[int(digits[pos]-'0')][i])
		letterCombinationsDfs_(digits, digitsL, pos+1, path, dMap, res)
		path = reserve
	}
}

// it is good method below, no recursive
// func letterCombinations(digits string) []string {
// 	dMap := map[int][]int8{
// 		2: {'a', 'b', 'c'},
// 		3: {'d', 'e', 'f'},
// 		4: {'g', 'h', 'i'},
// 		5: {'j', 'k', 'l'},
// 		6: {'m', 'n', 'o'},
// 		7: {'p', 'q', 'r', 's'},
// 		8: {'t', 'u', 'v'},
// 		9: {'w', 'x', 'y', 'z'},
// 	}

// 	l1 := len(digits)
// 	if l1 <= 0 {
// 		return nil
// 	}

// 	first := ""
// 	for i := 0; i < l1; i++ {
// 		first += string(dMap[int(digits[i]-'0')][0])
// 	}
// 	res := []string{first}

// 	for i := 0; i < l1; i++ {

// 		l2 := len(dMap[int(digits[i]-'0')])
// 		l3 := len(res)
// 		for j := 1; j < l2; j++ {
// 			for k := 0; k < l3; k++ {
// 				res = append(res, res[k][0:i]+string(dMap[int(digits[i]-'0')][j])+res[k][i+1:])
// 			}
// 		}
// 	}

// 	return res
// }

// @lc code=end

