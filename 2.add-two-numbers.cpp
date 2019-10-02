/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
*
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.89%)
 * Likes:    6065
 * Dislikes: 1582
 * Total Accepted:    1M
 * Total Submissions: 3.3M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL;
        ListNode *prev = NULL;

        int remain = 0;
        int r = 0;

        while (l1 || l2)
        {
            ListNode *n = new ListNode(0);

            if (l1 == NULL)
            {
                r = l2->val;
                l2 = l2->next;
            }
            else if (l2 == NULL)
            {
                r = l1->val;
                l1 = l1->next;
            }
            else
            {
                r = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }

            r = r + remain;
            n->val = r % 10;
            remain = r / 10;

            if (head == NULL)
            {
                head = n;
                prev = n;
            }
            else
            {
                prev->next = n;
                prev = n;
            }
        }

        if (remain > 0)
        {
            ListNode *n = new ListNode(0);
            n->val = remain;
            prev->next = n;
        }

        return head;
    }
};
// @lc code=end
