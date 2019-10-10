/*
 * @lc app=leetcode id=313 lang=golang
 *
 * [313] Super Ugly Number
 *
 * https://leetcode.com/problems/super-ugly-number/description/
 *
 * algorithms
 * Medium (42.75%)
 * Likes:    425
 * Dislikes: 110
 * Total Accepted:    65.9K
 * Total Submissions: 154.1K
 * Testcase Example:  '12\n[2,7,13,19]'
 *
 * Write a program to find the n^th super ugly number.
 *
 * Super ugly numbers are positive numbers whose all prime factors are in the
 * given prime list primes of size k.
 *
 * Example:
 *
 *
 * Input: n = 12, primes = [2,7,13,19]
 * Output: 32
 * Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first
 * 12
 * ⁠            super ugly numbers given primes = [2,7,13,19] of size 4.
 *
 * Note:
 *
 *
 * 1 is a super ugly number for any given primes.
 * The given numbers in primes are in ascending order.
 * 0 < k ≤ 100, 0 < n ≤ 10^6, 0 < primes[i] < 1000.
 * The n^th super ugly number is guaranteed to fit in a 32-bit signed integer.
 *
 *
 */

// @lc code=start
func nthSuperUglyNumber(n int, primes []int) int {
	l1 := len(primes)
	if l1 <= 0 {
		return -1
	}
	t := make([]int, l1)

	res := make([]int, n)
	res[0] = 1

	for i := 1; i < n; i++ {
		min := int64(res[t[0]] * primes[0])
		choose := []int{0}
		for j := 1; j < l1; j++ {
			now := int64(res[t[j]] * primes[j])
			if min > now {
				min = now
				choose = []int{j}
			} else if min == now {
				choose = append(choose, j)
			}
		}
		res[i] = res[t[choose[0]]] * primes[choose[0]]
		for _, v := range choose {
			t[v]++
		}

	}
	return res[n-1]
}

// @lc code=end

