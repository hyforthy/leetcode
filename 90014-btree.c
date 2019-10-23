#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
 
// #include "btree.h"  
 
 /*
 * 实现BTree的创建、插入、删除、查找、销毁操作
 *
 */
 
#ifndef __BTREE_H__  
#define __BTREE_H__  
  
#ifdef __cplusplus  
extern "C" {  
#endif   
  
typedef int KeyType;  
typedef struct BTNode BTNode;
typedef struct BTree BTree;  
 
// 创建BTree，n为内结点最少的孩子数，n必须大于等于2 
BTree *BTreeCreate(int n);  
   
// BTree的插入操作    
int BTreeInsert(BTree *tree, KeyType key);  
 
// BTree的删除操作  
int BTreeRemove(BTree *tree, KeyType key);  
 
// 深度遍历BTree  
void BTreeTraverse(const BTree *tree);  
  
// BTree的查找操作，返回key所在节点指针，pos保存key所在节点内的位置
BTNode *BTreeSearch(const BTree *tree, int key, int *pos); 
 
// 销毁BTree
void BTreeDestroy(BTree *tree);   
 
      
#ifdef __cplusplus  
}  
#endif  
 
  
#endif  



 
// BTree的结点
struct BTNode {  
	int nkey;                             /// 结点中关键字数  
	KeyType *key;              			  /// 关键字向量  
	struct BTNode **child;                /// 孩子指针向量  
	char leaf;                            /// 是否为叶子节点  
};
 
struct BTree {
	BTNode *root;                         /// 根结点
	int mindegree;                        /// 内结点的最小孩子数
};
 
// 分配结点空间, degree为内结点的最小孩子数
BTNode *NewNode(int degree)
{
	BTNode *node = (BTNode*)calloc(1, sizeof(BTNode));  
    if (!node) 
        return NULL;
		
	node->key = (KeyType *)calloc((degree << 1) - 1, sizeof(KeyType));
	if (!(node->key)) {
		free(node);
		return NULL;
	}
	
	node->child = (BTNode **)calloc((degree << 1), sizeof(BTNode *));
	if (!(node->child)) {
		free(node->key);
		free(node);
		return NULL;
	}
	
	node->leaf = 1;
	
	return node;
}
 
void FreeNode(BTNode *node)
{
	if (!node)
		return;
	
	if (node->key)
		free(node->key);
	if (node->child)
		free(node->child);
	
	free(node);
}
  
// 向磁盘写入结点  
void DiskWrite(BTNode *node)  
{ 
	printf("Write to btree:\n");
    for(int i = 0; i < node->nkey; i++){  
        printf("%d ",node->key[i]);  
    }  
    printf("\n");  
}  
  
// 从磁盘读取结点  
void DiskRead(BTNode *node)  
{
    printf("Read from btree:\n");  
    for(int i = 0;i < node->nkey; i++){  
        printf("%d ", node->key[i]);  
    }  
    printf("\n");  
}  
 
BTree *BTreeCreate(int n)  
{   
	BTree *tree;
	
	if (n < 2)
		return NULL;
		
	tree = (BTree *)calloc(1, sizeof(BTree));
	if (!tree)
		return NULL;
	tree->mindegree = n;
	
	tree->root = NewNode(n);
	if (!(tree->root)) {
		free(tree);
		return NULL;
	}
	//--DiskWrite(tree->root);
	return tree;	
} 
 
void BTreeTraverse_(const BTNode *node, int layer)
{
	if (!node)
		return;
		
	printf("Layrer: %d\n", layer);
	
	for (int i = 0; i < node->nkey; i++)
		printf("%d ", node->key[i]);
	printf("\n");
	
	for (int i = 0; i <= node->nkey; i++)
		BTreeTraverse_(node->child[i], layer + 1);
}
 
void BTreeTraverse(const BTree *tree)  
{  
	BTNode *node;
	if (!tree)
		return;
	node = tree->root;
	BTreeTraverse_(node, 0);
}  
  
