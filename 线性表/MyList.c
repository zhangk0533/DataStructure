#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define LIST_INIT_SIZE 100  //���Ա�洢�ռ�ĳ�ʼ������ 
#define LISTINCREMENT 10  //���Ա�洢�ռ�ķ������� 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef int Status;

typedef struct{
	int *elem;  //�洢�ռ��ַ 
	int length;  //��ǰ���� 
	int listsize;  //��ǰ����Ĵ洢����(��sizeof(int)Ϊ��λ) 
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


