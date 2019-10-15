/*
 * @lc app=leetcode id=207 lang=golang
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (39.43%)
 * Likes:    2283
 * Dislikes: 110
 * Total Accepted:    267.4K
 * Total Submissions: 676.2K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 *
 * Example 1:
 *
 *
 * Input: 2, [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *
 * Example 2:
 *
 *
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 *
 *
 * Note:
 *
 *
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 *
 *
 */

// @lc code=start
// dfs遍历有无回环
func canFinish(numCourses int, prerequisites [][]int) bool {
	l1 := len(prerequisites)

	dMap := make(map[int][]int)

	for i := 0; i < l1; i++ {
		if _, ok := dMap[prerequisites[i][0]]; !ok {
			dMap[prerequisites[i][0]] = []int{prerequisites[i][1]}
		} else {
			dMap[prerequisites[i][0]] = append(dMap[prerequisites[i][0]], prerequisites[i][1])
		}
	}

	path := make(map[int]bool)
	done := make(map[int]bool)
	for i := 0; i < numCourses; i++ {

		r := canFinish_(i, path, done, dMap)
		if r == false {
			return false
		}
	}
	return true
}

func canFinish_(course int, path, done map[int]bool, dMap map[int][]int) bool {
	if _, ok := path[course]; ok && path[course] {
		return false
	}
	if _, ok := done[course]; ok {
		return true
	}

	path[course] = true
	done[course] = true

	for _, v := range dMap[course] {
		r := canFinish_(v, path, done, dMap)
		if r == false {
			return false
		}
	}
	path[course] = false
	return true
}

// @lc code=end

