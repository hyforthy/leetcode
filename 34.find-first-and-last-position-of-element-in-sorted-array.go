/*
 * @lc app=leetcode id=34 lang=golang
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (34.30%)
 * Likes:    2097
 * Dislikes: 98
 * Total Accepted:    362.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Example 1:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 *
 * Example 2:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 *
 */

// @lc code=start
func searchRange(nums []int, target int) []int {
	res := []int{-1, -1}
	l1 := len(nums)
	if l1 <= 0 {
		return res
	}

	begin := 0
	end := l1 - 1

	for begin <= end {
		mid := (begin + end) >> 1
		if nums[mid] < target {
			begin = mid + 1
		} else {
			end = mid - 1
		}
	}

	if begin < 0 || begin >= l1 || nums[begin] != target {
		return res
	}

	res[0] = begin
	end = l1 - 1
	for begin <= end {
		mid := (begin + end) >> 1
		if nums[mid] <= target {
			begin = mid + 1
		} else {
			end = mid - 1
		}
	}
	res[1] = end

	return res
}

// @lc code=end

