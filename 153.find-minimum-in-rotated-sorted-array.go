/*
 * @lc app=leetcode id=153 lang=golang
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (43.64%)
 * Likes:    1269
 * Dislikes: 183
 * Total Accepted:    329K
 * Total Submissions: 753.3K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 *
 * Example 1:
 *
 *
 * Input: [3,4,5,1,2]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 *
 *
 */

// @lc code=start
func findMin(nums []int) int {
	l1 := len(nums)
	begin := 0
	end := l1 - 1

	if nums[l1-1] > nums[0] {
		return nums[0]
	}

	for begin < end {

		mid := (begin + end) >> 1
		if nums[mid] >= nums[0] {
			begin = mid + 1
		} else {
			end = mid
		}

	}

	return nums[begin]
}

// @lc code=end

