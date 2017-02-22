#ifndef QUEUE_H
#define QUEUE_H

typedef struct
{
	int elemsize;
	int alloclength;
	void* elems;
	int loglength;
	int front;
	int rear;
}Queue;



void QueueNew(Queue* q,int elemsize);
void QueuePush(Queue* q,void* elem);
void QueuePop(Queue* q,void* dest);
int QueueEmpty(Queue* q);
void QueueDispos(Queue* q);
int IsEmpty(Queue* q);
int IsFull(Queue* q);
void MakeEmpty(Queue* q);

static int Succ(int Value,Queue* q);

#endif
