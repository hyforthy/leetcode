
import (
	"fmt"
	"math"
	"sort"
	"strconv"
)

// Q1
// 寻找数组中超过半数的数
// 每次剔除2个不同数字，剩下的相同的数字就是众数-摩尔投票法
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
// 一个正整数的数组，将其中元素连接形成新的整数使其最小，连接后整数用字符串表示。比如[3,32,321]的最小形式是"321323"
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
// 购物单问题，不考虑主附件, 要求在给定的金钱数额下，使买到的物品价格乘权重最大
// 实际是0-1背包问题
// info里的元素[p v], p是价格，v是权重
func GouwudPure(info [][]int, money int) int64 {
	m := len(info)

	dp := make([][]int64, m+1)
	for i := 0; i < m+1; i++ {
		dp[i] = make([]int64, money+1)
	}

	for i := 1; i <= m; i++ {
		for j := 1; j <= money; j++ {
			if info[i-1][0] <= j {
				dp[i][j] = int64(math.Max(float64(dp[i-1][j]), float64(dp[i-1][j-info[i-1][0]]+int64(info[i-1][0])*int64(info[i-1][1]))))
			} else {
				dp[i][j] = dp[i-1][j]
			}
		}
	}

	return dp[m][money]

}

// Q4
// 火车按顺序停进站，类似栈接口，只有后进的火车出站了，里面的火车才能出来
// 给出火车进站顺序列表，求一共多少种出站组合？
/////// method1
func GetTrainCountWithStack(myInput []int) int {
	l1 := len(myInput)
	if l1 <= 0 {
		return 0
	}

	stack := make([]int, l1)
	return RecursiveTrainWithStack(myInput, stack, 0)
}

func RecursiveTrainWithStack(myInput, stack []int, stackN int) int {
	if len(myInput) == 0 {
		return 1
	}

	if stackN == 0 {
		stack[0] = myInput[0]
		return RecursiveTrainWithStack(myInput[1:], stack, 1)
	}

	stack[stackN] = myInput[0]
	c1 := RecursiveTrainWithStack(myInput[1:], stack, stackN+1)
	c2 := RecursiveTrainWithStack(myInput, stack, stackN-1)
	return c1 + c2
}

///////

/////// method1.1
// 打印出所有排列
func GetTrainCountWithStack(myInput []int) int {
	l1 := len(myInput)
	if l1 <= 0 {
		return 0
	}

	stack := make([]int, l1)
	out := make([]int, l1)
	totalN := 0
	return RecursiveTrainWithStack(myInput, stack, 0, out, totalN)
}

func RecursiveTrainWithStack(myInput, stack []int, stackN int, out []int, totalN int) int {
	if len(myInput) == 0 {
		for i := stackN - 1; i >= 0; i-- {
			out[totalN] = stack[i]
			totalN += 1
		}
		fmt.Println(out)
		return 1
	}

	if stackN > 0 { // 多分支注意恢复原状态
		out[totalN] = stack[stackN-1]
		reserveE := stack[stackN-1]
		c1 := RecursiveTrainWithStack(myInput, stack, stackN-1, out, totalN+1)

		stack[stackN-1] = reserveE
		stack[stackN] = myInput[0]
		c2 := RecursiveTrainWithStack(myInput[1:], stack, stackN+1, out, totalN)
		return c1 + c2
	}

	stack[0] = myInput[0]
	return RecursiveTrainWithStack(myInput[1:], stack, 1, out, totalN)
}

///////

/////// method2
// 只输出排列总数，根本无需真实的栈
func GetTrainCount(myInput []int) int {
	l1 := len(myInput)
	if l1 <= 0 {
		return 0
	}

	return RecursiveTrain(myInput, 0)
}

func RecursiveTrain(myInput []int, stackN int) int {
	if len(myInput) == 0 {
		return 1
	}

	if stackN == 0 {
		return RecursiveTrain(myInput[1:], 1)
	}

	c1 := RecursiveTrain(myInput[1:], stackN+1)
	c2 := RecursiveTrain(myInput, stackN-1)
	return c1 + c2
}

///////

/////// method3
// 打印出所有排列
// 思路：列出所有排列，过滤掉不合要求的排列
func GetAllRank(myInput []int, k, n int) {
	if k == n-1 {
		CheckAndPrintRank(myInput)
		return
	}
	for i := k; i < n; i++ {
		// switch
		if i != k {
			tmp := myInput[i]
			myInput[i] = myInput[k]
			myInput[k] = tmp //
		}

		GetAllRank(myInput, k+1, n)
		if i != k {
			tmp := myInput[i]
			myInput[i] = myInput[k]
			myInput[k] = tmp //
		}
	}
}

func CheckAndPrintRank(myInput []int) {
	l1 := len(myInput)

	// 判断规则：比当前数小的后面的数必须以降序排列
	for i := 0; i+1 < l1; i++ {
		min := myInput[i+1]
		for j := i + 2; j < l1; j++ {
			if myInput[j] < myInput[i] {
				if myInput[j] > min {
					return
				} else {
					min = myInput[j]
				}
			}
		}
	}
	fmt.Println(myInput)
}

///////

// Q5
// 一个正整数的数组，分成两堆，使两堆差值的绝对值最小，请获取此绝对值
//
func GetMinMinus(myInput []int) int {
	l1 := len(myInput)
	if l1 <= 0 {
		return -1
	}

	sum := 0
	for i := 0; i < l1; i++ {
		sum += myInput[i]
	}
	l2 := sum >> 1

	dp := make([][]int, l1+1)
	for i := 0; i < l1+1; i++ {
		dp[i] = make([]int, l2+1)
	}

	for i := 1; i <= l1; i++ {
		for j := 1; j <= l2; j++ {
			dp[i][j] = dp[i-1][j]
			if myInput[i-1] <= j && dp[i-1][j-myInput[i-1]]+myInput[i-1] > dp[i][j] {
				dp[i][j] = dp[i-1][j-myInput[i-1]] + myInput[i-1]
			}

		}
	}

	return sum - (dp[l1][l2] << 1)
}

///////