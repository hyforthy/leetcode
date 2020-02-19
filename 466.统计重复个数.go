/*
 * @lc app=leetcode.cn id=466 lang=golang
 *
 * [466] 统计重复个数
 *
 * https://leetcode-cn.com/problems/count-the-repetitions/description/
 *
 * algorithms
 * Hard (30.04%)
 * Likes:    26
 * Dislikes: 0
 * Total Accepted:    877
 * Total Submissions: 2.9K
 * Testcase Example:  '"acb"\n4\n"ab"\n2'
 *
 * 定义由 n 个连接的字符串 s 组成字符串 S，即 S = [s,n]。例如，["abc", 3]=“abcabcabc”。
 *
 * 另一方面，如果我们可以从 s2 中删除某些字符使其变为 s1，我们称字符串 s1 可以从字符串 s2 获得。例如，“abc” 可以根据我们的定义从
 * “abdbec” 获得，但不能从 “acbbe” 获得。
 *
 * 现在给出两个非空字符串 s1 和 s2（每个最多 100 个字符长）和两个整数 0 ≤ n1 ≤ 10^6 和 1 ≤ n2 ≤
 * 10^6。现在考虑字符串 S1 和 S2，其中S1=[s1,n1]和S2=[s2,n2]。找出可以使[S2,M]从 S1 获得的最大整数 M。
 *
 * 示例：
 *
 * 输入：
 * s1 ="acb",n1 = 4
 * s2 ="ab",n2 = 2
 *
 * 返回：
 * 2
 *
 *
 */

// @lc code=start
func getMaxRepetitions(s1 string, n1 int, s2 string, n2 int) int {
	l1 := len(s1)
	l2 := len(s2)

	if n1 == 0 || l1 == 0 {
		return 0
	}

	var countNow []int // 第i个元素代表第0~i个s1拼接得到的字符串可以得到多少个s2

	indexMap := make(map[int]int) // key是每一个s1结束时，数到的s2的位置； value是s1的序号

	checkPos := 0
	count := 0
	for i := 0; i < n1; i++ {
		for j := 0; j < l1; j++ {
			if s1[j] == s2[checkPos] {
				checkPos++
				if checkPos >= l2 {
					count++
					checkPos = 0
				}
			}
		}

		countNow = append(countNow, count)

		if v, ok := indexMap[checkPos]; ok {
			pre := countNow[v]
			repeated := (n1 - 1 - v) / (i - v) * (count - countNow[v])
			remain := countNow[v+(n1-1-v)%(i-v)] - pre
			// if (n1-1-v)%(i-v) == 0 {
			// 	remain = 0
			// }
			return (pre + repeated + remain) / n2
		}

		indexMap[checkPos] = i
	}

	return countNow[n1-1] / n2
}

// @lc code=end
