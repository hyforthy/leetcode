#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue> 
using namespace std; 
 
class TrieTree {  
#define NUM (52) 
struct trienode {  
	char flag;            // 从根到该节点构成单词的标志
	int count;            // 包含该节点的单词数量
	trienode *next[NUM];  // Trie每个节点含52个孩子
	trienode() {          // 构造函数
		flag = 0; 
		count= 0;		
		memset(next, 0, sizeof(next)); 
	} 
};
 
public:
	TrieTree();
	~TrieTree();
	bool Insert(const char *word);
	bool Search(const char *word);
	bool Delete(const char *word);
	
private:
	void TrieDestroy_(trienode *p)
	{
		if (!p)
		return;
 
		for (int i = 0; i < NUM; i++) {
			if (p->next[i])
				TrieDestroy_(p->next[i]); 
		}
	
		delete p;
	}
	
	void Delete_(trienode *p, const char *word)
	{
		if (!p || !(*word))
			return;
		
		Delete_(p->next[Index_(*word)], word + 1);
		
		delete p;
	}
	
	int Index_(char ch)
	{
		if (ch >= 'A' && ch <= 'Z')
			return ch - 'A';
		if (ch >= 'a' && ch <= 'z')
			return ch - 'a';
		return -1;
	}
	
private:	
	trienode *root;
 
};
 
TrieTree::TrieTree()
{
	root = new trienode();
}
 
 
TrieTree::~TrieTree()
{
	TrieDestroy_(root);
}
 
bool TrieTree::Insert(const char *word)
{
	char ch;
    trienode *p = root; 
  
    while((ch = *word++)){ 
        int index = Index_(ch);
		if (index < 0)
			return false;
			
        if(p->next[index] == NULL) 
			p->next[index]= new trienode();  
        p = p->next[index];
		p->count++;
    } 
	
    p->flag = 1;
	return true;
}
 
bool TrieTree::Search(const char *word)
{
	char ch;
	trienode *p = root;
		
	while ((ch = *word++)) {
		int index = Index_(ch);
		if (index < 0)
			return false;
			
		if (p->next[index] == NULL)
			return false;
			
		p = p->next[index];
	}
	
	if (p->flag)
		return true;
	return false;
}
 
bool TrieTree::Delete(const char *word)
{
	char ch;
	trienode *p = root;
	
	if (!Search(word))
		return false;
		
	while ((ch = *word++)) {
		int index = Index_(ch);
		if (index < 0)
			return false;
			
		if (p->next[index] == NULL)
			return false;
			
		if (p->next[index]->count <= 1) {
			Delete_(p->next[index], word);
			p->next[index] = NULL;
			break;
		}
		p->next[index]->count--;
		p = p->next[index];
	}
	p->flag = 0;	
	return true;
}
 
int main()
{
	int n1, n2;
	char word[256];
	
	scanf("%d", &n1);
	while (n1--) {
		TrieTree trie;
		
		scanf("%d", &n2);
		while (n2--) {
			scanf("%s", word);
			trie.Insert(word);
		}
		
		scanf("%s", word);
		if (trie.Search(word))
			printf("we find it: %s\n", word);
		else
			printf("we cannot find it: %s\n", word);
			
		if (trie.Delete("her"))
			printf("we delete it: her\n");
		else
			printf("we cannot delete it: her\n");
			
		if (trie.Search(word))
			printf("we find it: %s\n", word);
		else
			printf("we cannot find it: %s\n", word);
	}
	
	return 0;
}
