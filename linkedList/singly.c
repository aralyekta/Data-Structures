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
} linkedList;

void freeNode(Node *);
linkedList *createLinkedList(int);
void printLinkedList(linkedList *);
void append(linkedList *, int);
Node *createNode(int);
int pop(linkedList *);
int count(linkedList *, int);
int index(linkedList *, int);
void insert(linkedList *, int, int);
void removeNode(linkedList *, int);
void delete(linkedList *, int);

Node *createNode(int data)
{
	Node *Node = malloc(sizeof(Node));
	Node->data = data;
	Node->next = NULL;
	return Node;
}

void printLinkedList(linkedList *linkedListo)
{
	int i, len = LEN(linkedListo);
	Node *currentNode = HEAD(linkedListo);
	if (len == 0)
	{
		printf("The linked list doesn't have any elements\n");
		return;
	}
	for (i = 0; i < len; i++)
	{
		printf("%d ", DATA(currentNode));
		currentNode = NEXT(currentNode);
	}
	printf("\n%d\n", LEN(linkedListo));
}

linkedList *createLinkedList(int data)
{
	Node *Node = createNode(data);
	linkedList *linkedListo = malloc(sizeof(linkedList));
	HEAD(linkedListo) = Node;
	TAIL(linkedListo) = Node;
	LEN(linkedListo) = 1;
	return linkedListo;
}

void append(linkedList *linkedListo, int data)
{
	Node *nodeToAdd;
	if (LEN(linkedListo) == 0)
	{
		nodeToAdd = createNode(data);
		HEAD(linkedListo) = nodeToAdd;
		TAIL(linkedListo) = nodeToAdd;
		LEN(linkedListo) = 1;
	}
	else
	{
		nodeToAdd = createNode(data);
		NEXT(TAIL(linkedListo)) = nodeToAdd;
		TAIL(linkedListo) = nodeToAdd;
		LEN(linkedListo)++;
	}
}


int pop(linkedList *linkedListo)
{
	int val, i, len = LEN(linkedListo);
	Node *nodePtr;
	if (len == 0)
	{
		printf("The linked list doesn't have any elements\n");
		return -1;
	}
	else if (len == 1)
	{
		val = DATA(TAIL(linkedListo));
		free(HEAD(linkedListo));
		HEAD(linkedListo) = NULL;
		TAIL(linkedListo) = NULL;
		LEN(linkedListo)--;
		return val;
	}
	else
	{
		val = DATA(TAIL(linkedListo));
		nodePtr = HEAD(linkedListo);
		for (i = 1; i < len; i++, nodePtr = NEXT(nodePtr));
		TAIL(linkedListo) = nodePtr;
		nodePtr = NEXT(nodePtr);
		NEXT(TAIL(linkedListo)) = NULL;
		free(nodePtr);
		LEN(linkedListo)--;
		return val;
	}
}

int count(linkedList *linkedListo, int data)
{
	int counter = 0, i, len = LEN(linkedListo);
	Node *nodePtr = HEAD(linkedListo);
	for (i = 0; i < len; i++)
	{
		if (DATA(nodePtr) == data)
		{
			counter++;
		}
		nodePtr = NEXT(nodePtr);
	}
	return counter;
}

int index(linkedList *linkedListo, int data)
{
	int index = -1, i, len = LEN(linkedListo);
	Node *nodePtr = HEAD(linkedListo);
	for (i = 0; i < len; i++)
	{
		if (DATA(nodePtr) == data)
		{
			index = i;
			return index;
		}
		nodePtr = NEXT(nodePtr);
	}
	return index;
}

void insert(linkedList *linkedListo, int index, int data)
{
	Node *nodePtr, *nodeToAdd;
	int len = LEN(linkedListo), i;
	if (index < 0)
	{
		printf("Index must be 0 or positive\n");
	}
	else if (len == 0)
	{
		append(linkedListo, data);
	}
	else if (index == 0)
	{
		nodeToAdd = createNode(data);
		NEXT(nodeToAdd) = HEAD(linkedListo);
		HEAD(linkedListo) = nodeToAdd;
		LEN(linkedListo)++;
	}
	else if (index >= len)
	{
		append(linkedListo, data);
	}
	else
	{
		if (len == 1)
		{
			append(linkedListo, data);
		}
		else
		{
			nodePtr = HEAD(linkedListo);
			for (i = 1; i < index; i++, nodePtr = NEXT(nodePtr));
			nodeToAdd = createNode(data);
			NEXT(nodeToAdd) = NEXT(nodePtr);
			NEXT(nodePtr) = nodeToAdd;
			LEN(linkedListo)++;
		}
	}
}

void removeNode(linkedList *linkedListo, int data)
{
	int len = LEN(linkedListo);
	Node *nodePtr, *nodePtr2;
	if (len == 0)
	{
		printf("Linked list doesn't have any elements\n");
		return;
	}
	else if (len == 1)
	{
		if (DATA(HEAD(linkedListo)) == data)
		{
			pop(linkedListo);
			return;
		}
		else
		{
			printf("The element doesn't exist in the linked list\n");
			return;
		}
	}
	else
	{
		nodePtr = HEAD(linkedListo);
		if (DATA(nodePtr) == data)
		{
			HEAD(linkedListo) = NEXT(nodePtr);
			NEXT(nodePtr) = NULL;
			free(nodePtr);
			LEN(linkedListo)--;
		}
		else
		{
			while (NEXT(nodePtr) && DATA(NEXT(nodePtr)) != data)
			{
				nodePtr = NEXT(nodePtr);
			}
			if (nodePtr == TAIL(linkedListo))
			{
				printf("The element doesn't exist in the linked list\n");
			}
			else if (NEXT(nodePtr) == TAIL(linkedListo))
			{
				nodePtr2 = TAIL(linkedListo);
				NEXT(nodePtr) = NULL;
				TAIL(linkedListo) = nodePtr;
				free(nodePtr2);
				LEN(linkedListo)--;
			}
			else
			{
				nodePtr2 = NEXT(nodePtr);
				NEXT(nodePtr) = NEXT(nodePtr2);
				NEXT(nodePtr2) = NULL;
				free(nodePtr2);
				LEN(linkedListo)--;
			}
		}
	}
}

void delete(linkedList *linkedListo, int index)
{
	int len = LEN(linkedListo), i;
	Node *nodePtr, *nodePtr2;
	if (index < 0)
	{
		printf("Index should be 0 or positive\n");
	}
	else if (index == 0)
	{
		nodePtr = NEXT(HEAD(linkedListo));
		NEXT(HEAD(linkedListo)) = NULL;
		free(HEAD(linkedListo));
		HEAD(linkedListo) = nodePtr;
		LEN(linkedListo)--;
	}
	else if (index == len-1)
	{
		pop(linkedListo);
	}
	else if (index >= len)
	{
		printf("Index is out of bounds\n");
	}
	else
	{
		for (i = 1; i < index; i++, nodePtr = NEXT(nodePtr));
		nodePtr2 = NEXT(nodePtr);
		NEXT(nodePtr) = NEXT(nodePtr2);
		NEXT(nodePtr2) = NULL;
		free(nodePtr2);
		LEN(linkedListo)--;
	}
}

int main()
{
	int i;
	linkedList *linkedListo;
	linkedListo = createLinkedList(10);
	for (i = 0; i < 5; i++)
	{
		append(linkedListo, 10*i);
	}
	delete(linkedListo, 0);
	printLinkedList(linkedListo);
	return 0;
}
