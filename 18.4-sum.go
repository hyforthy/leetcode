import "sort"

/*
 * @lc app=leetcode id=18 lang=golang
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (31.57%)
 * Likes:    1284
 * Dislikes: 256
 * Total Accepted:    267.2K
 * Total Submissions: 844.8K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 *
 * Note:
 *
 * The solution set must not contain duplicate quadruplets.
 *
 * Example:
 *
 *
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 *
 *
 */

// @lc code=start
func fourSum(nums []int, target int) [][]int {
	l1 := len(nums)
	if l1 < 4 {
		return nil
	}
	sort.Ints(nums)
	var res [][]int

	if nums[l1-1]+nums[l1-2]+nums[l1-3]+nums[l1-4] < target {
		return nil
	}

	for i := 0; i < l1-3; {
		if i > 0 && nums[i] == nums[i-1] {
			i++
			continue
		}

		if nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target {
			break
		}
		if nums[i]+nums[l1-1]+nums[l1-2]+nums[l1-3] < target {
			i++
			continue
		}

		for j := i + 1; j < l1-2; {
			if j > i+1 && nums[j] == nums[j-1] {
				j++
				continue
			}

			if nums[i]+nums[j]+nums[j+1]+nums[j+2] > target {
				break
			}
			if nums[i]+nums[j]+nums[l1-1]+nums[l1-2] < target {
				j++
				continue
			}

			begin := j + 1
			end := l1 - 1

			for begin < end {
				to := target - nums[i] - nums[j]
				if nums[begin]+nums[end] < to {
					begin++
				} else if nums[begin]+nums[end] > to {
					end--
				} else {
					res = append(res, []int{nums[i], nums[j], nums[begin], nums[end]})
					t := nums[begin]
					for begin < end && nums[begin] == t {
						begin++
					}
					t = nums[end]
					for begin < end && nums[end] == t {
						end--
					}
				}
			}
			j++

		}
		i++

	}
	return res
}

// @lc code=end

