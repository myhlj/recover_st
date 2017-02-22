#include <stdlib.h>
#include "void_list.h"
#include <string.h>
#include <assert.h>
#include <math.h>

List NewList(int elemsize,List l)
{
	l->elemsize = elemsize;
	l->elems = malloc(elemsize);
	assert(l->elems!=NULL);
	l->next = NULL;
}

int IsEmpty(List l)
{
	return l->next==NULL;
}

int IsLast(Position p,List l)
{
	Position temp = Find(p->elems,l);
	if(temp==NULL)
	{
		return 0;
	}
	else
	{
		return temp->next==NULL;
	}
}

Position Find(void* elem,List l)
{
	Position p;
	p = l->next;
	while(p!=NULL && memcmp(elem,p->elems,l->elemsize)!=0)
		p = p->next;
	return p;
}


Position FindPrevious(void* elem,List l)
{
	Position p;
	p = l;
	while(p->next!=NULL && memcmp(p->next->elems,elem,l->elemsize)!=0)
		p=p->next;
	if(p->next == NULL)
	{
		return NULL;
	}
	return p;
}

void Insert(void* elem,List l,Position p)
{
	Position tempCell;
	tempCell = malloc(sizeof(struct Node));
	assert(tempCell!=NULL);
	tempCell->elems = malloc(l->elemsize);
	memcpy(tempCell->elems,elem,l->elemsize);
	tempCell->next = p->next;
	p->next = tempCell;
}

void Push(void* elem,List l)
{
	Position p;
	p = l;
	if(p!=NULL)
	{
		while(p->next)
		{
			p=p->next;
		}
		Position newNode = malloc(sizeof(struct Node));
		assert(newNode!=NULL);
		newNode->elems = malloc(l->elemsize);
		newNode->next=NULL;
		memcpy(newNode->elems,elem,l->elemsize);
		p->next = newNode;
	}
}

void Delete(void* elem,List l)
{
	Position p = FindPrevious(elem,l);
	if(p!=NULL)
	{
		Position posNext = p->next->next;
		free(p->next->elems);
		free(p->next);
		p->next = posNext;
	}
}

void DeleteList(List l)
{
	Position p,pTemp;
	p = l->next;
	l->next=NULL;
	while(p)
	{
		pTemp = p->next;
		free(p->elems);
		free(p);
		p = pTemp;
	}
	free(l);
	l = NULL;
}


void GetAt(List l,Position p,void* pDest)
{
	memcpy(pDest,p->elems,l->elemsize);
}


List Reverse(List l)
{
	if(l==NULL)return NULL;
	PtrToNode first=l;
	PtrToNode second=l->next;
	PtrToNode third=NULL;

	first->next = NULL;
	if(second==NULL)
		return l;
	while(second!=NULL)
	{
		third=second->next;
		second->next=first;

		first=second;
		second=third;
	}
	return first;
}

typedef struct Data* pData;

struct OneCore
{
	int Coefficent;
	int Exponent;
};

typedef struct OneCore* pOneCore;
int main()
{

/*	List l = malloc(sizeof(struct Node));
	NewList(sizeof(int),l);
	int elems = 5;
	Push(&elems,l);
	elems = 6;
	Push(&elems,l);
	elems = 7;
	Push(&elems,l);

	Position pTemp = l->next;
	while(pTemp!=NULL)
	{
		int elems;
		memcpy(&elems,pTemp->elems,l->elemsize);
		printf("%d\n",elems);
		pTemp = pTemp->next;
	}
	

	Delete(&elems,l);

	pTemp = l->next;
	while(pTemp!=NULL)
	{
		int elems;
		memcpy(&elems,pTemp->elems,l->elemsize);
		printf("%d\n",elems);
		pTemp = pTemp->next;
	}

	elems = 5;
	Position p = Find(&elems,l);
	elems = 8;
	Insert(&elems,l,p);
	elems = 9;
	Insert(&elems,l,p);
	pTemp = l->next;
	while(pTemp!=NULL)
	{
		int elems;
		memcpy(&elems,pTemp->elems,l->elemsize);
		printf("%d\n",elems);
		pTemp = pTemp->next;
	}
	DeleteList(l);
*/
	/*
	double a=3.1415925;double b=78.21341;double c=89.788;
	List newList = malloc(sizeof(struct Node));
	NewList(sizeof(double),newList);
	Push(&a,newList);Push(&b,newList);
	Push(&c,newList);

	Position pTemp = newList->next;
	while(pTemp!=NULL)
	{
		double elems;
		memcpy(&elems,pTemp->elems,newList->elemsize);
		printf("%f\n",elems);
		pTemp = pTemp->next;
	}
	*/
/*	
	struct Data one;one.first=1;one.se=1.78;one.third=400;
	struct Data two;two.first=2;two.se=2.78;two.third=500;
	List sList = malloc(sizeof(struct Node));
	NewList(sizeof(struct Data),sList);
	Push(&one,sList);Push(&two,sList);
	Position pTemp = sList->next;
	while(pTemp!=NULL)
	{
		struct Data dest;
//		memcpy(&dest,pTemp->elems,sList->elemsize);
		GetAt(sList,pTemp,&dest);
		printf("%d\n",dest.first);
		printf("%f\n",dest.se);
		printf("%d\n",dest.third);
		pTemp = pTemp->next;
	}
*/
	/*
	
	pData pExample = malloc(sizeof(struct Data));
	pExample->first=1;pExample->se=2.89;pExample->third=400;
	pData pSend = malloc(sizeof(struct Data));
	pSend->first=2;pSend->se=3.89;pSend->third=500;
	pData pThird = malloc(sizeof(struct Data));
	pThird->first=3;pThird->se=4.89;pThird->third=600;
	List pList = malloc(sizeof(struct Node));
	NewList(sizeof(pData),pList);
	Push(&pExample,pList);Push(&pSend,pList);Push(&pThird,pList);
	
	Position pTemp = pList->next;
	while(pTemp!=NULL)
	{
		struct Data* pDest;
		GetAt(pList,pTemp,&pDest);
		printf("%d\n",pDest->first);
		printf("%f\n",pDest->se);
		printf("%d\n",pDest->third);
		pTemp = pTemp->next;
	}
	
	List l = malloc(sizeof(struct Node));
	NewList(sizeof(pOneCore),l);
	pOneCore pOne = malloc(sizeof(struct OneCore));
	pOne->Coefficent = 5;
	pOne->Exponent = 8;
	Push(&pOne,l);
	pOneCore pTwo = malloc(sizeof(struct OneCore));
	pTwo->Coefficent = -3;
	pTwo->Exponent = 2;
	Push(&pTwo,l);

	double x=2;
	double result = 0;
	pTemp = l->next;
	while(pTemp!=NULL)
	{
		struct OneCore* pDest;
		GetAt(l,pTemp,&pDest);
		result += pDest->Coefficent*x + pow((double)x,(double)pDest->Exponent);
		pTemp = pTemp->next;
	}

	printf("%f\n",result);
*/
	List lpoint = malloc(sizeof(struct Node));
	NewList(sizeof(char*),lpoint);
	char* strOne = "one";
	char* strTwo = "second";
	char* strThree = "Three";
	Push(&strOne,lpoint);
	Push(&strTwo,lpoint);
	Push(&strThree,lpoint);
	Position pCharPosi = lpoint->next;
	while(pCharPosi != NULL)
	{
		char* pDest;
		GetAt(lpoint,pCharPosi,&pDest);
		printf("%s\n",pDest);
		pCharPosi = pCharPosi->next;
	}
	return 0;
}
