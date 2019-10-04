import (
	"strings"
)

/*
 * @lc app=leetcode id=6 lang=golang
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (33.39%)
 * Likes:    1208
 * Dislikes: 3660
 * Total Accepted:    365.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 *
 * string convert(string s, int numRows);
 *
 * Example 1:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 *
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 */

// @lc code=start
// func convert(s string, numRows int) string {
// 	l := len(s)
// 	if l <= 0 || numRows <= 0 {
// 		return ""
// 	}
// 	if numRows == 1 {
// 		return s
// 	}

// 	rowList := make([]string, numRows)

// 	segment := (numRows - 1) * 2

// 	for i := 0; i < l; i++ {
// 		id := i % segment
// 		if id < numRows {
// 			rowList[id] += string(s[i])
// 		} else {
// 			rowList[segment-id] += string(s[i])
// 		}
// 	}

// 	return strings.Join(rowList, "")
// }

func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}

	index := 0
	direct := 0
	rowList := make([]string, numRows)
	l := len(s)

	for i := 0; i < l; i++ {
		rowList[index] += string(s[i])
		if index == numRows-1 {
			direct = 1
		} else if index == 0 {
			direct = 0
		}

		if direct == 0 {
			index += 1
		} else {
			index -= 1
		}
	}

	return strings.Join(rowList, "")
}

// @lc code=end

