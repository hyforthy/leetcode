/*
 * @lc app=leetcode id=19 lang=golang
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.61%)
 * Likes:    2198
 * Dislikes: 162
 * Total Accepted:    461.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 *
 * Example:
 *
 *
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 *
 *
 * Note:
 *
 * Given n will always be valid.
 *
 * Follow up:
 *
 * Could you do this in one pass?
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
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if head == nil {
		return nil
	}

	if n <= 0 {
		return head
	}
	p := head
	for n > 0 && p.Next != nil {
		p = p.Next
		n--
	}

	if n == 1 {
		head = head.Next
		return head
	}

	if n > 1 {
		return head
	}

	pre := head

	for p.Next != nil {
		pre = pre.Next
		p = p.Next
	}

	pre.Next = pre.Next.Next

	return head
}

// @lc code=end
