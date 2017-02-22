#include "binarytree.h"
#include "stdlib.h"
#include <string.h>
#include "assert.h"


void NewTree(int size,pTreeNode* pRoot,void* pElement)
{
	*pRoot = malloc(sizeof(struct TreeNode));
	(*pRoot)->elemsize = size;
	(*pRoot)->Left = NULL;
	(*pRoot)->Right = NULL;
	(*pRoot)->pElement = malloc(size);
	assert((*pRoot)->pElement != NULL);
	memcpy((*pRoot)->pElement,pElement,size);
}

void AddNode(const pTreeNode pRoot,void* pElement,pTreeNode pParent,int flag)
{
	pTreeNode pTemp = malloc(sizeof(struct TreeNode));
	assert(pTemp!=NULL);
	pTemp->Left = NULL;
	pTemp->Right = NULL;
	pTemp->elemsize = pRoot->elemsize;

	pTemp->pElement = malloc(pTemp->elemsize);
	assert(pTemp->pElement!=NULL);
	memcpy(pTemp->pElement,pElement,pTemp->elemsize);

	pTreeNode pDest = NULL;
	if(FindTreeNode(pRoot,pParent,&pDest))
	{
		if(!flag)
		{
			pDest->Left = pTemp;
		}
		else
		{
			pDest->Right = pTemp;
		}
	}
}

int FindTreeNode(const pTreeNode pRoot,const pTreeNode pSrc,pTreeNode* pDest)
{
	int flag = 0;
	if(pRoot == NULL || pSrc == NULL)
	{
		*pDest = NULL;
		return flag;
	}

	if(memcmp(pRoot,pSrc,sizeof(pTreeNode)) == 0)
	{
		flag = 1;
		*pDest = pRoot;
		return flag;
	}
	if(!flag)
		flag = FindTreeNode(pRoot->Left,pSrc,pDest);
	if(!flag)
		flag = FindTreeNode(pRoot->Right,pSrc,pDest);
}


void ListTree(const pTreeNode pRoot,void (*show)(void*))
{
	if(pRoot == NULL)
		return;
	//后序遍历	
	ListTree(pRoot->Left,show);
	ListTree(pRoot->Right,show);
	if(pRoot->pElement)
		show(pRoot->pElement);
	//中序遍历
//	ListTree(pRoot->Left,show);
//	if(pRoot->pElement)
//		show(pRoot->pElement);
//	ListTree(pRoot->Right,show);
}

void MyShow(void* str)
{
	if(str == NULL)
		return;
	printf("%s\n",*(char**)str);
}

void FreeTree(pTreeNode pTree)
{
	if(pTree == NULL)
		return;
	FreeTree(pTree->Left);
	FreeTree(pTree->Right);

	if(pTree->pElement)
		free(pTree->pElement);
	
	free(pTree);
	pTree = NULL;
}

int main()
{
	pTreeNode pTree = NULL;
	char* add="-";
	
	NewTree(sizeof(char*),&pTree,&add);

	char* first = "*";
	AddNode(pTree,&first,pTree,0);

	char* second = "e";
	AddNode(pTree,&second,pTree,1);
	
	char* three = "*";
	AddNode(pTree,&three,pTree->Left,0);
	
	char* four = "+";
	AddNode(pTree,&four,pTree->Left,1);

	char* five = "a";
	AddNode(pTree,&five,pTree->Left->Left,0);

	char* six = "b";
	AddNode(pTree,&six,pTree->Left->Left,1);


	char* seven = "c";
	AddNode(pTree,&seven,pTree->Left->Right,0);

	char* eight = "d";
	AddNode(pTree,&eight,pTree->Left->Right,1);

//	char* nine = "nine";
//	AddNode(pTree,&nine,pTree->Right->Right,0);

//	char* ten = "ten";
//	AddNode(pTree,&ten,pTree->Right->Right,1);

	ListTree(pTree,MyShow);

	FreeTree(pTree);
	return 0;
}
