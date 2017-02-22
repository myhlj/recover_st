#ifndef _Cursor_H
#define _Cursor_H

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitializeCursorSpace( void );

List MakeEmpty( List L);
int IsEmpty( const Lsit L);

int IsLast( const Position P,const List L);

Position Find(int X,const List L);

void Insert(int X, List L ,Position P);

void DeleteList(List L);

Position Header( const List L);

Position First( const List L);

Position Advance( const Position P);

int Retrieve( const Position P );

static Position CursorAlloc( void );

static void CursorFree( void );
#endif

struct Node
{
	int Element;
	Position Next;
};

struct Node CursorSpace[ 256 ];
