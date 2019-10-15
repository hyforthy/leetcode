/*
 * @lc app=leetcode id=416 lang=golang
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (41.74%)
 * Likes:    1526
 * Dislikes: 41
 * Total Accepted:    111.7K
 * Total Submissions: 267.5K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 *
 * Note:
 *
 *
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [1, 5, 11, 5]
 *
 * Output: true
 *
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [1, 2, 3, 5]
 *
 * Output: false
 *
 * Explanation: The array cannot be partitioned into equal sum subsets.
 *
 *
 *
 *
 */

// @lc code=start
// 0-1背包问题
// func canPartition(nums []int) bool {
// 	sum := 0
// 	for _, v := range nums {
// 		sum += v
// 	}

// 	if sum%2 != 0 {
// 		return false
// 	}

// 	l1 := len(nums)
// 	l2 := sum/2 + 1

// 	dp := make([][]bool, l1)
// 	for i := 0; i < l1; i++ {
// 		dp[i] = make([]bool, l2)
// 	}
// 	dp[0][0] = true // dp[i][j]含义：前i个元素中可否找出部分元素使其和为j，可以：true，不可以：false

// 	for i := 1; i < l1; i++ {
// 		for j := 0; j < l2; j++ {
// 			dp[i][j] = dp[i-1][j]
// 			if dp[i][j] {
// 				continue
// 			}

// 			if nums[i] <= j {
// 				dp[i][j] = dp[i-1][j-nums[i]]
// 			} else {
// 				dp[i][j] = false
// 			}
// 		}
// 	}

// 	return dp[l1-1][l2-1]

// }

func canPartition(nums []int) bool {
	sum := 0
	for _, v := range nums {
		sum += v
	}

	if sum%2 != 0 {
		return false
	}

	l1 := len(nums)
	l2 := sum/2 + 1

	dp := make([][]bool, 2)
	for i := 0; i < 2; i++ {
		dp[i] = make([]bool, l2)
	}
	dp[0][0] = true

	for i := 1; i < l1; i++ {
		for j := 0; j < l2; j++ {
			dp[i&1][j] = dp[(i&1)^1][j]
			if dp[i&1][j] {
				continue
			}

			if nums[i] <= j {
				dp[i&1][j] = dp[(i&1)^1][j-nums[i]]
			} else {
				dp[i&1][j] = false
			}
		}
	}

	return dp[(l1-1)&1][l2-1]

}

// func canPartition(nums []int) bool {
// 	sort.Ints(nums)

// 	l1 := len(nums)
// 	sum1 := 0
// 	sum2 := 0

// 	for i := l1 - 1; i >= 0; i-- {
// 		if sum1 >= sum2 {
// 			sum2 += nums[i]
// 		} else {
// 			sum1 += nums[i]
// 		}
// 	}

// 	return sum1 == sum2
// }

// @lc code=end

