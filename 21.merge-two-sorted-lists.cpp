/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (49.13%)
 * Likes:    2695
 * Dislikes: 392
 * Total Accepted:    696.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
   ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
            
        ListNode *r = NULL, *p = NULL;
        while (l1 && l2) {
            ListNode *t = NULL;
            if (l1->val <= l2->val) {
                t = l1;
                l1 = l1->next;
            } else {
                t = l2;
                l2 = l2->next;
            }
            if (!r) {
                r = t;
                p = r;
            } else {
                p->next = t;
                p = p->next;
            }
        }
        if (l1) {
            p->next = l1;
        } else {
            p->next = l2;
        }
        return r;
    }
};

