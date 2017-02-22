#include "searchtree.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>



void NewTree(void* key,int elemsize,pTreeNode* pTree)
{
	(*pTree) = malloc(sizeof(struct TreeNode));

	(*pTree)->elemsize = elemsize;
	(*pTree)->Left = NULL;
	(*pTree)->Right = NULL;

	(*pTree)->pElement = malloc(elemsize);
	memcpy((*pTree)->pElement,key,elemsize);
}



pTreeNode Find(void* key,const pTreeNode pTree,int (*Compare)(void* src,void* dest))
{
	if(pTree == NULL)
		return NULL;
	if(Compare(key,pTree->pElement) < 0)
		return Find(key,pTree->Left,Compare);
	else if(Compare(key,pTree->pElement) > 0)
		return Find(key,pTree->Right,Compare);
	else
		return pTree;
}

pTreeNode FindMin(const pTreeNode pTree)
{
	if(pTree == NULL)
		return NULL;
	else if(pTree->Left == NULL)
		return pTree;
	else 
		return FindMin(pTree->Left);
}

pTreeNode FindMax(const pTreeNode pTree)
{
	pTreeNode pTemp = pTree;
	if(pTree == NULL)
		return NULL;
	else
		while(pTemp->Right != NULL)
			pTemp = pTemp->Right;

	return pTemp;
}

int Insert(const pTreeNode pTree,void* key,int (*Compare)(void* src,void* dest))
{
	int flag = 1;
	if(pTree == NULL)
	{
		flag = 0;
		return flag;
	}
	else if(Compare(pTree->pElement,key) < 0)
		flag = Insert(pTree->Left,key,Compare);
	else if(Compare(pTree->pElement,key) > 0)
		flag = Insert(pTree->Right,key,Compare);
	
	if(!flag)
	{
		pTreeNode pTemp = malloc(sizeof(struct TreeNode));
		pTemp->Left = NULL;
		pTemp->Right = NULL;
		pTemp->elemsize = pTree->elemsize;
		pTemp->pElement = malloc(pTemp->elemsize);
		memcpy(pTemp->pElement,key,pTemp->elemsize);

		if(Compare(pTree->pElement,key) < 0)
			pTree->Left = pTemp;
		else if(Compare(pTree->pElement,key) > 0)
			pTree->Right = pTemp;

		flag = 1;
	}
}

void ListTree(const pTreeNode pTree,void (*show)(void* src))
{
	if(pTree == NULL)
		return;
//	show(pTree->pElement);
	ListTree(pTree->Left,show);
	show(pTree->pElement);
	ListTree(pTree->Right,show);
}

void ShowElement(void* src)
{
	printf("%d\n",*(int*)src);
}

int CompareInt(void* src,void* dest)
{
	return *(int*)dest - *(int*)src;
}

void FreeTree(pTreeNode pTree)
{
	if(pTree == NULL)
		return;
	FreeTree(pTree->Left);
	FreeTree(pTree->Right);
	if(pTree)
	{
		if(pTree->pElement)
			free(pTree->pElement);
		free(pTree);
	}
}


pTreeNode DeleteTree(void* key,pTreeNode pTree,int (*Compare)(void* src,void* dest))
{
	if(pTree == NULL){
		printf("Element not found");
		return NULL;
	}

	pTreeNode pTempCell = NULL;
	if(Compare(pTree->pElement,key)<0)
		pTree->Left = DeleteTree(key,pTree->Left,Compare);
	else if(Compare(pTree->pElement,key)>0)
		pTree->Right = DeleteTree(key,pTree->Right,Compare);
	else if(pTree->Left && pTree->Right)//找到了该节点，该节点有两个儿子
	{
		pTempCell = FindMin(pTree->Right);
		memcpy(pTree->pElement,pTempCell->pElement,pTree->elemsize);
		pTree->Right = DeleteTree(pTempCell->pElement,pTree->Right,Compare);
	}
	else//只有一个儿子,或者没有儿子
	{
		pTempCell = pTree;
		if(pTree->Left == NULL)
			pTree = pTree->Right;
		else if(pTree->Right == NULL)
			pTree = pTree->Left;
		free(pTempCell);
	}
	return pTree;
}

int main()
{
	pTreeNode pTree = NULL;

	int root = 5;
	NewTree(&root,sizeof(int),&pTree);

	int one = 1;
	Insert(pTree,&one,CompareInt);

	int two = 2;
	Insert(pTree,&two,CompareInt);

	int three = 3;
	Insert(pTree,&three,CompareInt);

	int four = 4;
	Insert(pTree,&four,CompareInt);

	int six = 6;
	Insert(pTree,&six,CompareInt);

	int seven = 7;
	Insert(pTree,&seven,CompareInt);

	ListTree(pTree,ShowElement);

	pTreeNode pMax = FindMax(pTree);
	pTreeNode pMin = FindMin(pTree);

	printf("%d\n",*(int*)pMax->pElement);
	printf("%d\n",*(int*)pMin->pElement);


	int key = 3;
	DeleteTree(&key,pTree,CompareInt);

	ListTree(pTree,ShowElement);

	FreeTree(pTree);


	return 0;
}
