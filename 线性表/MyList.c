#include <stdio.h>
#include <stdlib.h>

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
	return 0;
}




