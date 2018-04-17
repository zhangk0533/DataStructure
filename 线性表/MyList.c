#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define LIST_INIT_SIZE 100  //线性表存储空间的初始分配量 
#define LISTINCREMENT 10  //线性表存储空间的分配增量 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef int Status;

typedef struct{
	int *elem;  //存储空间基址 
	int length;  //当前长度 
	int listsize;  //当前分配的存储容量(以sizeof(int)为单位) 
}MyList;

Status InitList(MyList *L);
Status ListInsert(MyList *L,int i,int e);
Status ListDelete(MyList *L,int i,int *e);

int main(int argc, char *argv[]) {
	MyList L;
	InitList(&L);
	int i=0;
	ListInsert(&L,0,1);
	ListInsert(&L,1,2);
	printf("%d",*(L.elem+1));
	return 0;
}

Status InitList(MyList *L)
{
	L->elem = (int *)(malloc(sizeof(int)*LIST_INIT_SIZE));
	if(L->elem==NULL) return ERROR;
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
}

Status ListInsert(MyList *L,int i,int e)
{
	if(i<0||i>L->length+1) return ERROR;
	if(L->length==LIST_INIT_SIZE)
	{
		int *newbase = (int *)(realloc(L->elem,sizeof(int)*(LIST_INIT_SIZE+LISTINCREMENT)));
		L->elem = newbase;
	}
	int *q;
	int *p = L->elem+i;
	for(q=L->elem+L->length;q>=p;q--)
	{
		*(q+1) = *q;
	}
	*p = e;
	return OK;
}

Status ListDelete(MyList *L,int i,int *e)
{
	if(i<0||i>L->length+1) return ERROR;
	int *q = L->elem+i;
	*e = *q;
	for(++q;q<L->elem+L->length;q++)
	{
		*q = *(q+1);
	}
	return OK;
}


