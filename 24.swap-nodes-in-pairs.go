/*
 * @lc app=leetcode id=24 lang=golang
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (46.52%)
 * Likes:    1437
 * Dislikes: 127
 * Total Accepted:    363.3K
 * Total Submissions: 779K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 *
 *
 * Example:
 *
 *
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
func swapPairs(head *ListNode) *ListNode {
	var res *ListNode = nil
	var pre *ListNode = nil

	p := head
	for p != nil && p.Next != nil {
		q := p.Next
		next := q.Next
		q.Next = p

		if pre != nil {
			pre.Next = q
		} else {
			res = q
		}

		pre = p
		p = next
	}
	if pre != nil {
		pre.Next = p
	} else {
		res = p
	}

	return res
}

// @lc code=end
