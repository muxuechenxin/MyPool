#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
//顺序存储实现
#define MAXSIZE 20
typedef int ElementType;
typedef struct SNode* Stack;
typedef struct SNode {
	ElementType Data[MAXSIZE];
	int Top;
}SNode;
void Push(Stack PtrS, ElementType item)
{
	if (PtrS->Top == MAXSIZE - 1) {
		printf("Stack is full"); return;
	}
	else {
		PtrS->Data[++(PtrS->Top)] = item;
		return;
	}
}

int Pop(Stack PtrS)
{
	if (PtrS->Top == -1) {
		printf("Stack is empty"); return 0;
	}
	else {
		return (PtrS->Data[(PtrS->Top)--]);
	}
}

void Myprintf(Stack PtrS)
{
	while (PtrS->Top!=-1)
	{
		printf("%d  ", PtrS->Data[(PtrS->Top--)]);
	}
}

int main()
{
	int x = 1;
	Stack PtrS=(Stack)malloc(sizeof(SNode));
	PtrS->Top = -1;
	while (1)
	{
		scanf("%d", &x);
		if (x == 0)break;
		Push(PtrS, x);
	}

	Myprintf(PtrS);
	return 0;
}

*/



//链式存储//单向链表的头作为top！！！
typedef int ElementType;
typedef struct SNode* Stack;
typedef struct SNode {
	ElementType Data;
	Stack Next;
}SNode;

Stack CreateS()
{
	Stack S = (Stack)malloc(sizeof(SNode));
	S->Next = NULL;
	return S;
}

int IsEmpty(Stack S)
{
	return (S->Next == NULL);
}


void Push(ElementType item, Stack S)//把元素item压入堆栈里面去
{
	Stack TmpCell = (Stack)malloc(sizeof(SNode));
	TmpCell->Data = item;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
}

int Pop(Stack S)//删除并返回堆栈s的栈顶元素
{
	Stack FirstCell;
	int top;
	if (IsEmpty(S)) {
		printf("Stack is empty"); return NULL;
	}
	else {
		FirstCell = S->Next;
		S->Next = FirstCell->Next;
		top = FirstCell->Data;
		free(FirstCell);
		return top;
	}
}

void Myprintf(Stack S)
{
	while (S->Next)
	{
		S = S->Next;
		printf("%d", S->Data);
	}
}

int main()
{
	Stack S = CreateS();
	int x;
	while (1)
	{
		scanf("%d", &x);
		if (x == 0)break;
		Push(x,S);
	}

	Myprintf(S);

	return 0;
}