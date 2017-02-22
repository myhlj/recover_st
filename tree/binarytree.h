#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct TreeNode* pTreeNode;

struct TreeNode
{
	void* pElement;
	int elemsize;
	pTreeNode Left;
	pTreeNode Right;
};

void NewTree(int size,pTreeNode* pRoot,void* pElement);//新建一棵二叉树
void AddNode(const pTreeNode pRoot,void* pElement,pTreeNode pParent,int flag);//flag 0为左子树,1为右子树
int FindTreeNode(const pTreeNode pRoot,const pTreeNode pSrc,pTreeNode* pDest);//查找树结点
void DeleteTreeNode(pTreeNode pRoot,pTreeNode pSrc);//删除树节点
void FreeTree(pTreeNode pRoot);//释放整棵树

void ListTree(const pTreeNode pRoot,void (*show)(void*));

void MyShow(void* str);

#endif
