#ifndef INT_LIST_H
#define INT_LIST_H
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List l);
int IsEmpty(List l);
int IsLast(Position p,List l);
Position Find(int x,List l);
void Delete(int x,List l);
Position FindPrevious(int x,List l);
void Insert(int x,List l,Position p);
void DeleteList(List l);
Position Header(List l);
Position First(List l);
Position Advance(Position p);
int Retrieve(Position p);
void Push(int x,List l);
#endif

struct Node
{
	int element;
	Position Next;
};
