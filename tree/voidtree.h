#ifndef VOIDTREE_H
#define VOIDTREE_H

typedef struct TreeNode* pPtrToNode;

struct TreeNode
{
	void* pElement;
	int elemsize;
	pPtrToNode FirstChild;
	pPtrToNode NextSibling;
};

void NewTree(int size,pPtrToNode* pTreeRoot);
void AddNode(void* pElement,const pPtrToNode pRoot,pPtrToNode pParent );
void DeleteNode(void* pElement);
int FindNode(pPtrToNode pElement,const pPtrToNode pTreeRoot,pPtrToNode* pDest);
void GetRoot(pPtrToNode pRoot);
void ListTree(const pPtrToNode pTree);//void (*show)(void*));
void FreeTree(pPtrToNode pTree);
//void FreeNextSibling(pPtrToNode pNode);
#endif
