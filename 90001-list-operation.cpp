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


    private:
        struct node * head;
}