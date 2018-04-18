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

int main(int argc, char *argv[]) {
	return 0;
}
