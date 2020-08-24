#include <stdio.h>
#include <stdlib.h>
#define LEN(linkedListPtr) (linkedListPtr)->length
#define HEAD(linkedListPtr) (linkedListPtr)->head
#define TAIL(linkedListPtr) (linkedListPtr)->tail
#define DATA(NodePtr) (NodePtr)->data
#define NEXT(NodePtr) (NodePtr)->next

/* Our methods are
 * print, append, count, index, insert, remove, pop, delete */

/* Here are the structs used */

/* Struct for a node */
typedef struct Node
{
	int data;
	struct Node *next;
} Node;

/* Struct for the linked list */
typedef struct linkedList
{
	Node *head;
	Node *tail;
	int length;
}linkedList;

linkedList *createLinkedList(int);
void printLinkedList(linkedList *);
void append(linkedList *, int);
Node *createNode(int);
void pop(linkedList *);

Node *createNode(int data)
{
	Node *Node = malloc(sizeof(Node));
	Node->data = data;
	Node->next = NULL;
	return Node;
}

void printLinkedList(linkedList *linkedList)
{
	int i, len = LEN(linkedList);
	Node *currentNode = HEAD(linkedList);
	for (i = 0; i < len; i++)
	{
		printf("%d ", DATA(currentNode));
		currentNode = NEXT(currentNode);
	}
	printf("\n");
}

linkedList *createLinkedList(int data)
{
	Node *Node = createNode(data);
	linkedList *linkedList = malloc(sizeof(linkedList));
	HEAD(linkedList) = Node;
	TAIL(linkedList) = Node;
	LEN(linkedList) = 1;
	return linkedList;
}

void append(linkedList *linkedList, int data)
{
	Node *Node;
	if (LEN(linkedList) == 0)
	{
		linkedList = createLinkedList(data);
		return;
	}
	Node = createNode(data);
	NEXT(TAIL(linkedList)) = Node;
	TAIL(linkedList) = Node;
	LEN(linkedList)++;
}

void pop(linkedList *linkedList)
{
	
}

int main()
{
	linkedList *linkedList;
	linkedList = createLinkedList(10);
	printLinkedList(linkedList);
	return 0;
}
