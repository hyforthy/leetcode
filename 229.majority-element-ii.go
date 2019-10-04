/*
 * @lc app=leetcode id=229 lang=golang
 *
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (33.20%)
 * Likes:    1040
 * Dislikes: 124
 * Total Accepted:    113.9K
 * Total Submissions: 342.7K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times.
 *
 * Note: The algorithm should run in linear time and in O(1) space.
 *
 * Example 1:
 *
 *
 * Input: [3,2,3]
 * Output: [3]
 *
 * Example 2:
 *
 *
 * Input: [1,1,1,3,3,2,2,2]
 * Output: [1,2]
 *
 */

// @lc code=start
// 摩尔投票法，三个不同的投票同时删除，剩下的就可能是超过1/3的投票
func majorityElement(nums []int) []int {
	var v1 int
	var v2 int
	n1 := 0
	n2 := 0

	l := len(nums)

	for i := 0; i < l; i++ {
		if n1 != 0 && v1 == nums[i] {
			n1++
			continue
		}
		if n2 != 0 && v2 == nums[i] {
			n2++
			continue
		}
		if n1 == 0 {
			v1 = nums[i]
			n1++
			continue
		}
		if n2 == 0 {
			v2 = nums[i]
			n2++
			continue
		}

		n1--
		n2--
	}

	result := []int{}

	c1 := 0
	c2 := 0
	for i := 0; i < l; i++ {
		if v1 == nums[i] {
			c1++
		} else if v2 == nums[i] {
			c2++
		}
	}

	if c1 > l/3 {
		result = append(result, v1)
	}

	if c2 > l/3 {
		result = append(result, v2)
	}

	return result

}

// @lc code=end

