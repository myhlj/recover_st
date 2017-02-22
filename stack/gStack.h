#ifndef GSTACK_H
#define GSTACK_H

typedef struct
{
	int elemsize;
	int loglength;
	int alloclength;
	void* elems;
	void (*release)(void*);
}stack;

void StackNew(stack* s,int elemsize,void (*release)(void*));
void StackDispos(stack* s);
void StackPush(stack* s,void* elem);
void StackPop(stack* s,void* destelem);
int StackEmpty(stack* s);
void StackTop(stack* s,void* target);
#endif
