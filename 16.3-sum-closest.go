import (
	"math"
	"sort"
)

/*
 * @lc app=leetcode id=16 lang=golang
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.75%)
 * Likes:    1362
 * Dislikes: 97
 * Total Accepted:    385.4K
 * Total Submissions: 842.5K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 */

// @lc code=start
func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)
	res := 0
	l1 := len(nums)

	abs := math.MaxFloat64
	for i := 0; i < l1; i++ {
		to := target - nums[i]

		begin := i + 1
		end := l1 - 1

		for begin < end {
			sum := nums[begin] + nums[end]

			t := math.Abs(float64(sum - to))
			if abs > t {
				abs = t
				res = sum + nums[i]
			}

			if sum < to {
				begin++
			} else if sum > to {
				end--
			} else {
				return target
			}

		}
	}
	return res
}

// @lc code=end

