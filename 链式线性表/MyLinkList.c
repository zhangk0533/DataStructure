#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef int Status;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,* LinkList;

Status GetElem(LinkList L,int i,int *e);
Status ListInsert(LinkList *L,int i,int e);
Status ListDelete(LinkList *L,int i,int *e);
void CreateList(LinkList *L,int n);
void MergeList(LinkList *La,LinkList *Lb,LinkList *Lc);
void TraverseLinkList(LinkList L);

int main(int argc, char *argv[]) {
	
	LinkList L;
	CreateList(&L,4);
	TraverseLinkList(L);
	//ListInsert(&L,5,5);
	//TraverseLinkList(L);
	int e;
//	ListDelete(&L,4,&e);
//	TraverseLinkList(L);
//	printf("%d",e);
	GetElem(L,3,&e);
	printf("%d",e);
	return 0;
}

Status GetElem(LinkList L,int i,int *e)
{
	LNode *p = L;
	int j=0;
	while(p&&j<i)
	{
		p = p->next;
		j++;
	}
	(*e) = p->data;
	return OK;
}

Status ListInsert(LinkList *L,int i,int e)
{
	LinkList p = (*L);
	int j=0;
	while(p&&j<i-1)
	{
		p = p->next;
		j++;
	}
	LinkList newNode = (LinkList)malloc(sizeof(LNode));
	if(newNode==NULL)
	{
		return ERROR; //申请内存失败
	}
	newNode->data = e;
	newNode->next = p->next;
	p->next = newNode;
	return OK;
}

Status ListDelete(LinkList *L,int i,int *e)
{
	LinkList p = (*L);
	int j = 0;
	while(p->next&&j<i-1)
	{
		p = p->next;
		j++;
	}
	LinkList q = p->next;
	(*e) = q->data;
	p->next = q->next;
	return OK;
	free(q);
}

void CreateList(LinkList *L,int n)
{
	(*L) = NULL;
	(*L) = (LinkList)malloc(sizeof(LNode));
	LinkList pTrail = (*L);
	int i;
	for(i=0;i<n;i++)
	{
		LinkList pNew = (LinkList)malloc(sizeof(LNode));
		int val;
		printf("请输入第%d个数:",i+1);
		scanf("%d",&val);
		pTrail->next = pNew;
		pNew->data = val;
		pNew->next = NULL;
		pTrail = pNew;
	}
}

void TraverseLinkList(LinkList L)
{
	LinkList p = L->next;
	while(p!=NULL)
	{
		printf("%d",p->data);
		p = p->next;
	}
	putchar('\n');
}


































