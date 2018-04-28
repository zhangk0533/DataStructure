#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define STACK_INIT_SIZE 100  //存储空间初始分配量
#define STACKINCREMENT 10  //存储空间分配增量 

typedef int Status;

typedef struct {
	int *base;
	int *top;
	int stacksize;
}MyStack;

Status InitStack(MyStack *S);
Status DestoryStack(MyStack *S);
Status ClearStack(MyStack *S);
Status StackEmpty(MyStack S);
int StackLength(MyStack S);
Status GetTop(MyStack S,int *e);
Status Push(MyStack *S,int e);
Status Pop(MyStack *S,int *e);
void TraverStack(MyStack S);
//Status StackTraverse(MyStack S,)


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	MyStack S;
	
	int e = 0;
	InitStack(&S);
	Push(&S,1);
	Push(&S,2);
	Pop(&S,&e);
	TraverStack(S);
	
	return 0;
}

Status InitStack(MyStack *S)
{
	S->base = malloc(sizeof(int)*STACK_INIT_SIZE);
	if(S->base==NULL)
	{
		exit(OVERFLOW);
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status DestoryStack(MyStack *S)
{
	free(S->base);
	S->base = NULL;
	S->top = NULL;
}

Status ClearStack(MyStack *S)
{
	S->stacksize = 0;
	S->top = S->base;
	return OK;
}

Status StackEmpty(MyStack S)
{
	if(S.base==S.top)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int StackLength(MyStack S)
{
	return S.top-S.base;
}

Status GetTop(MyStack S,int *e)
{
	if(S.base==S.top)
	{
		return ERROR;
	}
	(*e) = *--S.top;
	return OK;
}

Status Push(MyStack *S,int e)
{
	if(S->top-S->base>=S->stacksize)
	{
		S->base = realloc(S->base,(STACK_INIT_SIZE+STACKINCREMENT)*sizeof(int));
		if(S->base==NULL)
		{
			exit(OVERFLOW);
		}
		S->top = S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

Status Pop(MyStack *S,int *e)
{
	if(S->base==S->top)
	{
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}

void TraverStack(MyStack S)
{
	while(S.base<S.top)
	{
		printf("%d",*--S.top);
	}
}

















