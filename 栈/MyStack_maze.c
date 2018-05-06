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

#define MazeScale 2

typedef int Status;

typedef int MazeType[MazeScale][MazeScale];

MazeType maze;

int a[2][2] = {{2,2},{2,2}};

typedef struct{
	int x;
	int y;
}PosType;

typedef struct{
	int ord;
	PosType seat;
	int di;
}SElemType;

typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}MyStack;

Status InitStack(MyStack *S);
Status DestoryStack(MyStack *S);
Status ClearStack(MyStack *S);
Status StackEmpty(MyStack S);
int StackLength(MyStack S);
Status GetTop(MyStack S,SElemType *e);
Status Push(MyStack *S,SElemType e);
Status Pop(MyStack *S,SElemType *e);
Status MazePath(MazeType maze,PosType Start,PosType end);
Status Pass(PosType pos);
Status FootPrint(PosType pos);
PosType NextPos(PosType pos,int di);
Status MarkPrint(PosType pos);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	MyStack S;
	return 0;
}

Status InitStack(MyStack *S)
{
	S->base = malloc(sizeof(SElemType)*STACK_INIT_SIZE);
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

Status GetTop(MyStack S,SElemType *e)
{
	if(S.base==S.top)
	{
		return ERROR;
	}
	(*e) = *--S.top;
	return OK;
}

Status Push(MyStack *S,SElemType e)
{
	if(S->top-S->base>=S->stacksize)
	{
		S->base = realloc(S->base,(STACK_INIT_SIZE+STACKINCREMENT)*sizeof(SElemType));
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

Status Pop(MyStack *S,SElemType *e)
{
	if(S->base==S->top)
	{
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}

Status MazePath(MazeType maze,PosType Start,PosType end)
{
	return OK;
}

Status Pass(PosType pos)
{
	if(maze[pos.x][pos.y]==0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status FootPrint(PosType pos)
{
	maze[pos.x][pos.y] = 1;
	return OK;
}

PosType NextPos(PosType pos,int di)
{
	PosType nextPos;
	switch(di)
	{
		case 1:
			nextPos.x = pos.x+1;
			nextPos.y = pos.y;
			break;
		case 2:
			nextPos.x = pos.x;
			nextPos.y = pos.y-1;
			break;
		case 3:
			nextPos.x = pos.x-1;
			nextPos.y = pos.y;
		case 4:
			nextPos.x = pos.x;
			nextPos.y = pos.y+1;
	}
	return nextPos;
}

Status MarkPrint(PosType pos)
{
	maze[pos.x][pos.y] = -1;
	return OK;
}









