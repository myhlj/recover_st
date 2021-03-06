#include "int_list.h"
#include "stdlib.h"
#include <string.h>
#include <assert.h>
//本例中使用哑节点
int IsEmpty(List l)
{
	return l->Next == NULL;
}

int IsLast(Position p,List l)
{
	return p->Next == NULL;
}

Position Find(int x,List l)
{
	Position p;
	p = l->Next;//所以从p->next开始
	while(p!=NULL && p->element != x)
		p = p->Next;
	return p;
}

Position FindPrevious(int x,List l)
{
	/*
	Position poslast = l;
	Position p = l->Next;
	while(p!=NULL && p->element != x)
	{
		poslast = p;
		p = p->Next;
	}
	return poslast;
	*/
	Position p;
	p = l;
	while(p->Next != NULL && p->Next->element != x)
		p = p->Next;
	if(p->Next == NULL)
	{
		return NULL;
	}
	return p;
}

void Insert(int x,List l,Position p)
{
	Position tempCell;
	tempCell = malloc(sizeof(struct Node));
	assert(tempCell!=NULL);
	tempCell->element = x;
	tempCell->Next = p->Next;
	p->Next = tempCell;
}

void Push(int x,List l)
{
	Position p;
	p = l;
	while(p->Next)
	{
		p = p->Next;
	}
	Position newNode = malloc(sizeof(struct Node));
	assert(newNode!=NULL);
	memset(newNode,0,sizeof(struct Node));
	newNode->element = x;
	p->Next = newNode;
}

void Delete(int x,List l)
{
	Position p = FindPrevious(x,l);
	if(p!=NULL)
	{
		Position posNext = p->Next->Next;
		free(p->Next);
		p->Next = posNext;
	}
}

void DeleteList(List l)
{
	Position p,pTemp;
	p = l->Next;
	l->Next = NULL;
	while(p)
	{
		pTemp = p->Next;
		free(p);
		p = pTemp;
	}
	free(l);
	l = NULL;
}

void Reverse(List l){
    Position p,ppre,head;
    head = l;
    p = l->Next;
    while(p){
        ppre = p;
        p = p->Next;

    }
}

int main()
{
	List l = malloc(sizeof(struct Node));
	memset(l,0,sizeof(struct Node));
	assert(l!=NULL);
	Insert(8,l,l);
	Insert(19,l,l);
	Insert(89,l,l);
	Position p = Find(10,l);
	if(p!=NULL)
		printf("%d\n",p->element);

//	p = FindPrevious(90,l);
//	if(p!=NULL)
//		printf("%d\n",p->element);

	Push(99,l);
//	p = FindPrevious(99,l);
//	if(p!=NULL)
//		printf("%d\n",p->element);

	Delete(90,l);
	Push(110,l);


	Position pTemp = l->Next;
	while(pTemp!=NULL)
	{
		printf("%d\n",pTemp->element);
		pTemp = pTemp->Next;
	}
	
	DeleteList(l);
	Position pTemp1 = l;
	while(pTemp1!=NULL)
	{
		printf("%d\n",pTemp1->element);
		pTemp1 = pTemp1->Next;
	}	
	return 0;
}
