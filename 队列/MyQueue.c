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

int main(int argc, char *argv[]) {
	return 0;
}


Status InitQueue(LinkQueue *Q)
{
	
}
Status DestoryQueue(LinkQueue *Q)
{
	
}
Status ClearQueue(LinkQueue *Q)
{
	
}
Status QueueEmpty(LinkQueue Q)
{
	
}
int QueueLength(LinkQueue Q)
{
	
}
Status GetHead(LinkQueue Q,int *e)
{
	
}
Status EnQueue(LinkQueue *Q,int e)
{
	
}
Status DeQueue(LinkQueue *Q,int *e)
{
	
}
