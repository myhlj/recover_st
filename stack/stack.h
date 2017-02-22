#ifndef STACK_H
#define STACK_H

typedef struct
{
	int *elems;
	int loglength;
	int alloclength;
}stack;
void StackNew(stack *s);
void StackDispose(stack *s);
void StackPush(stack *s,int elems);
int StackPop(stack* s);

#endif
