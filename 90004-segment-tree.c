// 桌子上零散地放着若干个盒子，桌子的后方是一堵墙。
// 现在从桌子前射来一束平行光， 把盒子的影子投射到了墙上。问影子的总宽度是多少？
// 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Node
{
	int lvalue, rvalue;
	int data;
	struct Node *lchild;
	struct Node *rchild;	
} Node;
 
Node  *Build(int l, int r)
{
	Node *root;
 
	if (l >= r)
		return NULL;
		
	root = (Node *)calloc(1, sizeof(Node));
	root->lvalue = l;
	root->rvalue = r;
	root->data = 0;
	root->lchild = NULL;
	root->rchild = NULL;
 
	if (l + 1 < r) {
		int  mid = (l + r) >> 1;
		root->lchild = Build(l , mid) ;
		root->rchild = Build(mid , r) ; 
	} 
 
	return root; 
}
 
void  Insert(Node *root, int c, int d)
{
	if (!root)
		return;
		
	if(c <= root->lvalue && d >= root->rvalue) 
		root->data++;
	else {
		int mid = (root->lvalue + root->rvalue) >> 1;
		if (d <= mid) 
			Insert(root->lchild, c, d);
		else if(c >= mid) 
			Insert(root->rchild, c, d);
		else {
			Insert(root->lchild, c, mid);
			Insert(root->rchild, mid, d);
		}
	}
} 
 
 
 
void  Delete(Node *root, int c, int d)
{
	if (!root)
		return;
		
	if (c <= root->lvalue && d >= root->rvalue) 
		root->data--;
	else 
	{
		int mid = (root->lvalue + root->rvalue) >> 1;
		if (d <= mid) 
			Delete(root->lchild, c, d);
		else if(c >= mid) 
			Delete(root->rchild, c, d);
		else {
			Delete(root->lchild, c, mid);
			Delete(root->rchild, mid, d);
		}
	}
} 
 
void Find(Node *root,int a,int b, int *count)  
{  
	int mid;
	
	if (!root)
		return;

	if (a >= b) {
		return;
	}

	if (a >= root->rvalue || b <= root->lvalue) {
		return;
	}
	
	if(root->data > 0) {
		int rMin = root->rvalue <= b ? root->rvalue : b;
		int lMax = root->lvalue >= a ? root->lvalue : a;
		*count += (rMin - lMax);  
		return;  
	}
	
	mid = (root->lvalue + root->rvalue) >> 1;  
	if(b <= mid)   
		Find(root->lchild, a, b, count);  
	else if(a >= mid)   
		Find(root->rchild,a, b, count);	
	else {  
		Find(root->lchild, a, mid, count);  
		Find(root->rchild, mid, b, count);  
	}  
}
 
int value[][2] = {
		{1, 7},
		{8, 17},
		{15, 23},
		{34, 40},
		{38, 42},
		{36, 41}
	};
	
int main()
{
	int count = 0;
	int i;
	
	Node *root = Build(3, 101);
	
	for (i = 0; i < sizeof(value) / sizeof(value[0]); i++)
		Insert(root, value[i][0], value[i][1]);
		
	Find(root, 4, 50, &count);
	printf("count: %d\n", count);
	
	Delete(root, 36, 41);
	
	count = 0;
	Find(root, 4, 50, &count);
	printf("count: %d\n", count);
	
	Delete(root, 38, 42);
	
	count = 0;
	Find(root, 4, 50, &count);
	printf("count: %d\n", count);
	
	return 0;
}
