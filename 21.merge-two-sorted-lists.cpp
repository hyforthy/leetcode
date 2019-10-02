/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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

