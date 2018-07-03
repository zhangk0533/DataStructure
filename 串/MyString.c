#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 256
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Bool;

typedef struct MyString_t {
	int length;
	char str[MAX_STRLEN+1];
} SString;

Status StrAssign(SString* T,char* chars);
Status StrCopy(SString* T,SString S);
Status ClearString(SString* S);
Bool StringEmpty(SString S);
int StrLength(SString S);
Bool StrCompare(SString S,SString L);
Status SubString(SString Sub,SString S,int pos,int len);
int Index(SString S,SString T,int pos);
Status StrInsert(SString S,SString T,int pos);
Status StrDelete(SString S,int pos,int len);


Status StrAssign(SString* T,char* chars)
{
	if (T->length>1) {
		T->str[0] = 0;
		T->str[1] = '\0';
	}	
	int len = strlen(chars);
	int i;
	for (i = 0; i < len; ++i) {
		T->str[i] = chars[i];
	}
	return OK;	
}

Status StrCopy(SString* T,SString S)
{
	int i;
	for (i = 0; i < S.length; ++i) {
		T->str[i] = S.str[i];
	}
	return OK;
}

Status ClearString(SString* S)
{
	S->length = 0;
	return OK;
}

Bool StringEmpty(SString S)
{
	if (S.length==0) {
		return TRUE;
	}
	return FALSE;	
}

int StrLength(SString S)
{
	return S.length;
}




