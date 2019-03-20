#include <stdio.h>
#include <stack>
#include <queue>

using namespace std;

class BT
{
  public:
    struct node
    {
        int data;
        struct node *left;
        struct node *right;
    };

  public:
    void preorder1(struct node *t)
    {
        if (t)
        {
            printf("%d\n", t->data);
            if (t->left)
                preorder1(t->left);
            if (t->right)
                preorder1(t->right);
        }
    }

    void preorder2(struct node *t)
    {
        stack<struct node *> s;
        struct node *p = t;
        while (p != NULL)
        {
            printf("%d\n", p->data);
            if (p->right != NULL)
                s.push(p->right);
            if (p->left != NULL)
                p = p->left;
            else
            {
                if (s.empty())
                    break;
                p = s.top();
                s.pop();
            }
        }
    }

    void inorder1(struct node *t)
    {
        if (t)
        {
            if (t->left)
                preorder1(t->left);
            printf("%d\n", t->data);
            if (t->right)
                preorder1(t->right);
        }
    }

    void inorder2(struct node *t)
    {
        stack<struct node *> s;
        struct node *p = t;
        do
        {
            while (p != NULL)
            {
                s.push(p);
                p->left;
            }

            if (!s.empty())
            {
                p = s.top();
                s.pop();
                printf("%d\n", t->data);
                p = p->right;
            }
        } while (p != NULL || !s.empty());
    }

    void postorder1(struct node *t)
    {
        if (t)
        {
            if (t->left)
                preorder1(t->left);
            if (t->right)
                preorder1(t->right);
            printf("%d\n", t->data);
        }
    }
    void postorder2(struct node *t)
    {
        stack<struct node *> s;
        if (!t)
            return;
        s.push(t);

        struct node *cur = NULL;
        struct node *pre = NULL;

        while (!is_empty(stack))
        {
            cur = s.top();
            if ((cur->left == NULL && cur->right == NULL) ||
                (pre != NULL && (cur->left == pre || cur->right == pre)))
            {
                printf("%d\n", cur->data);
                s.pop();
                pre = cur;
            }
            else
            {

                if (cur->right != NULL)
                    s.push(cur->right);
                if (cur->left != NULL)
                    s.push(cur->left);
            }
        }
    }

    void level(struct node *t) {  
        if (!t) {  
            return;  
        }  
        queue<struct node *> q;  
        q.push(t);  
        while (!q.empty()) {  
            struct node *p = queue.front();  
            q.pop();
            printf("%d\n", cur->data);
            if (p->left != null) {  
                q.push(p->left); 
            }  
            if (p->right != null) {  
                q.push(p->right); 
            }  
        }  
    }

  private:
    struct node *root;
};