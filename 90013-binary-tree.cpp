#include <stack>
#include <queue>
#include <cstdlib>

// #include "binarytree.h"

#include <iostream>
#include <cstdio>
#include <string>
 
 
 using namespace std;
 
class binarytree
{
	public:
		typedef struct node {
				int key;
				struct node *left;
				struct node *right;
			} treenode;
		/* 回调函数 */
		typedef void (*callback_func)(void *data);
		
		binarytree();
		~binarytree();
		int bt_insert(int key);
 
		/* 非递归前序遍历 */
		void bt_preorder_norec(callback_func cb_func);
		/* 非递归中序遍历 */
		void bt_inorder_norec(callback_func cb_func);
		/* 非递归后序遍历 */
		void bt_postorder_norec(callback_func cb_func);
		/* 广度优先遍历 */
		void bt_levelorder(callback_func cb_func);
		/* 非递归后序遍历求树的高度 */
		int bt_depth_norec();
		/* 非递归广义优先遍历求树的高度 */
		int bt_depth_norec1(); 
		
		/* 递归前序遍历 */
		void bt_preorder_rec(callback_func cb_func) { __preorder_rec(root, cb_func);}
		/* 递归中序遍历 */
		void bt_inorder_rec(callback_func cb_func) { __inorder_rec(root, cb_func);}
		/* 递归后序遍历 */
		void bt_postorder_rec(callback_func cb_func) { __postorder_rec(root, cb_func);}
		/* 递归求树的高度 */
		int bt_depth_rec() { return __depth_rec(root);}
		
		/* 递归check树平衡性 */
		int bt_isbalanced_rec() { return __isbalanced_rec(root);}
		
		/* 递归求叶节点数目 */
		int bt_leafnum_rec() { return __leafnum_rec(root);}
		
 
		
	private:
		void __preorder_rec(treenode *root, callback_func cb_func);
		void __inorder_rec(treenode *root, callback_func cb_func);
		void __postorder_rec(treenode *root, callback_func cb_func);
		int __depth_rec(treenode *root);
		int __isbalanced_rec(treenode *root);
		int __leafnum_rec(treenode *root);
		
		treenode *do_lookup(int key, treenode **res);
		treenode *root;
		int nodenum;
};


binarytree::binarytree():root(NULL), nodenum(0)
{
 
}
 
binarytree::~binarytree()
{
	bt_postorder_norec(free);
}
 
