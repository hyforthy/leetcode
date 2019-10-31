/*
 * @lc app=leetcode id=547 lang=golang
 *
 * [547] Friend Circles
 *
 * https://leetcode.com/problems/friend-circles/description/
 *
 * algorithms
 * Medium (55.26%)
 * Likes:    1284
 * Dislikes: 104
 * Total Accepted:    111.9K
 * Total Submissions: 201.4K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 *
 * There are N students in a class. Some of them are friends, while some are
 * not. Their friendship is transitive in nature. For example, if A is a direct
 * friend of B, and B is a direct friend of C, then A is an indirect friend of
 * C. And we defined a friend circle is a group of students who are direct or
 * indirect friends.
 *
 *
 *
 * Given a N*N matrix M representing the friend relationship between students
 * in the class. If M[i][j] = 1, then the ith and jth students are direct
 * friends with each other, otherwise not. And you have to output the total
 * number of friend circles among all the students.
 *
 *
 * Example 1:
 *
 * Input:
 * [[1,1,0],
 * ⁠[1,1,0],
 * ⁠[0,0,1]]
 * Output: 2
 * Explanation:The 0th and 1st students are direct friends, so they are in a
 * friend circle. The 2nd student himself is in a friend circle. So return
 * 2.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * [[1,1,0],
 * ⁠[1,1,1],
 * ⁠[0,1,1]]
 * Output: 1
 * Explanation:The 0th and 1st students are direct friends, the 1st and 2nd
 * students are direct friends, so the 0th and 2nd students are indirect
 * friends. All of them are in the same friend circle, so return 1.
 *
 *
 *
 *
 * Note:
 *
 * N is in range [1,200].
 * M[i][i] = 1 for all students.
 * If M[i][j] = 1, then M[j][i] = 1.
 *
 *
 */

// @lc code=start
// func findCircleNum(M [][]int) int {
// 	res := 0

// 	l1 := len(M)
// 	if l1 <= 0 {
// 		return res
// 	}

// 	for i := 0; i < l1; i++ {
// 		for j := i; j < l1; j++ {
// 			if M[i][j] == 1 {
// 				res++
// 				findCircleNum_(M, l1, i, j)
// 			}
// 		}
// 	}

// 	return res
// }

// func findCircleNum_(M [][]int, l1, i, j int) {
// 	if M[i][j] == 0 {
// 		return
// 	}
// 	M[i][j] = 0
// 	pos := i
// 	for pos < l1 {
// 		findCircleNum_(M, l1, i, pos)
// 		pos++
// 	}

// 	if i == j {
// 		return
// 	}

// 	pos = 0
// 	for pos < l1 {
// 		findCircleNum_(M, l1, j, pos)
// 		pos++
// 	}

// }

func findCircleNum(M [][]int) int {
	res := 0

	l1 := len(M)
	if l1 <= 0 {
		return res
	}

	done := make([]bool, l1)
	for i := 0; i < l1; i++ {
		if !done[i] {
			res++
			findCircleNum_(M, l1, i, done)
		}
	}

	return res
}

func findCircleNum_(M [][]int, l1, i int, done []bool) {
	done[i] = true
	for j := 0; j < l1; j++ {
		if !done[j] && M[i][j] == 1 {
			findCircleNum_(M, l1, j, done)
		}
	}

}

// @lc code=end

