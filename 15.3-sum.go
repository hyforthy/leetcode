import "sort"

/*
 * @lc app=leetcode id=15 lang=golang
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.85%)
 * Likes:    4603
 * Dislikes: 533
 * Total Accepted:    658K
 * Total Submissions: 2.6M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 *
 * Note:
 *
 * The solution set must not contain duplicate triplets.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 *
 *
 */

// @lc code=start
func threeSum(nums []int) [][]int {
	sort.Ints(nums)

	var res [][]int

	l1 := len(nums)

	for i := 0; i < l1; {
		target := -nums[i]
		begin := i + 1
		end := l1 - 1

		for begin < end {
			sum := nums[begin] + nums[end]
			if sum < target {
				begin++
				continue
			}
			if sum > target {
				end--
				continue
			}

			if sum == target {
				res = append(res, []int{nums[i], nums[begin], nums[end]})

				second := nums[begin]
				third := nums[end]
				for begin < end && second == nums[begin] {
					begin++
				}

				for begin < end && third == nums[end] {
					end--
				}
			}
		}

		j := i + 1
		for j < l1 && nums[i] == nums[j] {
			j++
		}
		i = j
	}

	return res
}

// @lc code=end

