#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100  //�洢�ռ��ʼ������
#define STACKINCREMENT 10  //�洢�ռ�������� 

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
Status Push(MyStack *S,int *e);
Status Pop(MyStack *S,int e);
//Status StackTraverse(MyStack S,)


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	return 0;
}