// 二分查找，找到第一个大于或等于key的关键字所在位置  
int BinarySearch(const BTNode *node, int low, int high, KeyType key)  
{  
    int mid;
	
	if (low > high)
		return -1;
		
    while (low <= high) {  
        mid = (low + high) / 2;
		
        if (key > node->key[mid])
			low = mid + 1;       
        else
			high = mid - 1;
            
    }
	
    return low;  
}  
 
 
// 对满结点node进行分裂，parent为node的父结点且为非满结点，
// index为node在parent中的ID  
void BTreeSplitChild(BTNode *parent, int index, BTNode *node, int degree)  
{  
	int pos;  
  
	// 新结点用于保存node分裂出的key和指针
    BTNode* newnode = NewNode(degree); 
    if (!newnode) 
        return;
  
    newnode->leaf = node->leaf;  
    newnode->nkey = degree - 1;  /// 新结点key的最少数量
	
	// node中pos及其后的key值复制到新结点中
	pos = node->nkey - newnode->nkey; 
    for (int i = 0; i < newnode->nkey; ++i){  
        newnode->key[i] = node->key[pos + i];  
        node->key[pos + i] = 0;  
    }  
  
	// node若为非叶子结点，则把pos及其后的孩子指针复制到新结点中
    if (!node->leaf) {  
        for (int i = 0; i <= newnode->nkey; i++) {  
            newnode->child[i] = node->child[pos + i];  
            node->child[pos + i] = NULL;  
        }  
    }  
  
    for (int i = parent->nkey; i > index; --i) {  
        parent->child[i + 1] = parent->child[i];  
    }  
  
    parent->child[index + 1] = newnode;  
  
    for (int i = parent->nkey - 1; i >= index; --i) {  
        parent->key[i + 1] = parent->key[i];  
    }  
  
    parent->key[index] = node->key[pos - 1];
	node->key[pos - 1] = 0;
    ++parent->nkey;
	node->nkey = pos - 1;
  
    // 写入磁盘  
     //--DiskWrite(parent);  
     //--DiskWrite(newnode);  
     //--DiskWrite(node);  
}  
 
// 向未满的结点node中插入key
int BTreeInsertNonfull(BTNode* node, KeyType key, int degree)  
{  
	int pos;
	
	pos = BinarySearch(node, 0, node->nkey - 1, key);
	if (pos >= 0 && pos < node->nkey && node->key[pos] == key)
		return -1;
		
	pos = pos >= 0 ? pos : 0;
	
	// node为叶子结点则直接插入
	if (node->leaf) {  		
		
		for (int i = node->nkey - 1; i >= pos; i--)  
			node->key[i + 1] = node->key[i]; 
 
		
		node->key[pos] = key;  
		++node->nkey; 
		//--DiskWrite(node); 
	
		return 0;
	}  	
	
	// 从磁盘读取孩子节点  
	//--DiskRead(node->child[pos]);  
	
	// 对满孩子结点进行分裂操作  
	if (node->child[pos]->nkey == ((degree << 1) - 1)) {  
		BTreeSplitChild(node, pos, node->child[pos], degree);    
		if (key > node->key[pos])
			++pos;    
	}
	
	return BTreeInsertNonfull(node->child[pos], key, degree);   
}  
  
int BTreeInsert(BTree *tree, KeyType key)  
{ 
	BTNode *node;  
    BTNode *root;
	int degree;
 
	if (!tree)
		return -1;
		
	root = tree->root;
    if (!root)
		return -1;
 
	degree = tree->mindegree;
	
    // 根结点未满  
    if (root->nkey < (degree << 1) - 1)
		return BTreeInsertNonfull(root, key, degree);  
 
    
	node = NewNode(degree);  
    if (!node) 
        return -1;
  
    tree->root = node;  
    node->leaf = 0;  
    node->nkey = 0;  
    node->child[0] = root;  
  
    BTreeSplitChild(node, 0, root, degree);  
    return BTreeInsertNonfull(node, key, degree);  
}  
 
// 合并结点rchild到lchild，同时将parent中id为index的key下移到lchild中
// lchild和rchild的key数均为degree - 1
void BTreeMergeChild(BTNode *parent, int index, BTNode *lchild, BTNode *rchild, int degree)  
{  	   
	lchild->nkey = (degree << 1) - 1;
	
	lchild->key[degree - 1] = parent->key[index];
	for (int i = 0; i < degree - 1; i++)
		lchild->key[i + degree] = rchild->key[i];
		
	if (!(lchild->leaf)) {
		for (int i = 0; i < degree; i++)
			lchild->child[i + degree] = rchild->child[i];
	}
	
	for (int i = index + 1; i < parent->nkey; i++) {
		parent->key[i - 1] = parent->key[i];
		parent->child[i] = parent->child[i + 1];
	}
	parent->nkey--;
	
	FreeNode(rchild);
	
	//--DiskWrite(parent);
	//--DiskWrite(lchild);	
} 
 
