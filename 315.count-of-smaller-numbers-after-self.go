import (
	"sort"
)

/*
 * @lc app=leetcode id=315 lang=golang
 *
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (39.48%)
 * Likes:    1447
 * Dislikes: 61
 * Total Accepted:    91.9K
 * Total Submissions: 232K
 * Testcase Example:  '[5,2,6,1]'
 *
 * You are given an integer array nums and you have to return a new counts
 * array. The counts array has the property where counts[i] is the number of
 * smaller elements to the right of nums[i].
 *
 * Example:
 *
 *
 * Input: [5,2,6,1]
 * Output: [2,1,1,0]
 * Explanation:
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 *
 */

// @lc code=start
// 通过线段树实现
func countSmaller(nums []int) []int {
	l1 := len(nums)
	using := make([]int, l1)
	res := make([]int, l1)

	for i, v := range nums {
		using[i] = v
	}

	sort.Ints(using)

	m := make(map[int]int)
	for i := 0; i < l1; i++ {
		m[using[i]] = i + 1
	}

	worker := make([]int, l1<<2)

	for i := l1 - 1; i >= 0; i-- {
		res[i] = sumSmaller(worker, 1, l1, 1, m[nums[i]]-1)
		updateSmaller(worker, 1, l1, m[nums[i]], 1, 1)
	}

	return res
}

func updateSmaller(worker []int, start, end, which, value, idx int) {
	if start == end {
		worker[idx] += value
		return
	}

	mid := (start + end) >> 1

	if which <= mid {
		updateSmaller(worker, start, mid, which, value, idx<<1)
	} else {
		updateSmaller(worker, mid+1, end, which, value, (idx<<1)+1)

	}
	worker[idx] = worker[idx<<1] + worker[(idx<<1)+1]
}

func sumSmaller(worker []int, start, end, i, j int) int {
	return sumSmaller_(worker, start, end, i, j, 1)
}

func sumSmaller_(worker []int, start, end, i, j, idx int) int {
	if start > j || end < i {
		return 0
	}

	if i <= start && j >= end {
		return worker[idx]
	}

	mid := (start + end) >> 1

	return sumSmaller_(worker, start, mid, i, j, 2*idx) +
		sumSmaller_(worker, mid+1, end, i, j, 2*idx+1)
}

// todo 通过现状数组实现

// @lc code=end

