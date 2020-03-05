/*
 * @lc app=leetcode id=464 lang=golang
 *
 * [464] Can I Win
 *
 * https://leetcode.com/problems/can-i-win/description/
 *
 * algorithms
 * Medium (27.96%)
 * Likes:    716
 * Dislikes: 127
 * Total Accepted:    41.8K
 * Total Submissions: 149.1K
 * Testcase Example:  '10\n11'
 *
 * In the "100 game," two players take turns adding, to a running total, any
 * integer from 1..10. The player who first causes the running total to reach
 * or exceed 100 wins.
 *
 * What if we change the game so that players cannot re-use integers?
 *
 * For example, two players might take turns drawing from a common pool of
 * numbers of 1..15 without replacement until they reach a total >= 100.
 *
 * Given an integer maxChoosableInteger and another integer desiredTotal,
 * determine if the first player to move can force a win, assuming both players
 * play optimally.
 *
 * You can always assume that maxChoosableInteger will not be larger than 20
 * and desiredTotal will not be larger than 300.
 *
 *
 * Example
 *
 * Input:
 * maxChoosableInteger = 10
 * desiredTotal = 11
 *
 * Output:
 * false
 *
 * Explanation:
 * No matter which integer the first player choose, the first player will lose.
 * The first player can choose an integer from 1 up to 10.
 * If the first player choose 1, the second player can only choose integers
 * from 2 up to 10.
 * The second player will win by choosing 10 and get a total = 11, which is >=
 * desiredTotal.
 * Same with other integers chosen by the first player, the second player will
 * always win.
 *
 *
 */

// @lc code=start
func canIWin(maxChoosableInteger int, desiredTotal int) bool {
	if maxChoosableInteger >= desiredTotal {
		return true
	}

	if (1+maxChoosableInteger)*maxChoosableInteger/2 < desiredTotal {
		return false
	}
	m := make(map[int]bool)
	return canIWin_(maxChoosableInteger, desiredTotal, 0, m)
}

func canIWin_(maxChoosableInteger int, desiredTotal int, used int, m map[int]bool) bool {
	if _, ok := m[used]; ok {
		return m[used]
	}

	for i := 0; i < maxChoosableInteger; i++ {
		cur := 1 << uint(i)
		if cur&used != 0 {
			continue
		}

		if i+1 >= desiredTotal {
			m[used] = true
			return true
		}

		if !canIWin_(maxChoosableInteger, desiredTotal-1-i, used|cur, m) { // 第二个选手赢不了时
			m[used] = true
			return true
		}
	}
	m[used] = false
	return false
}

// @lc code=end
