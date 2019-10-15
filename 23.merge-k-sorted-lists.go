/*
 * @lc app=leetcode id=23 lang=golang
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (36.28%)
 * Likes:    3034
 * Dislikes: 201
 * Total Accepted:    465.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 *
 * Example:
 *
 *
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeKLists(lists []*ListNode) *ListNode {
	l1 := len(lists)

	var res *ListNode = nil
	var p *ListNode = nil

	for {
		pos := -1
		for i := 0; i < l1; i++ {
			if lists[i] == nil {
				continue
			}
			if pos == -1 {
				pos = i
				continue
			}
			if lists[i].Val < lists[pos].Val {
				pos = i
			}
		}

		if pos == -1 {
			break
		}

		if res == nil {
			res = lists[pos]
			p = res
		} else {
			p.Next = lists[pos]
			p = p.Next
		}

		lists[pos] = lists[pos].Next
	}

	return res
}

// @lc code=end

