#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

typedef struct QNode{
	int data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr real;
}LinkQueue;

Status InitQueue(LinkQueue *Q);
Status DestoryQueue(LinkQueue *Q);
Status ClearQueue(LinkQueue *Q);
Status QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
Status GetHead(LinkQueue Q,int *e);
Status EnQueue(LinkQueue *Q,int e);
Status DeQueue(LinkQueue *Q,int *e);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	printf("%d",1);
	return 0;
}


Status InitQueue(LinkQueue *Q)
{
	Q->front = Q->real = (QNode *)malloc(sizeof(QNode));
	Q->front->next = NULL;
	return OK;
}

Status DestoryQueue(LinkQueue *Q)
{
	while(Q->front)
	{
		Q->real = Q->front->next;
		free(Q->front);
		Q->front = Q->real;
	}
	return OK; 
}

Status ClearQueue(LinkQueue *Q)
{
	Q->real = Q->front;
	return OK;
}

Status QueueEmpty(LinkQueue Q)
{
	if(Q.real==Q.front)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
	
}

int QueueLength(LinkQueue Q)
{
	return Q.real-Q.front;
}

Status GetHead(LinkQueue Q,int *e)
{
	if(!QueueEmpty(Q))
	{
		(*e) = Q.front->data;
		return OK;
	}
	return ERROR;
}

Status EnQueue(LinkQueue *Q,int e)
{
	QueuePtr elem = (QueuePtr)(malloc(sizeof(QNode)));
	if(elem==NULL)
	{
		exit(OVERFLOW);
	}
	elem->data = e;
	elem->next = NULL;
	Q->real->next = elem;
	Q->real = elem;
	return OK;
}

Status DeQueue(LinkQueue *Q,int *e)
{
	QueuePtr head = Q->front->next;
	(*e) = head->data;
	Q->front->next = head->next;
	if(Q->real==head)
	{
		Q->front=Q->real;
	}
	return OK; 
}
















