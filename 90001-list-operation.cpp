#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

class LO {
    public:
        struct node * circleMeetingPoint(struct node *head) {
            struct node *slow = head;
            struct node *fast = head;

            while(fast && fask->next) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast)
                    break;
            }

            if (fast == NULL || fast->next == NULL) {
                return NULL;
            }

            return slow;
        }

        bool isCircle(struct node *head) {
            return (circleMeetingPoint(head) != NULL);
        }

        /* the list can not be circle*/
        struct node *reverse(struct node *head) {
            struct node *pre = NULL;
            struct node *cur = head;

            while(cur) {
                struct node *t = cur->next;
                cur->next = pre;
                pre = cur;
                cur = t;
            }

            return pre;
        }

        /* 找倒数第d个节点 */
        struct node * distanceNodeToEnd(struct node *head, int d) {
            struct node * slow = head;
            struct node * fast = head;

            while(d > 1 && fast) {
                fast = fast->next;
                d--;
            }

            if (!fast)
                return NULL;
            
            while (fast->next) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }

        // 2个链表的第一个公共节点
        struct node * firstmeetingNode(struct node *head1, struct node *head2) {
            int l1 = 0;
            int l2 = 0;

            struct node *n1 = head1;
            while (n1) {
                l1++;
                n1 = n1->next;
            }

            struct node *n2 = head2;
            while (n2) {
                l2++;
                n2 = n2->next;
            }

            n1 = head1;
            n2 = head2;
            while (l1 < l2) {
                n2 = n2->next;
                l2--;
            }

            while (l2 < l1) {
                n1 = n2->next;
                l1--;
            }

            while (n1 && n2) {
                if (n1 == n2) {
                    return n1;
                }
                n1 = n1->next;
                n2 = n2->next;
            }
            return NULL;
        }

    private:
        struct node * head;
}