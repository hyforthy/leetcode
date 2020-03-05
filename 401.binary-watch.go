import (
	"fmt"
	"strconv"
)

/*
 * @lc app=leetcode id=401 lang=golang
 *
 * [401] Binary Watch
 *
 * https://leetcode.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (45.83%)
 * Likes:    425
 * Dislikes: 732
 * Total Accepted:    70.8K
 * Total Submissions: 154.3K
 * Testcase Example:  '0'
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and
 * the 6 LEDs on the bottom represent the minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the
 * right.
 *
 * For example, the above binary watch reads "3:25".
 *
 * Given a non-negative integer n which represents the number of LEDs that are
 * currently on, return all possible times the watch could represent.
 *
 * Example:
 * Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04",
 * "0:08", "0:16", "0:32"]
 *
 *
 * Note:
 *
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid,
 * it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for
 * example "10:2" is not valid, it should be "10:02".
 *
 *
 */

// @lc code=start
// func readBinaryWatch(num int) []string {
// 	var res []string
// 	doRead(&res, num, 0, 0, 1)
// 	return res
// }

// func doRead(res *[]string, num int, hour, minute int, pos uint) {

// 	if num == 0 {
// 		*res = append(*res, strconv.Itoa(hour)+":"+fmt.Sprintf("%02d", minute))
// 		return
// 	}

// 	for i := pos; i <= 10; i++ {
// 		if i >= 5 {
// 			if minute+1<<(10-i) >= 60 {
// 				continue
// 			}
// 			doRead(res, num-1, hour, minute+1<<(10-i), i+1)
// 		} else {
// 			if hour+1<<(4-i) >= 12 {
// 				continue
// 			}
// 			doRead(res, num-1, hour+1<<(4-i), minute, i+1)
// 		}
// 	}
// }

func readBinaryWatch(num int) []string {
	var res []string
	doRead(&res, num, 0, 0, 1)
	return res
}

func doRead(res *[]string, num int, hour, minute int, pos uint) {

	if num == 0 {
		*res = append(*res, strconv.Itoa(hour)+":"+fmt.Sprintf("%02d", minute))
		return
	}

	for i := pos; i <= 10; i++ {
		if i >= 5 {
			if minute+1<<(i-5) >= 60 {
				return
			}
			doRead(res, num-1, hour, minute+1<<(i-5), i+1)
		} else {
			if hour+1<<(i-1) >= 12 {
				continue
			}
			doRead(res, num-1, hour+1<<(i-1), minute, i+1)
		}
	}
}

// @lc code=end
