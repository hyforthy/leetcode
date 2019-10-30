import (
	"math"
	"sort"
)

/*
 * @lc app=leetcode id=363 lang=golang
 *
 * [363] Max Sum of Rectangle No Larger Than K
 *
 * https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
 *
 * algorithms
 * Hard (35.64%)
 * Likes:    502
 * Dislikes: 36
 * Total Accepted:    31K
 * Total Submissions: 86.6K
 * Testcase Example:  '[[1,0,1],[0,-2,3]]\n2'
 *
 * Given a non-empty 2D matrix matrix and an integer k, find the max sum of a
 * rectangle in the matrix such that its sum is no larger than k.
 *
 * Example:
 *
 *
 * Input: matrix = [[1,0,1],[0,-2,3]], k = 2
 * Output: 2
 * Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is
 * 2,
 * and 2 is the max number no larger than k (k = 2).
 *
 * Note:
 *
 *
 * The rectangle inside the matrix must have an area > 0.
 * What if the number of rows is much larger than the number of columns?
 *
 */

// @lc code=start
func maxSumSubmatrix(matrix [][]int, k int) int {
	res := int(math.MinInt64)
	l1 := len(matrix)
	if l1 <= 0 {
		return res
	}
	l2 := len(matrix[0])

	for i := 0; i < l1; i++ {
		colSum := make([]int, l2)
		for j := i; j < l1; j++ {
			for t := 0; t < l2; t++ {
				colSum[t] += matrix[j][t]
			}

			curSet := []int{0}
			nowMax := int(math.MinInt64)
			rowSum := 0
			for t := 0; t < l2; t++ {
				rowSum += colSum[t]
				index := lowerBound(curSet, rowSum-k)

				if index < len(curSet) {
					if nowMax < rowSum-curSet[index] {
						nowMax = rowSum - curSet[index]
					}
				}
				curSet = append(curSet, rowSum)
				sort.Ints(curSet)
			}

			if res < nowMax {
				res = nowMax
			}
		}
	}
	return res
}

func lowerBound(array []int, target int) int {
	l1 := len(array)
	begin := 0
	end := l1 - 1

	for begin <= end {
		mid := (begin + end) >> 1

		if array[mid] < target {
			begin = mid + 1
		} else {
			end = mid - 1
		}
	}

	return begin
}

// @lc code=end

