
import (
	"fmt"
	"sort"
	"strconv"
)

// Q1
// 寻找数组中超过半数的数。每次剔除2个不同数字，剩下的相同的数字就是众数-摩尔投票法
func FindMostData(array []int) []int {
	result := 0
	count := 0

	l := len(array)
	for i := 0; i < l; i++ {
		if count == 0 {
			count++
			result = array[i]
		} else {
			if result == array[i] {
				count++
			} else {
				count--
			}
		}
	}

	count = 0
	for i := 0; i < l; i++ {
		if result == array[i] {
			count++
		}
	}

	if count > l/2 {
		return []int{result}
	}

	return []int{}
}

// Q2
// 数组中元素有正有负，求子序列和的最大值
// array can not be empty
func MaxSubArraySum(array []int) int {
	l := len(array)

	cur := array[0]
	max := cur

	for i := 0; i < l; i++ {
		if cur >= 0 {
			cur += array[i]
		} else {
			cur = array[i]
		}

		if cur > max {
			max = cur
		}
	}
	return max
}

// Q3
// 一个正整数的数组，将其中整数连接形成新的整数使其最小，连接后整数用字符串表示。比如[3,32,321]的最小形式是"321323"
type StringNumber []string

func (p StringNumber) Len() int {
	return len(p)
}

func (p StringNumber) Less(a, b int) bool {
	return p[a]+p[b] < p[b]+p[a]
}

func (p StringNumber) Swap(a, b int) {
	orig := p[a]
	p[a] = p[b]
	p[b] = orig
}

func MinNumber(nums []int) string {
	strs := StringNumber([]string{})

	for _, v := range nums {
		strs = append(strs, strconv.Itoa(v))
	}

	sort.Sort(strs)

	fmt.Println(strs)
	result := ""

	for _, v := range strs {
		result += v
	}

	return result
}

// Q4
// 丑数：只包含质因数2、3、5的数是丑数，例如6、8是丑数，但7、14不是，因为含质因数7。
// 求第n个丑数，规定1是第一个丑数。
func GetUglyNum(n int) int {

}