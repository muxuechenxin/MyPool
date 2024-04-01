#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef struct LNode* LIST;
typedef int ElementType;

typedef struct LNode {
	ElementType Data;
	LIST Next;
}LNode;

LIST Creatlist()
{
	LIST Ptrl=(LIST)malloc(sizeof(LNode));
	Ptrl->Next = NULL;
	return Ptrl;
}

LIST Find(ElementType X, LIST Ptrl)
{
	LIST p = Ptrl;
	while (p && p->Data != X) {
		p = p->Next;
	}
	if (p->Data == X) return p;
	else return NULL;
}


void Delete(LIST Ptrl)
{
	int i;
	printf("请输入你想要删除的序号");
	scanf("%d", &i);
	while (Ptrl && i--)
	{
		Ptrl = Ptrl->Next;
		if (Ptrl)
		{
			printf("查找失败");
			return;
		}
	}
	LIST P_next = Ptrl->Next;
	Ptrl->Next = P_next->Next;
	free(P_next);
}

void Insert(LIST Ptrl)
{
	int i;
	printf("请输入你想要插入的位置序号");
	scanf("%d", &i);
	LIST new = (LIST)malloc(sizeof(LNode));
	printf("请输入数据");
	scanf("%d", &new->Data);
	while (Ptrl&& i--)
	{
		Ptrl = Ptrl->Next;
	}

	new->Next = Ptrl->Next;
	Ptrl->Next = new;
}

void Input_Head( LIST Ptrl)
{
	LIST p = Ptrl->Next;
	LIST new = (LIST)malloc(sizeof(LNode));
	scanf("%d", &new->Data);
	new->Next = p;
	Ptrl->Next = new;
}
void Input_Rear(LIST Ptrl)
{
	LIST rear;
	while (Ptrl->Next)
	{
		Ptrl = Ptrl->Next;
	}
	rear = Ptrl;
	LIST new = (LIST)malloc(sizeof(LNode));
	scanf("%d", &new->Data);
	new->Next = NULL;
	rear->Next = new;
	rear = new;
}

LIST FindKth(int K, LIST Ptrl)
{
	LIST p = Ptrl;
	int i = 1;
	while (p && i < K){
		p = p->Next;
		i++;
	}
	if (i == K) return p;
	else return NULL;
}



int length(LIST Ptrl)
{
	LIST p = Ptrl;
	int j = 0;
	while (p)
	{
		p = p->Next;
		j++;
	}
	return j;
}

void Myprintf(LIST Ptrl)
{
	if (Ptrl==NULL)
	{
		printf("为空表");
		return;
	}
	while (Ptrl)
	{
		Ptrl = Ptrl->Next;
		printf("%d  ", Ptrl->Data);
	}
}

int main()
{
	LIST Ptrl = Creatlist();
	int x;
	int data;
	scanf("%d", &x);
	while (x--)
	{
		Input_Head(Ptrl);
	}


	Myprintf(Ptrl);

	return 0;
}