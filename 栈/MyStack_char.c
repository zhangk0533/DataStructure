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
	char *base;
	char *top;
	int stacksize;
}MyStack;

Status InitStack(MyStack *S);
Status DestoryStack(MyStack *S);
Status ClearStack(MyStack *S);
Status StackEmpty(MyStack S);
int StackLength(MyStack S);
Status GetTop(MyStack S,char *e);
Status Push(MyStack *S,char e);
Status Pop(MyStack *S,char *e);
void TraverStack(MyStack S);
void LineEdit();

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	MyStack S;
	
	return 0;
}

Status InitStack(MyStack *S)
{
	S->base = (char*)malloc(sizeof(char)*STACK_INIT_SIZE);
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
	return OK;
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

Status GetTop(MyStack S,char *e)
{
	if(S.base==S.top)
	{
		return ERROR;
	}
	(*e) = *--S.top;
	return OK;
}

Status Push(MyStack *S,char e)
{
	if(S->top-S->base>=S->stacksize)
	{
		S->base = (char*)realloc(S->base,(STACK_INIT_SIZE+STACKINCREMENT)*sizeof(char));
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

Status Pop(MyStack *S,char *e)
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
		printf("%c",*--S.top);
	}
}

void LineEdit()
{
	MyStack S;
	InitStack(&S);
	char ch = getchar();
	while(ch!=EOF)
	{
		while(ch!='\n'&&ch!=EOF)
		{
			char e;
			switch(ch)
			{
				case '#':Pop(&S,&e);
				break;
				case '@':ClearStack(&S);
				break; 
				default:Push(&S,ch);
			}
			ch = getchar();
		}
		ClearStack(&S);
		ch = getchar();
	}
}

void SymbolMatch() 
{
	MyStack S;
	InitStack(&S);
	char ch = getchar();
	while(ch!='\n')
	{
		
	}
}















