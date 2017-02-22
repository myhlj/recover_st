#include "queue.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void QueueNew(Queue* q,int elemsize)
{
	q->elemsize = elemsize;
	q->loglength = 0;
	q->alloclength = 10;
	q->elems = malloc(10 * q->elemsize);
	assert(q->elems);
	q->front = 1;
	q->rear = 0;
}


int Succ(int Value,Queue* q)
{
	if(++Value == q->alloclength)
		Value = 0;
	return Value;
}


int IsFull(Queue* q)
{
	return q->loglength == q->alloclength;
}


int IsEmpty(Queue* q)
{
	return q->loglength == 0;
}



void QueuePush(Queue* q,void* elem)
{
	if(IsFull(q))
	{
		q->alloclength *= 2;
		q->elems = realloc(q->elems,q->alloclength);
		assert(q->elems);
	}

	
	q->rear = Succ(q->rear,q);

	void* addr = (char*)q->elems + (q->rear * q->elemsize);
	memcpy(addr,elem,q->elemsize);
	
	q->loglength++;
}



void QueuePop(Queue* q,void* dest)
{
	if(IsEmpty(q))
	{
		dest = NULL;
		return;
	}

	////////////////////////////////////////////////////////
	void* dest1 = (char*)q->elems + (q->front * q->elemsize);
	memcpy(dest,dest1,q->elemsize);

	q->front++;
	q->loglength--;
}



void MakeEmpty(Queue* q)
{
	q->loglength = 0;
	q->front = 1;
	q->rear = 0;
}

int main()
{
	Queue q;
	
	QueueNew(&q,sizeof(int));

	int sample1 = 10;
	int sample2 = 20;

	QueuePush(&q,&sample1);
	QueuePush(&q,&sample2);


	int dest1,dest2;
	QueuePop(&q,&dest1);
	QueuePop(&q,&dest2);


	printf("dest1:%d\n",dest1);
	printf("dest2:%d\n",dest2);


	Queue q1;
	QueueNew(&q1,sizeof(char*));

	char* str1 = "123456";
	char* str2 = "7891011";

	QueuePush(&q1,&str1);
	QueuePush(&q1,&str2);


	char* dest = NULL;
	QueuePop(&q1,&dest);

	printf("%s\n",dest);

	return 0;
}
