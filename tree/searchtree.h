#ifndef SEARCHTREE_H
#define SEARCHTREE_H

typedef struct TreeNode* pTreeNode;
struct TreeNode
{
	void* pElement;
	int elemsize;
	pTreeNode Left;
	pTreeNode Right;
};

void NewTree(void* key,int elemsize,pTreeNode* pTree);
pTreeNode Find(void* key,const pTreeNode pTree,int (*Compare)(void* src,void* dest));
pTreeNode FindMin(const pTreeNode pTree);
pTreeNode FindMax(const pTreeNode pTree);
int Insert(const pTreeNode pTree,void* key,int (*Compare)(void* src,void* dest));

void ListTree(const pTreeNode pTree,void(*show)(void* src));

void FreeTree(pTreeNode pTree);

pTreeNode DeleteTree(void* key,pTreeNode pTree,int (*Compare)(void* src,void* dest));
#endif
