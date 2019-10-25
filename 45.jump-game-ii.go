import "math"

/*
 * @lc app=leetcode id=45 lang=golang
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (28.89%)
 * Likes:    1539
 * Dislikes: 87
 * Total Accepted:    200K
 * Total Submissions: 688.7K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * Example:
 *
 *
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 *
 * Note:
 *
 * You can assume that you can always reach the last index.
 *
 */

// @lc code=start
func jump(nums []int) int {
	res := 0
	l1 := len(nums)
	if l1 <= 0 {
		return res
	}

	pos := 0
	nowMax := 0
	for pos < l1-1 {
		res++
		nextMax := nowMax
		for i := pos; i <= nowMax; i++ {
			nextMax = int(math.Max(float64(nextMax), float64(i+nums[i])))
			if nextMax >= l1-1 {
				return res
			}
		}

		if nextMax <= nowMax {
			return -1
		}

		pos = nowMax + 1
		nowMax = nextMax
	}

	return res
}

// @lc code=end

