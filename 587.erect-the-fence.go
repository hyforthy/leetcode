/*
 * @lc app=leetcode id=587 lang=golang
 *
 * [587] Erect the Fence
 *
 * https://leetcode.com/problems/erect-the-fence/description/
 *
 * algorithms
 * Hard (34.60%)
 * Likes:    154
 * Dislikes: 161
 * Total Accepted:    7.8K
 * Total Submissions: 22.4K
 * Testcase Example:  '[[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]'
 *
 * There are some trees, where each tree is represented by (x,y) coordinate in
 * a two-dimensional garden. Your job is to fence the entire garden using the
 * minimum length of rope as it is expensive. The garden is well fenced only if
 * all the trees are enclosed. Your task is to help find the coordinates of
 * trees which are exactly located on the fence perimeter.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
 * Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
 * Explanation:
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [[1,2],[2,2],[4,2]]
 * Output: [[1,2],[2,2],[4,2]]
 * Explanation:
 *
 * Even you only have trees in a line, you need to use rope to enclose
 * them.
 *
 *
 *
 *
 * Note:
 *
 *
 * All trees should be enclosed together. You cannot cut the rope to enclose
 * trees that will separate them in more than one group.
 * All input integers will range from 0 to 100.
 * The garden has at least one tree.
 * All coordinates are distinct.
 * Input points have NO order. No order required for output.
 * input types have been changed on April 15, 2019. Please reset to default
 * code definition to get new method signature.
 *
 *
 */

// @lc code=start
func outerTrees(points [][]int) [][]int {
	l1 := len(points)
	if l1 < 4 {
		return points
	}

	first := 0
	for i := 1; i < l1; i++ {
		if points[i][0] > points[first][0] ||
			(points[i][0] == points[first][0] && points[i][1] > points[first][1]) {
			continue
		}
		first = i
	}

	res := [][]int{points[first]}

	cur := first
	for {
		next := 0
		for i := 1; i < l1; i++ {
			if i == cur {
				continue
			}

			cp := outerTreesCrossProduct(points[cur], points[i], points[next])
			if cp > 0 {
				next = i
			} else if cp == 0 && outerTreesDist(points[cur], points[i]) > outerTreesDist(points[cur], points[next]) {
				next = i
			}
		}

		for i := 0; i < l1; i++ {
			// 与next同线的点放入结果集中
			cp := outerTreesCrossProduct(points[cur], points[i], points[next])
			if cp == 0 && i != cur && i != next {
				res = append(res, points[i])
			}
		}

		cur = next

		if cur == first {
			break
		}

		res = append(res, points[next])
	}

	return res
}

// 叉积，（x1,y1）和（x2,y2）两个向量叉积： x1*y2-x2*y1, A和B的叉积为正，则A逆时针转向B，肯定说的是转小角
func outerTreesCrossProduct(a, b, c []int) int {
	return (b[0]-a[0])*(c[1]-a[1]) - (c[0]-a[0])*(b[1]-a[1])
}

func outerTreesDist(a, b []int) int {
	return (b[0]-a[0])*(b[0]-a[0]) + (b[1]-a[1])*(b[1]-a[1])
}

// @lc code=end
