<<<<<<< Updated upstream
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

#define MazeScale 10

typedef int Status;

typedef int MazeType[MazeScale][MazeScale];

MazeType maze = {
	{2,2,2,2,2,2,2,2,2,2},
	{2,0,0,2,0,0,0,2,0,2},
	{2,0,0,2,0,0,0,2,0,2},
	{2,0,0,0,0,2,2,0,0,2},
	{2,0,2,2,2,0,0,0,0,2},
	{2,0,0,0,2,0,0,0,0,2},
	{2,0,2,0,0,0,2,0,0,2},
	{2,0,2,2,2,0,2,2,0,2},
	{2,2,0,0,0,0,0,0,0,2},
	{2,2,2,2,2,2,2,2,2,2}
};

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
    int i,j;
	for(i=0;i<MazeScale;i++)
	{
		for(j=0;j<MazeScale;j++)
		{
			if(maze[i][j]==2)
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	PosType start;
	PosType end;
	start.x = 1;
	start.y = 1;
	end.x = 8;
	end.y = 8;
	MazePath(maze,start,end);

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

Status MazePath(MazeType maze,PosType start,PosType end)
{
	MyStack S;
	InitStack(&S);
	int cusStep = 1;
	PosType curPos = start;
	do
	{
		if(Pass(curPos))
		{
			FootPrint(curPos);
			SElemType e;
			e.di = 1;
			e.ord = cusStep;
			e.seat = curPos;
			Push(&S,e);
			if(e.seat.x==end.x&&e.seat.y==end.y)
			{
				break;
			}
			curPos = NextPos(curPos,e.di);
			cusStep++;
		}
		else
		{
			cusStep--;
			SElemType e;
			Pop(&S,&e);
			while(e.di==4&&!StackEmpty(S))
			{
				MarkPrint(e.seat);
				Pop(&S,&e);
				cusStep--;
			}
			if(e.di<4)
			{
				curPos = NextPos(e.seat,e.di+1);
				e.di++;
				cusStep++;
				Push(&S,e);
			}
		}
	}while(!StackEmpty(S));
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
			nextPos.x = pos.x;
			nextPos.y = pos.y+1;
			break;
		case 2:
			nextPos.x = pos.x+1;
			nextPos.y = pos.y;
			break;
		case 3:
			nextPos.x = pos.x;
			nextPos.y = pos.y-1;
		case 4:
			nextPos.x = pos.x-1;
			nextPos.y = pos.y;
	}
	return nextPos;
}

Status MarkPrint(PosType pos)
{
	maze[pos.x][pos.y] = -1;
	return OK;
}









=======
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

#define MazeScale 10

typedef int Status;

typedef int MazeType[MazeScale][MazeScale];

MazeType maze = {
	{2,2,2,2,2,2,2,2,2,2},
	{2,0,0,2,0,0,0,2,0,2},
	{2,0,0,2,0,0,0,2,0,2},
	{2,0,0,0,0,2,2,0,0,2},
	{2,0,2,2,2,0,0,0,0,2},
	{2,0,0,0,2,0,0,0,0,2},
	{2,0,2,0,0,0,2,0,0,2},
	{2,0,2,2,2,0,2,2,0,2},
	{2,2,0,0,0,0,0,0,0,2},
	{2,2,2,2,2,2,2,2,2,2}
};

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
    int i,j;
	for(i=0;i<MazeScale;i++)
	{
		for(j=0;j<MazeScale;j++)
		{
			if(maze[i][j]==2)
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	PosType start;
	PosType end;
	start.x = 1;
	start.y = 1;
	end.x = 8;
	end.y = 8;
	MazePath(maze,start,end);
	for(i=0;i<MazeScale;i++)
	{
		for(j=0;j<MazeScale;j++)
		{
			if(maze[i][j]==2)
			{
				printf("#");
			}
			else if(maze[i][j]==1)
			{
				printf(".");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
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

Status MazePath(MazeType maze,PosType start,PosType end)
{
	MyStack S;
	InitStack(&S);
	int cusStep = 1;
	PosType curPos = start;
	do
	{
		if(Pass(curPos))
		{
			FootPrint(curPos);
			SElemType e;
			e.di = 1;
			e.ord = cusStep;
			e.seat = curPos;
			Push(&S,e);
			if(e.seat.x==end.x&&e.seat.y==end.y)
			{
				break;
			}
			curPos = NextPos(curPos,e.di);
			cusStep++;
		}
		else
		{
			cusStep--;
			SElemType e;
			Pop(&S,&e);
			while(e.di==4&&!StackEmpty(S))
			{
				MarkPrint(e.seat);
				Pop(&S,&e);
				cusStep--;
			}
			if(e.di<4)
			{
				curPos = NextPos(e.seat,e.di+1);
				e.di++;
				cusStep++;
				Push(&S,e);
			}
		}
	}while(!StackEmpty(S));
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
			nextPos.x = pos.x;
			nextPos.y = pos.y+1;
			break;
		case 2:
			nextPos.x = pos.x+1;
			nextPos.y = pos.y;
			break;
		case 3:
			nextPos.x = pos.x;
			nextPos.y = pos.y-1;
		case 4:
			nextPos.x = pos.x-1;
			nextPos.y = pos.y;
	}
	return nextPos;
}

Status MarkPrint(PosType pos)
{
	maze[pos.x][pos.y] = -1;
	return OK;
}









>>>>>>> Stashed changes
