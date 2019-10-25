import "sort"

/*
 * @lc app=leetcode id=90 lang=golang
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (43.85%)
 * Likes:    1124
 * Dislikes: 54
 * Total Accepted:    229.8K
 * Total Submissions: 521.4K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 *
 *
 */

// @lc code=start
func subsetsWithDup(nums []int) [][]int {
	var res [][]int
	res = append(res, []int{})
	sort.Ints(nums)

	l1 := len(nums)

	start := 0
	for i := 0; i < l1; i++ {
		l2 := len(res)
		if i == 0 || nums[i] != nums[i-1] {
			start = 0
		}

		for j := start; j < l2; j++ {
			x := make([]int, len(res[j]))
			copy(x, res[j])
			x = append(x, nums[i])
			res = append(res, x)
		}

		start = l2
	}

	return res
}

// @lc code=end

