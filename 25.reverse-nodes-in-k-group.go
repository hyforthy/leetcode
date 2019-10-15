/*
 * @lc app=leetcode id=25 lang=golang
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (38.06%)
 * Likes:    1434
 * Dislikes: 288
 * Total Accepted:    210.2K
 * Total Submissions: 551K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 *
 *
 *
 *
 * Example:
 *
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 *
 * Note:
 *
 *
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
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
func reverseKGroup(head *ListNode, k int) *ListNode {
	if k <= 1 {
		return head
	}

	var res *ListNode = nil
	var pre *ListNode = nil

	p := head

	for {
		start := p
		pos := 0
		for pos < k && start != nil {
			start = start.Next
			pos++
		}

		if pos < k {
			if res == nil {
				res = p
			}
			if pre != nil {
				pre.Next = p
			}
			break
		}

		start = p
		nxt := start.Next

		for pos = 1; pos < k && nxt != nil; pos++ {
			t := nxt.Next
			nxt.Next = start
			start = nxt
			nxt = t
		}

		if res == nil {
			res = start
		}
		if pre != nil {
			pre.Next = start
		}
		pre = p
		p = nxt
	}
	return res
}

// @lc code=end

