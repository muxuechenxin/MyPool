#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//循环链表
typedef struct Node {
	int data;
	struct Node* pre;
	struct Node* next;
 }Node;

Node* initList() {
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->pre = L;
	L->next = L;
	return L;
}


void headInsert(Node* L, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	if (L->data == 0) {
		//链表为空
		node->pre = L;
		node->next = L->next;
		L->next = node;
		L->pre = node;

	}
	else {
		//链表不为空
		node->next = L->next;
		L->next->pre = node;
		L->next = node;
		node->pre = L;
	}
	L->data++;
}

void tailInsert(Node* L, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	Node* n = L->next;
	while (n->next != L) {
		n = n->next;
	}
	node->data = data;
	
	node->pre = n;
	node->next = L;
	L->pre = node;
	n->next = node;
	L->data++;
}

void printList(Node* L) {
	Node* node = L->next;
	while (node != L) {
		printf("%d -> ", node->data);
		node = node->next;
	}
	printf("NuLL\n");
}

int delete(Node* L, int data) {
	Node* node = L->next;
	while (node != L) {
		if (node->data == data) {
			node->pre->next = node->next;
			node->next->pre = node->pre;
			free(node);
			L->data--;
			return 1;
		}
		node = node->next;
	}
	return 0;
}

int main()
{
	Node* L = initList();
	headInsert(L, 1);
	headInsert(L, 2);
	headInsert(L, 3);
	headInsert(L, 4);

	tailInsert(L, 0);
	tailInsert(L, -1);
	tailInsert(L, -2);

	printf("%d\n", L->data);
	
	printList(L);

	delete(L, 2);
	delete(L, 3);
	delete(L, 4);

	printf("%d\n", L->data);
	printList(L);

	return 0;
}