binarytree::treenode *binarytree::do_lookup(int key, treenode **res)
{
	treenode *node = root;
	*res = NULL;
	
	while (node) {
		*res = node;
		if (key == node->key)
			return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	
	return NULL;
}
 
int binarytree::bt_insert(int key)
{
	treenode *node;
	treenode *add;
	
	if (do_lookup(key, &node))
		return -1;
	
	add = (treenode *)malloc(sizeof(treenode));
	if (!add)
		return -1;
	
	add->key = key;
	add->left = NULL;
	add->right = NULL;
	
	nodenum++;
	
	if (!root) {
		root = add;
		return 0;
	}
	
	if (key < node->key)
		node->left = add;
	else
		node->right = add;
	
	return 0;	
}
 
void binarytree::__preorder_rec(treenode *root, callback_func cb_func)
{
	if (root) {
		cb_func(root);
		__preorder_rec(root->left, cb_func);
		__preorder_rec(root->right, cb_func);
	}
}
 
 
void binarytree::__inorder_rec(treenode *root, callback_func cb_func)
{
	if (root) {	
		__inorder_rec(root->left, cb_func);
		cb_func(root);
		__inorder_rec(root->right, cb_func);
	}
}
 
 
 
void binarytree::__postorder_rec(treenode *root, callback_func cb_func)
{
	if (root) {
		__postorder_rec(root->left, cb_func);
		__postorder_rec(root->right, cb_func);
		cb_func(root);
	}
}
 
void binarytree::bt_preorder_norec(callback_func cb_func)
{
	treenode *node = root;
	stack<treenode *> st;
	
	while (node || !st.empty()) {
		if (node) {
			cb_func(node);
			st.push(node);
			node = node->left;
		}
		else {
			node = st.top()->right;
			st.pop();
		}
	}
}
 
void binarytree::bt_inorder_norec(callback_func cb_func)
{
	treenode *node = root;
	stack<treenode *> st;
	
	while (node || !st.empty()) {
		if (node) {
			st.push(node);
			node = node->left;
		}
		else {
			cb_func(st.top());
			node = st.top()->right;
			st.pop();
		}
	}
}
 
void binarytree::bt_postorder_norec(callback_func cb_func)
{
	treenode *node = root, *visited = NULL;
	stack<treenode *> st;
	
	while (node || !st.empty()) {
		if (node) {
			st.push(node);
			node = node->left;
		}
		else {
			node = st.top();
			if (node->right && node->right != visited)
				node = node->right;
			else {
				cb_func(node);
				visited = node;
				node = NULL;
				st.pop();
			}
			
		}
	}
}
 
void binarytree::bt_levelorder(callback_func cb_func)
{
	queue<treenode *> qu;
	
	if (root)
		qu.push(root);
	
	while (!qu.empty()) {
		cb_func(qu.front());
		if (qu.front()->left)
			qu.push(qu.front()->left);
		if (qu.front()->right)
			qu.push(qu.front()->right);
		
		qu.pop();
	}
}
 
int binarytree::__depth_rec(treenode *root) 
{
	if (!root)
		return 0;
	
	return max(__depth_rec(root->left), __depth_rec(root->right)) + 1;
}
 
int binarytree::bt_depth_norec() 
{
	treenode *node = root, *visited = NULL;
	stack<treenode *> st;
	int depth = 0;
	
	while (node || !st.empty()) {
		if (node) {
			st.push(node);
			node = node->left;
			depth = depth >= (int)st.size() ? depth : st.size();
		}
		else {
			node = st.top();
			if (node->right && node->right != visited)
				node = node->right;
			else {
				visited = node;
				node = NULL;
				st.pop();			
			}
			
		}
	}
	
	return depth;
 
}
 
int binarytree::bt_depth_norec1() 
{
	int depth = 0, tmp = 1, lc = 1;
	queue<treenode *> qu;
	
	if (root)
		qu.push(root);
	
	while (!qu.empty()) {
		if (qu.front()->left) {
			qu.push(qu.front()->left);
		}
		else
			tmp--;
			
		if (qu.front()->right) {
			qu.push(qu.front()->right);
			tmp++;
		}
		
		qu.pop();
		
		if (--lc == 0) {
			depth++;
			lc = tmp;
		}
	}
	
	return depth;
 
}
 
int binarytree::__isbalanced_rec(treenode *root)
{
	int depthl, depthr;
	if (!root)
		return 1;
		
	depthl = __depth_rec(root->left);
	depthr = __depth_rec(root->right);
	
	if (depthl - depthr > 1 || depthl - depthr < -1)
		return 0;
		
	return __isbalanced_rec(root->left) && __isbalanced_rec(root->right);
}
 
int binarytree::__leafnum_rec(treenode *root)
{
	if (!root)
		return 0;
	if (!(root->left) && !(root->right))
		return 1;
		
	return __leafnum_rec(root->left) + __leafnum_rec(root->right);
}
 
void print(void* node)
{
 
	printf("%d ", ((binarytree::treenode *)node)->key);
}
 
 
 
int main(int argc, char ** argv)
{
	binarytree tree;
	
	for (int i = 1; i < argc; i++) {
			tree.bt_insert(atoi(argv[i]));
	}
	
	printf("bt_preorder_norec\n");
	tree.bt_preorder_norec(print);
	printf("\nbt_inorder_norec\n");
	tree.bt_inorder_norec(print);
	printf("\nbt_postorder_norec\n");
	tree.bt_postorder_norec(print);
	
	printf("\nbt_preorder_rec\n");
	tree.bt_preorder_rec(print);
	printf("\nbt_inorder_rec\n");
	tree.bt_inorder_rec(print);
	printf("\nbt_postorder_rec\n");
	tree.bt_postorder_rec(print);
	
	printf("\nbt_levelorder\n");
	tree.bt_levelorder(print);
	
	printf("\nbt_depth_rec: %d\n", tree.bt_depth_rec());
	printf("bt_depth_norec: %d\n", tree.bt_depth_norec());
	printf("bt_depth_norec1: %d\n", tree.bt_depth_norec1());
	
	printf("bt_isbalanced_rec: %d\n", tree.bt_isbalanced_rec());
	printf("bt_leafnum_rec: %d\n", tree.bt_leafnum_rec());
	
	
	return 0;
}