// 查找前驱
BTNode *BTreeSearchPredecessor(BTNode *node)
{
	while (!(node->leaf))
		node = node->child[node->nkey];
	
	return node;
}
 
// 查找后继
BTNode *BTreeSearchSuccessor(BTNode *node)
{
	while(!(node->leaf))
		node = node->child[0];
		
	return node;
}
 
// lchild中最后一个key上移到parent，parent中的id为index的key下移到rchild
void BTreeShiftToRightChild(BTNode *parent, int index, BTNode *lchild, BTNode *rchild)
{
 
	for (int i = rchild->nkey; i > 0; i--) 
		rchild->key[i] = rchild->key[i - 1];
		
	rchild->key[0] = parent->key[index];
	parent->key[index] = lchild->key[lchild->nkey - 1];
 
	if (!(lchild->leaf)) {
		for (int i = rchild->nkey + 1; i > 0; i--) 
			rchild->child[i] = rchild->child[i - 1];
		rchild->child[0] = lchild->child[lchild->nkey];
	}
 
	lchild->nkey--;
	rchild->nkey++;
	
	//--DiskWrite(parent);
	//--DiskWrite(lchild);
	//--DiskWrite(rchild);
}
 
// rchild中第一个key上移到parent，parent中的id为index的key下移到lchild
void BTreeShiftToLeftChild(BTNode *parent, int index, BTNode *lchild, BTNode *rchild)
{
	lchild->key[lchild->nkey] = parent->key[index];
	parent->key[index] = rchild->key[0];
 
	for (int i = 0; i < rchild->nkey - 1; i++) 
		rchild->key[i] = rchild->key[i + 1];
		
	if (!(rchild->leaf)){
		lchild->child[lchild->nkey + 1] = rchild->child[0];
		for (int i = 0; i < rchild->nkey; i++)
			rchild->child[i] = rchild->child[i + 1];
	}
	lchild->nkey++;
	rchild->nkey--;
	
	//--DiskWrite(parent);
	//--DiskWrite(lchild);
	//--DiskWrite(rchild);
}
 
int BTreeDeleteNotNone(BTNode *node, KeyType key, int degree)
{
	int pos, kps;
	BTNode *nps, *lchild = NULL, *mchild = NULL, *rchild = NULL;
	
	pos = BinarySearch(node, 0, node->nkey - 1, key);
	pos = pos >= 0 ? pos : 0;
 
	if (node->leaf) {
		// key不存在
		if (pos >= node->nkey || key < node->key[pos])
			return -1;
		
		// 1、node为叶结点且在其中找到key
		for (int i = pos; i < node->nkey - 1; i++)
			node->key[i] = node->key[i + 1];
		
		node->nkey--;
		//--DiskWrite(node);
		return 0;
	}
	
	mchild = node->child[pos];
	//--DiskRead(mchild);
	
	if (pos < node->nkey) {
		rchild = node->child[pos + 1];
		//--DiskRead(rchild);
	}
	
	// 2、node为非叶结点且在其中找到key
	if (pos < node->nkey && key == node->key[pos]) {
		// 2a
		if (mchild->nkey >= degree) {
			nps = BTreeSearchPredecessor(mchild);
			kps = nps->key[nps->nkey - 1];
			node->key[pos] = kps;
			return BTreeDeleteNotNone(mchild, kps, degree);
		}
		// 2b
		else if (rchild->nkey >= degree) {
			nps = BTreeSearchSuccessor(rchild);
			kps = nps->key[0];
			node->key[pos] = kps;
			return BTreeDeleteNotNone(mchild, kps, degree);
		}
		// 2c
		else {
			BTreeMergeChild(node, pos, mchild, rchild, degree);
			return BTreeDeleteNotNone(mchild, key, degree);
		}
	}
	else {
		if (pos > 0) {
			lchild = node->child[pos - 1];
			//--DiskRead(lchild);
		}
		
		// 3、node为非叶结点且未找到key，且key所在的子树的根结点key数为degree - 1
		if (mchild->nkey == degree - 1) {
			// 3a
			if (lchild && lchild->nkey >= degree) {
				BTreeShiftToRightChild(node, pos - 1, lchild, mchild);
			}
			// 3a
			else if (rchild && rchild->nkey >= degree) {
				BTreeShiftToLeftChild(node, pos, mchild, rchild);
			}
			// 3b
			else if (pos > 0){
				BTreeMergeChild(node, pos - 1, lchild, mchild, degree);
				mchild = lchild;
			}
			// 3b
			else {
				BTreeMergeChild(node, pos, mchild, rchild, degree);
			}
		}
		
		return BTreeDeleteNotNone(mchild, key, degree);
	}
}
int BTreeRemove(BTree *tree, KeyType key)  
{  
	BTNode *root;
	int degree;
		
	if (!tree)
		return -1;
		
	root = tree->root;
 
    if (tree == NULL)  
        return -1;  
		
	degree = tree->mindegree;
	
	if (root->nkey == 1 && !(root->leaf)) {
		BTNode *lchild, *rchild;
		lchild = root->child[0];
		rchild = root->child[1];
		
		//--DiskRead(root->child[0]);
		//--DiskRead(root->child[1]);
		
		if (lchild->nkey == degree - 1 && rchild->nkey == degree - 1) {
			BTreeMergeChild(root, 0, lchild, rchild, degree);
			FreeNode(root);
			tree->root = lchild;
			return BTreeDeleteNotNone(lchild, key, degree);
		}
		
	}
 
	return BTreeDeleteNotNone(root, key, degree);
}   
  
