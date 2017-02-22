#include "voidtree.h"
#include "stdlib.h"
#include "assert.h"
#include <string.h>
#include <sys/time.h>


void NewTree(int size,pPtrToNode* pTreeRoot)
{

//	pPtrToNode pTemp = malloc(sizeof(struct TreeNode));
	*pTreeRoot = malloc(sizeof(struct TreeNode));
	(*pTreeRoot)->elemsize = size;
	
	(*pTreeRoot)->pElement = NULL;
//	(*pTreeRoot)->pElement = malloc(size);
//	assert((*pTreeRoot)->pElement != NULL);

//	int zerro = 0;
//	memcpy((*pTreeRoot)->pElement,&zerro,size);
//	pTemp->pElement = NULL;

	(*pTreeRoot)->FirstChild = NULL;
	(*pTreeRoot)->NextSibling = NULL;

//	*pTreeRoot = pTemp;
}


void AddNode( void* pElement,const pPtrToNode pRoot,pPtrToNode pParent )
{
	pPtrToNode pTemp = malloc(sizeof(struct TreeNode));
	assert(pTemp != NULL);

	if(pRoot == NULL || pParent == NULL)
		return;

	pTemp->pElement = malloc(pRoot->elemsize);
	assert(pTemp->pElement != NULL);
	memcpy(pTemp->pElement,pElement,pRoot->elemsize);
	pTemp->elemsize = pRoot->elemsize;
	pTemp->FirstChild = NULL;
	pTemp->NextSibling = NULL;
	

	pPtrToNode pDest = NULL;
//	FindNode(pParent,pRoot,&pDest);

	if(FindNode(pParent,pRoot,&pDest))
	{
		if(pDest->FirstChild != NULL)
		{
			pPtrToNode p = pDest->FirstChild;
			while(p->NextSibling != NULL)
			{
				p = p->NextSibling;
			}
			p->NextSibling = pTemp;

//			if(pTemp->pElement)
//				printf("NextSibling:%s\n",*(char**)pTemp->pElement);
		}
		else
		{
			pDest->FirstChild = pTemp;
//			if(pTemp->pElement)
//				printf("FirstChild:%s\n",*(char**)pTemp->pElement);
		}
	}
}

int FindNode(pPtrToNode pElement,const pPtrToNode pTreeRoot,pPtrToNode* pDest)
{
	int flag = 0;
	if(pElement == NULL || pTreeRoot == NULL)
	{
		return flag;
	}

	pPtrToNode pTemp = pTreeRoot;
	
	if(memcmp(pElement,pTreeRoot,sizeof(pPtrToNode)) == 0){
		*pDest = pTemp;
//		if(pTemp->pElement)
//			printf("firstchild找到 :%s\n",*(char**)pTemp->pElement);
		flag = 1;
		return flag;
	}
	/*
	pTemp = pTemp->FirstChild;
	while(pTemp != NULL)
	{
		if(memcmp(pElement,pTemp,sizeof(pPtrToNode)) == 0){
			*pDest = pTemp;
//			if(pTemp->NextSibling->pElement)
//				printf("nextSibling找到 :%s\n",*(char**)pTemp->NextSibling->pElement);
			return;
		}
		pTemp = pTemp->NextSibling;
	}
	*/
	if(!flag)
		flag = FindNode(pElement,pTreeRoot->NextSibling,pDest);
	if(!flag)
		flag = FindNode(pElement,pTreeRoot->FirstChild,pDest);
//	FindNode(pElement,pTreeRoot->NextSibling,pDest);
}

void ListTree(const pPtrToNode pTree)//void (*show)(void*))
{
	if(pTree == NULL)
	{
//		printf("----------------------\n");
		return;
	}

	pPtrToNode pTemp = pTree;
	
	if(pTemp->pElement != NULL)
	{
//		char* pDest = NULL;
//		memcpy(&pDest,pTemp->pElement,pTemp->elemsize);
//		printf("%s\n",pDest);

		printf("%s\n",*((char**)pTemp->pElement));
	}

/*	
	while(pTemp->NextSibling != NULL)
	{
		if(pTemp->NextSibling->pElement != NULL)
		{
//			char* pDest = NULL;
//			memcpy(&pDest,pTemp->NextSibling->pElement,pTemp->elemsize);
//			printf("NextSibling:%s\n",pDest);
			printf("NextSIbling:%s\n",*(char**)pTemp->NextSibling->pElement);
		}
		pTemp = pTemp->NextSibling;
	}
*/
	
//	ListTree(pTree->NextSibling);
//	ListTree(pTree->FirstChild);

	ListTree(pTree->FirstChild);
	ListTree(pTree->NextSibling);
}

/*
void FreeNextSibling(pPtrToNode pNode)
{
	if(pNode == NULL)
		return;
	if(pNode->NextSibling != NULL)
		FreeNextSibling(pNode->NextSibling);
	if(pNode->pElement)
		free(pNode->pElement);
	free(pNode);
	pNode = NULL;
}
*/

void FreeTree(pPtrToNode pTree)
{
	if(pTree == NULL)
		return;
	pPtrToNode pTemp = pTree;

//	FreeNextSibling(pTemp->NextSibling);

//	if(pTemp->FirstChild != NULL)
	FreeTree(pTemp->FirstChild);
	FreeTree(pTemp->NextSibling);
	
	if(pTemp->pElement)
		free(pTemp->pElement);
	free(pTemp);	
	pTemp = NULL;
}

/*
void DeleteTreeNode(pTrToNode pRoot,pTrToNode pSrc)
{
	
}
*/

int main()
{

	pPtrToNode pRoot = NULL;
	NewTree(sizeof(char*),&pRoot);

	char* first = "first";
	AddNode(&first,pRoot,pRoot);

	char* seconed = "seconed";
	AddNode(&seconed,pRoot,pRoot);

	char* three = "three";
	AddNode(&three,pRoot,pRoot->FirstChild);


	char* four = "four";
	AddNode(&four,pRoot,pRoot->FirstChild);

	char* five = "five";
	AddNode(&five,pRoot,pRoot->FirstChild);


	char* six = "six";
	AddNode(&six,pRoot,pRoot->FirstChild->NextSibling);

	char* seven = "seven";
	AddNode(&seven,pRoot,pRoot->FirstChild->NextSibling);

	char* eight = "eight";
	AddNode(&eight,pRoot,pRoot);

	char* nine = "nine";
	AddNode(&nine,pRoot,pRoot->FirstChild->NextSibling->NextSibling);
/*
	char* five = "five";
	AddNode(&five,pRoot,pRoot->NextSibling->FirstChild);

	char* six = "six";
	AddNode(&six,pRoot,pRoot->NextSibling->NextSibling);
*/
/*	int one = 1;
	AddNode(&one,pRoot,pRoot);
		
	int two = 2;
//	if(pRoot->FirstChild != NULL)
//	{
		AddNode(&two,pRoot,pRoot);
//	}

	int three = 3;
	AddNode(&three,pRoot,pRoot);


	int four = 4;
	AddNode(&four,pRoot,pRoot->FirstChild);


	int five = 5;
	AddNode(&five,pRoot,pRoot->FirstChild->FirstChild);
	ListTree(pRoot);

	FreeTree(pRoot);
	*/
	
	struct timeval tpstart,tpend;
	float timeuse;
	gettimeofday(&tpstart,NULL);


	ListTree(pRoot);


	gettimeofday(&tpend,NULL);


	timeuse = 1000000 * (tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;
	timeuse/=1000000;

	printf("Used Tiem: %f\n",timeuse);
	FreeTree(pRoot);
	
	return 0;
}
