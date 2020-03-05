/*
 * @lc app=leetcode id=1095 lang=golang
 *
 * [1095] Find in Mountain Array
 *
 * https://leetcode.com/problems/find-in-mountain-array/description/
 *
 * algorithms
 * Hard (34.35%)
 * Likes:    123
 * Dislikes: 15
 * Total Accepted:    5.2K
 * Total Submissions: 15K
 * Testcase Example:  '[1,2,3,4,5,3,1]\n3'
 *
 * (This problem is an interactive problem.)
 *
 * You may recall that an array A is a mountain array if and only if:
 *
 *
 * A.length >= 3
 * There exists some i with 0 < i < A.length - 1 such that:
 *
 * A[0] < A[1] < ... A[i-1] < A[i]
 * A[i] > A[i+1] > ... > A[A.length - 1]
 *
 *
 *
 *
 * Given a mountain array mountainArr, return the minimum index such that
 * mountainArr.get(index) == target.  If such an index doesn't exist, return
 * -1.
 *
 * You can't access the mountain array directly.  You may only access the array
 * using a MountainArray interface:
 *
 *
 * MountainArray.get(k) returns the element of the array at index k
 * (0-indexed).
 * MountainArray.length() returns the length of the array.
 *
 *
 * Submissions making more than 100 calls to MountainArray.get will be judged
 * Wrong Answer.  Also, any solutions that attempt to circumvent the judge will
 * result in disqualification.
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: array = [1,2,3,4,5,3,1], target = 3
 * Output: 2
 * Explanation: 3 exists in the array, at index=2 and index=5. Return the
 * minimum index, which is 2.
 *
 * Example 2:
 *
 *
 * Input: array = [0,1,2,4,2,1], target = 3
 * Output: -1
 * Explanation: 3 does not exist in the array, so we return -1.
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= mountain_arr.length() <= 10000
 * 0 <= target <= 10^9
 * 0 <= mountain_arr.get(index) <= 10^9
 *
 */

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * type MountainArray struct {
 * }
 *
 * func (this *MountainArray) get(index int) int {}
 * func (this *MountainArray) length() int {}
 */

// this is good, use it
//  class Solution {
// 	public:
// 		int findInMountainArray(int target, MountainArray& mountainArr) {
// 			int size = mountainArr.length();
// 			int peak = binarySearchPeak(1, size - 1, mountainArr);
// 			int ret = binarySearch(0, peak + 1, target, mountainArr, less<int>());
// 			if (ret == -1) ret = binarySearch(peak + 1, size, target, mountainArr, greater<int>());
// 			return ret;
// 		}

// 		int binarySearchPeak(int begin, int end, MountainArray& mountainArr) {
// 			int mid = 0;
// 			while (begin < end) {
// 				mid = ((begin + end) >> 1);
// 				int a = mountainArr.get(mid - 1);
// 				int b = mountainArr.get(mid);
// 				int c = mountainArr.get(mid + 1);
// 				if (a < b && b < c) begin = mid + 1;
// 				else if (a > b && b > c) end = mid;
// 				else break;
// 			}
// 			return mid;
// 		}

// 		template<class Comp>
// 		int binarySearch(int begin, int end, int target, MountainArray& mountainArr, Comp comp) {
// 			int mid = 0, midVal = 0;
// 			while (begin < end) {
// 				mid = ((begin + end) >> 1);
// 				midVal = mountainArr.get(mid);
// 				if (midVal == target) break;
// 				else if (comp(midVal, target)) begin = mid + 1;
// 				else end = mid;
// 			}
// 			return midVal == target ? mid : -1;
// 		}
// 	};
func findInMountainArray(target int, mountainArr *MountainArray) int {
	l1 := mountainArr.length()
	if l1 <= 0 {
		return -1
	}

	return findInMountainArray_(target, mountainArr, 0, l1-1)

}

func findInMountainArray_(target int, mountainArr *MountainArray, begin, end int) int {
	if end-begin <= 1 {
		if mountainArr.get(begin) == target {
			return begin
		}
		if begin != end && mountainArr.get(end) == target {
			return end
		}
		return -1
	}

	left := -1
	right := -1
	mid := (begin + end) >> 1

	midValue := mountainArr.get(mid)
	if midValue >= target {

		bValue := mountainArr.get(begin)
		if bValue <= target {
			left = findInMountainArray_(target, mountainArr, begin, mid)
			if left >= 0 {
				return left
			}
		}

		eValue := mountainArr.get(end)
		if eValue <= target {
			right = findInMountainArray_(target, mountainArr, mid, end)
		}
		return right
	}

	bValue := mountainArr.get(begin)
	eValue := mountainArr.get(end)

	if bValue >= midValue {
		left = findInMountainArray_(target, mountainArr, begin, mid)
		return left
	}
	if eValue >= midValue {
		right = findInMountainArray_(target, mountainArr, mid, end)
		return right
	}

	if bValue <= midValue && eValue <= midValue {
		left = findInMountainArray_(target, mountainArr, begin, mid)
		if left >= 0 {
			return left
		}
		right = findInMountainArray_(target, mountainArr, mid, end)
		return right
	}

	return right
}

// @lc code=end