BTNode* BTreeRecursiveSearch(const BTNode *node, KeyType key, int *pos)  
{  
    int index;  
  
	index = BinarySearch(node, 0, node->nkey - 1, key);
	if (index < 0)
		return NULL;
  
    // 找到key
    if (index < node->nkey && node->key[index] == key) {  
        *pos = index;  
        return (BTNode *)node;  
    }  
  
    // 已经是叶子结点，未找到  
    if (node->leaf)
        return NULL;  
  
    //--DiskRead(node->child[index]);  
 
    return BTreeRecursiveSearch(node->child[index], key, pos);  
}  
  
BTNode* BTreeSearch(const BTree *tree, KeyType key, int *pos)  
{  
	BTNode *node;
 
    if (!tree)
        return NULL;  
	node = tree->root;
	
	if (!node)
		return NULL;
	//--DiskRead(node);
	
    *pos = -1;  
    return BTreeRecursiveSearch(node, key, pos);  
}   
 
void BTreeDestroy_(BTNode *node)
{
	if (!node)
		return;
		
	for (int i = 0; i <= node->nkey; i++) {  
		BTreeDestroy_(node->child[i]);  
	}
	
	FreeNode(node);
}
 
void BTreeDestroy(BTree *tree)  
{
	if (!tree)
		return;
		
	BTreeDestroy_(tree->root);  
} 
 
int main()
{
	int pos;
	BTNode *node;
	BTree *tree = BTreeCreate(2);
	
	for (int i = 0; i < 10; i++)
		BTreeInsert(tree, i);
	printf("-------------------BTreeTraverse-------------------\n");
	BTreeTraverse(tree);
	printf("---------------------------------------------------\n\n\n");
	
	for (int i = 19; i >= 10; i--)
		BTreeInsert(tree, i);
	printf("-------------------BTreeTraverse-------------------\n");
	BTreeTraverse(tree);
	printf("---------------------------------------------------\n\n\n");
	
	for (int i = 10; i <= 15; i++)
		BTreeInsert(tree, i);
	printf("-------------------BTreeTraverse-------------------\n");	
	BTreeTraverse(tree);
	printf("---------------------------------------------------\n\n\n");
	
	printf("-------------------BTreeSearch---------------------\n");
	node = BTreeSearch(tree, 15, &pos);
	printf("%d\n", node ? node->key[pos] : -1);
	printf("---------------------------------------------------\n\n\n");
	
	for (int i = 6; i <= 15; i++) {
		BTreeRemove(tree, i);
		printf("-------------------BTreeRemove--BTreeTraverse-------------------\n");	
		BTreeTraverse(tree);
		printf("\n\n\n");
	}
	
	printf("-------------------BTreeSearch---------------------\n");
	node = BTreeSearch(tree, 15, &pos);
	printf("%d\n", node ? node->key[pos] : -1);
	printf("---------------------------------------------------\n\n\n");
	
	BTreeDestroy(tree);
	
	return 0;

}