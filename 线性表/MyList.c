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
Status compare(int a,int b);
int LocateElem(MyList L,int e);
void MergeList(MyList La,MyList Lb,MyList *Lc);
Status DestoryList(MyList *L);
Status ClearList(MyList *L);
bool ListEmpty(MyList L);
int ListLength(MyList L);
Status GetItem(MyList L,int i,int *e);
Status PriorElem(MyList L,int cur_e,int *pre_e);
Status NextElem(MyList L,int cur_e,int *next_e);



int main(int argc, char *argv[]) {
	MyList L;
	InitList(&L);
	int i=0;
	ListInsert(&L,1,1);
	ListInsert(&L,2,2);
	//printf("%d",*(L.elem+1));
	printf("%d",*L.elem);
	printf("%d",*(L.elem+1));
	int j = LocateElem(L,2);
	printf("%d",j);
	return 0;
}

Status InitList(MyList *L)
{
	L->elem = (int *)(malloc(sizeof(int)*LIST_INIT_SIZE));
	if(L->elem==NULL) return OVERFLOW;
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

Status ListInsert(MyList *L,int i,int e)
{
	if(i<1||i>L->length+1) return ERROR;
	if(L->length>=L->listsize)
	{
		int *newbase = (int *)(realloc(L->elem,sizeof(int)*(LIST_INIT_SIZE+LISTINCREMENT)));
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}
	int *q;
	int *p = L->elem+i -1;
	for(q=L->elem+L->length-1;q>=p;q--)
	{
		*(q+1) = *q;
	}
	*p = e;
	++L->length; 
	return OK;
}

Status ListDelete(MyList *L,int i,int *e)
{
	if(i<1||i>L->length) return ERROR;
	int *q = L->elem+i;
	*e = *q;
	for(++q;q<L->elem+L->length;q++)
	{
		*q = *(q+1);
	}
	--L->length;
	return OK;
}

Status compare(int a,int b)
{
 	if(a==b)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

int LocateElem(MyList L,int e)
{
	int *p = L.elem; 
	int i = 1;
	while(i<=L.length&&!compare(e,*p++))
	{
		++i;
	}
	if(i<=L.length)
	{
		return i;
	}
	else
	{
		return 0;
	}
}

void MergeList(MyList La,MyList Lb,MyList *Lc)
{
	
	La.elem;
	return ERROR; 
	
} 

Status DestoryList(MyList *L)
{
	L->length = 0;
	L->listsize = 0;
	free(L->elem);
	L->elem = NULL;
	return OK;
}

Status ClearList(MyList *L)
{
	L->length = 0;
	return OK;
}

bool ListEmpty(MyList L)
{
	if(L.length==0)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

int ListLength(MyList L)
{
	return L.length;
}

Status GetItem(MyList L,int i,int *e)
{
	if(i>L.length)
	{
		return OVERFLOW;
	}
	*e = *(L.elem+i-1);
	return OK;
}

Status PriorElem(MyList L,int cur_e,int *pre_e)
{
	//if()
}








