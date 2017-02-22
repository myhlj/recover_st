#include "stack.h"
#include <assert.h>
#include <stdlib.h>

void StackNew(stack *s)
{
	s->loglength = 0;
	s->alloclength = 4;
	s->elems = malloc(4*sizeof(int));
	assert(s->elems!=NULL);
}

void StackDispose(stack* s)
{
	free(s->elems);
}

void StackPush(stack* s, int elems)
{
	if(s->loglength == s->alloclength)
	{
		s->alloclength *= 2;
		s->elems = realloc(s->elems,s->alloclength*sizeof(int));
		assert(s->elems!=NULL);
	}
	s->elems[s->loglength] = elems;
	s->loglength++;
}

int StackPop(stack* s)
{
	assert(s->loglength>0);
	s->loglength--;
	return s->elems[s->loglength];
}

int main()
{
	stack example;
	StackNew(&example);
	StackPush(&example,4);
	StackPush(&example,5);
	StackPush(&example,2);
	StackPush(&example,7);
	int elem = StackPop(&example);
	printf("%d\n",elem);
	StackDispose(&example);
	return 0;
}
