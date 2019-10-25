import "math"

/*
 * @lc app=leetcode id=128 lang=golang
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (42.82%)
 * Likes:    2279
 * Dislikes: 129
 * Total Accepted:    238.1K
 * Total Submissions: 554K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 *
 * Your algorithm should run in O(n) complexity.
 *
 * Example:
 *
 *
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 */

// @lc code=start
// func longestConsecutive(nums []int) int {
// 	mm := make(map[int]int)
// 	res := 0

// 	for _, v := range nums {
// 		if mm[v] == 0 {
// 			lCount := mm[v-1]
// 			rCount := mm[v+1]
// 			sum := lCount + rCount + 1
// 			mm[v] = sum
// 			mm[v-lCount] = sum
// 			mm[v+rCount] = sum
// 			res = int(math.Max(float64(sum), float64(res)))
// 		}
// 	}

// 	return res
// }

func longestConsecutive(nums []int) int {
	mm := make(map[int]bool)
	res := 0

	for _, v := range nums {
		mm[v] = true
	}

	for _, v := range nums {
		if mm[v] == false {
			continue
		}
		mm[v] = false

		pre := v - 1
		next := v + 1

		for {
			if _, ok := mm[pre]; ok {
				mm[pre] = false
				pre--
			} else {
				break
			}
		}

		for {
			if _, ok := mm[next]; ok {
				mm[next] = false
				next++
			} else {
				break
			}
		}

		sum := next - pre - 1
		res = int(math.Max(float64(sum), float64(res)))

	}

	return res
}

// @lc code=end

