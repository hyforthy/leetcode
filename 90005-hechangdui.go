// 合唱队题目解答， 要求队形前面升序，后面降序。需要移除人员数

func GetCount(q []int) int {

	l := len(q)

	incPos := make([]int, l)
	decPos := make([]int, l)
	for i := 1; i < l; i++ {
		for j := i - 1; j >= 0; j-- {
			if q[j] < q[i] && incPos[j]+1 > incPos[i] {
				incPos[i] = incPos[j] + 1
			}
		}
	}

	for i := l - 2; i >= 0; i-- {
		for j := i + 1; j < l; j++ {
			if q[j] < q[i] && decPos[j]+1 > decPos[i] {
				decPos[i] = decPos[j] + 1
			}
		}
	}

	max := 0
	for i := 0; i < l; i++ {
		if incPos[i]+decPos[i]+1 > max {
			max = incPos[i] + decPos[i] + 1
		}
	}
	return l - max
}