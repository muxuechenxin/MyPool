#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

Node* initList()
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = NULL;
	L->pre = NULL;
	return L;
}

void headInsert(Node* L, int data)
{   Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;

	if (L->next != NULL)
	{
		node->pre = L;
		node->next = L->next; 
		L->next->pre = node;
		L->next = node;
		L->data++;

	}
	else {
		node->next = L->next;
		node->pre = L;
		L->next = node;
		L->data++;
	}
	
}

void tailList(Node* L, int data) {
	Node* node = L;
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	while (node->next) {
		node = node->next;
	}

	n->next = node->next;
	node->next = n;
	n->pre = node;
	L->data++;

}


int delete(Node* L,int data)
{
	Node* node = L->next;
	while (node) {
		if (node->data == data) {
			//É¾³ý
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

void printList(Node* L) {
	Node* node = L->next;
	while (node) {
		printf("%d -> ", node->data);
		node = node->next;
	}
	printf("NULL\n");
}

int main()
{
	Node* L = initList();
	headInsert(L, 1);
	headInsert(L, 2);
	headInsert(L, 3);
	headInsert(L, 4);

	tailList(L, 0);
	tailList(L, -1);
	tailList(L, -2);

	delete(L, 3);
	//delete(L, 5);

	printList(L);
	return 0;
}