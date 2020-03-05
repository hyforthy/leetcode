import "sort"

/*
 * @lc app=leetcode id=31 lang=golang
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (31.12%)
 * Likes:    2262
 * Dislikes: 736
 * Total Accepted:    280.1K
 * Total Submissions: 898.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place and use only constant extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 *
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 */

// @lc code=start
func nextPermutation(nums []int) {
	l1 := len(nums)
	if l1 <= 0 {
		return
	}

	pos := l1 - 1
	for pos > 0 {
		if nums[pos] > nums[pos-1] {
			break
		}
		pos--
	}

	if pos == 0 {
		sort.Ints(nums)
		// fmt.Println(nums)
		return
	}

	t := nums[pos-1]
	work := nums[pos-1:]
	sort.Ints(work)

	insert := sort.SearchInts(work, t+1)
	tmp := work[insert]
	for i := insert; i > 0; i-- {
		work[i] = work[i-1]
	}
	work[0] = tmp
	// fmt.Println(nums)
}

// class Solution {
// 	public:
// 		void nextPermutation(vector<int>& nums) {
// 			int n = nums.size(), k, l;
// 			for (k = n - 2; k >= 0; k--) {
// 				if (nums[k] < nums[k + 1]) {
// 					break;
// 				}
// 			}
// 			if (k < 0) {
// 				reverse(nums.begin(), nums.end());
// 			} else {
// 				for (l = n - 1; l > k; l--) {
// 					if (nums[l] > nums[k]) {
// 						break;
// 					}
// 				}
// 				swap(nums[k], nums[l]);
// 				reverse(nums.begin() + k + 1, nums.end());
// 			}
// 		}
// 	};

// @lc code=end
