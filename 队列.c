#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


//受操作约束的线性表。一端出，另一端入；Queue
//一般而言，队列其实在逻辑上是一个环状的
// 
// 
 /*其实很不方便的一点就是当空和满的时候，front == rear恒成立，
 也就是说无法判断空或满，那么就需要俩种办法
 1.使用额外的标记 size或者tag，增size++，减size--,
 增tag=1，减tag=0，tag代表最后一次操作是增还是减
 2.只使用n-1的数组空间*/
 
 /*
//顺序存储方式
#define MaxSize 20
typedef int ElementType;
typedef struct Queue* Queue;
typedef struct Queue {
	ElementType Data[MaxSize];
	int front;
	int rear;
}QNode;
//Queue CreatQueue(int MaxSize); //:生成长度为MaxSize的空队列;
//int IsFulIQ(Queue Q, int MaxSize); //:判断队列Q是否已满;
void AddQ(Queue Q, ElementType item);// :将数据元素item插入队列Q中;
int IsEmptyQ(Queue Q);// :判断队列Q是否为空;
ElementType DeleteQ(Queue Q);// :将队头数据元素从队列中删除并返回。


void AddQ(Queue PtrQ, ElementType item)
{
	if ((PtrQ->rear + 1) % MaxSize == PtrQ->front) {
		printf("Queue is full");
		return;
	}
	PtrQ->rear = (PtrQ->rear + 1) % MaxSize;
	PtrQ->Data[PtrQ->rear] = item;
}

ElementType DeleteQ(Queue PtrQ)
{
	if (PtrQ->front == PtrQ->rear)
	{
		printf("empty"); return;
	}
	else {
		PtrQ->front = (PtrQ->front + 1) % MaxSize;
		return PtrQ->Data[PtrQ->front];
	}
}

void Myprintf(Queue Q)
{
	if (Q->front == Q->rear) {
		printf("Queue is empty");
		return;
	}
	int i = Q->front+1;
	while (i != Q->rear+1) { // 当i指向队尾时停止遍历
		printf("%d ", Q->Data[i]); // 输出队列元素
		i = (i + 1) % MaxSize; // 将i后移一位
	}
	printf("\n");
}

int main()
{
	Queue PtrQ=(Queue)malloc(sizeof(QNode));
	PtrQ->front = 0;
	PtrQ->rear = 0;
	int x;
	while (1)
	{
		scanf("%d", &x);
		if (x == 0) {
			break;
		}
		AddQ(PtrQ, x);
	}

	printf("是否要出队");
	scanf("%d", &x);
	if (x == 1)
	{
		DeleteQ(PtrQ);
	}

	Myprintf(PtrQ);

	return 0;
}

*/



//链式存储
//同样，front只能在表头，而rear也只能在尾巴，因为尾巴增加容易，但是删除难
typedef int ElementType;
typedef struct QNode* Queue;

typedef struct Node {
	ElementType Data;
	struct Node* Next;
}Node;

typedef struct QNode {
	Node* rear;
	Node* front;
}QNode;


Queue init_queque()
{
	Queue Q=(Queue)malloc(sizeof(QNode));
	Q->front = Q->rear = NULL;
	return Q;
}

int is_empty(Queue Q)
{
	return Q->front == NULL;
}

void AddQ(Queue Q, ElementType x)
{
	Node* new = (Node*)malloc(sizeof(Node));
	if (!new) {
		printf("内存分配失败"); return;
	}
	new->Data = x;
	new->Next = NULL;
	if (is_empty(Q)) {
		Q->front=Q->rear = new;
	}
	else {
		Q->rear->Next = new;
		Q->rear = new;
	}
}

int DeleteQ(Queue Q)
{
	ElementType FrontELem;
	if (is_empty(Q)) {
		printf("empty");
		return 0;
	}
	Node* FrontCell = Q->front;
	if (Q->front == Q->rear) {
		Q->front = Q->rear = NULL;
	}
	else {
		Q->front = Q->front->Next;
		
	}
	FrontELem = FrontCell->Data;
	free(FrontCell);
	return FrontELem;
}


void Myprintf(Queue Q)
{
	if (is_empty(Q)) {
		printf("empty");
		return;
	}
	while (Q->front)
	{
		printf("%d  ", Q->front->Data);
		Q->front = Q->front->Next;
	}
}
int main()
{
	Queue Q = init_queque();

	//if (is_empty(Q)) printf("empty\n");


	int x;
	while (1) {
		scanf("%d", &x);
		if (x == 0) break;
		AddQ(Q, x);
	}

	printf("是否要出队");
	scanf("%d", &x);
	if (x == 1) DeleteQ(Q);

	Myprintf(Q);
	return 0;
}