#ifndef VOID_LIST_H
#define VOID_LIST_H
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List NewList(int elemsize,List l);
int IsEmpty(List l);
int IsLast(Position p,List l);
Position Find(void* elem,List l);
void Delete(void* elem,List l);
Position FindPrevious(void* elem,List l);
void Insert(void* elem,List l,Position p);
void Push(void* elem,List l);
void DeleteList(List l);
void GetAt(List l,Position p,void* pDest);
List Reverse(List l);
#endif
struct Node
{
	void* elems;
	int elemsize;
	Position next;
};

struct Data
{
	int first;
	double se;
	long third;
};
