#include <stdio.h>
#include <stdlib.h>
#define LEN(linkedListPtr) (linkedListPtr)->length
#define HEAD(linkedListPtr) (linkedListPtr)->head
#define TAIL(linkedListPtr) (linkedListPtr)->tail
#define DATA(NodePtr) (NodePtr)->data
#define NEXT(NodePtr) (NodePtr)->next

/* Our functions are
 * print, append, count, index, insert, remove, pop, delete, clear, contains, peekfirst, peeklast */

/* Structs used below */

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

/* Structs used above */

linkedList *createLinkedList();
void printLinkedList(linkedList *);
void append(linkedList *, int);
Node *createNode(int);
int pop(linkedList *);
int count(linkedList *, int);
int index(linkedList *, int);
void insert(linkedList *, int, int);
void removeNode(linkedList *, int);
void delete(linkedList *, int);
void clear(linkedList *);
int contains(linkedList *, int);
int peekFirst(linkedList *);
int peekLast(linkedList *);

Node *createNode(int data)
{
	Node *nodePtr = malloc(sizeof(Node)); /* Don't forget to free this malloc when removing or deleting nodes */
	DATA(nodePtr) = data;
	NEXT(nodePtr) = NULL;
	return nodePtr;
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
		/* Print all elements iteratively and move the pointer forward */
		printf("%d ", DATA(currentNode));
		currentNode = NEXT(currentNode);
	}
	printf("\n");
}

linkedList *createLinkedList()
{
	linkedList *linkedListo = malloc(sizeof(linkedList)); /* Don't forget to free the linked list after done */
	HEAD(linkedListo) = NULL;
	TAIL(linkedListo) = NULL;
	LEN(linkedListo) = 0;
	return linkedListo;
}

void append(linkedList *linkedListo, int data)
{
	Node *nodeToAdd;
	if (LEN(linkedListo) == 0)
	{
		/* If the linked list is empty, simply set the head and the tail pointers to the new node */
		nodeToAdd = createNode(data);
		HEAD(linkedListo) = nodeToAdd;
		TAIL(linkedListo) = nodeToAdd;
		LEN(linkedListo)++;
	}
	else
	{
		/* If the linked list already has nodes, set the tail's next to it and set the tail to it */
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
	if (len == 0) /* Check if the linked list is empty */
	{
		printf("The linked list doesn't have any elements\n");
		return -1;
	}
	else if (len == 1)
	{ /* The case when the linked list has only one node */
		val = DATA(TAIL(linkedListo));
		free(HEAD(linkedListo));
		HEAD(linkedListo) = NULL;
		TAIL(linkedListo) = NULL;
		LEN(linkedListo)--;
		return val;
	}
	else
	{ /* The regular case, the linked list has multiple nodes */
		val = DATA(TAIL(linkedListo));
		nodePtr = HEAD(linkedListo);
		for (i = 1; i < len-1; i++, nodePtr = NEXT(nodePtr));
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
		/* Move iteratively and increment the counter when searched data is found */
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
		/* Move iteratively and return the index when searched data is found */
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
	if (index < 0) /* Check for erroneous input */
	{
		printf("Index must be 0 or positive\n");
	}
	else if (len == 0) /* If the linked lists doesn't have any elements, simply append */
	{
		append(linkedListo, data);
	}
	else if (index == 0) /* If the index to insert is zero, set its pointer to head and move the head to the new node */
	{
		nodeToAdd = createNode(data);
		NEXT(nodeToAdd) = HEAD(linkedListo);
		HEAD(linkedListo) = nodeToAdd;
		LEN(linkedListo)++;
	}
	else if (index >= len) /* If the index to insert is beyond the last element, simply append */
	{
		append(linkedListo, data);
	}
	else /* Index to insert is between the first and the last node (not included), and the linked list has multiple nodes (because the last 2 cases handle all of the linked lists with one node)*/
	{
		nodePtr = HEAD(linkedListo);
		for (i = 1; i < index; i++, nodePtr = NEXT(nodePtr));
		nodeToAdd = createNode(data);
		NEXT(nodeToAdd) = NEXT(nodePtr);
		NEXT(nodePtr) = nodeToAdd;
		LEN(linkedListo)++;
	}
}

void removeNode(linkedList *linkedListo, int data)
{
	int len = LEN(linkedListo);
	Node *nodePtr, *nodePtr2;
	if (len == 0)
	{
		/* Check if the linked list is empty */
		printf("Linked list doesn't have any elements\n");
		return;
	}
	else if (len == 1) /* Check if the linked list has only one node */
	{
		if (DATA(HEAD(linkedListo)) == data) /* Check if the only node has the value to be removed */
		{
			pop(linkedListo);
			return;
		}
		else /* If the only node doesn't have the value to be removed */
		{
			printf("The element doesn't exist in the linked list\n");
			return;
		}
	}
	else /* Linked list has multiple nodes */
	{
		nodePtr = HEAD(linkedListo);
		if (DATA(nodePtr) == data) /* Check if the value to be removed is in the first node */
		{
			HEAD(linkedListo) = NEXT(nodePtr);
			NEXT(nodePtr) = NULL;
			free(nodePtr);
			LEN(linkedListo)--;
		}
		else /* The value to be removed could be in the next nodes */
		{
			while (NEXT(nodePtr) && DATA(NEXT(nodePtr)) != data) /* Move iteratively until finding the value */
			{
				nodePtr = NEXT(nodePtr);
			}
			if (nodePtr == TAIL(linkedListo)) /* If we moved all the way to the last element, the value to be removed doesn't exist in the linked list */
			{
				printf("The element doesn't exist in the linked list\n");
			}
			else if (NEXT(nodePtr) == TAIL(linkedListo)) /* If the moved all the way to the previous node of the tail, the value to be removed is in the tail node */
			{
				nodePtr2 = TAIL(linkedListo);
				NEXT(nodePtr) = NULL;
				TAIL(linkedListo) = nodePtr;
				free(nodePtr2);
				LEN(linkedListo)--;
			}
			else /* All other cases where we found the value in the middle nodes */
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
	if (len == 0) /* Check if the linked list is empty */
	{
		printf("The linked list doesn't have any elements\n");
	}
	else if (len == 1) /* If the linked list has only one node, simply pop */
	{
		pop(linkedListo);
	}
	else /* The linked list has multiple nodes */
	{
		if (index < 0) /* Check for erroneous input, this case index is way below the bounds */
		{
			printf("Index should be 0 or positive\n");
		}
		else if (index == 0) /* If the removal index is zero, move the head forward while freeing the first node */
		{
			nodePtr = NEXT(HEAD(linkedListo));
			NEXT(HEAD(linkedListo)) = NULL;
			free(HEAD(linkedListo));
			HEAD(linkedListo) = nodePtr;
			LEN(linkedListo)--;
		}
		else if (index == len-1) /* If the removal index points to the last node, simply pop */
		{
			pop(linkedListo);
		}
		else if (index >= len) /* Check for erroneous input, this case index is way above the bounds */
		{
			printf("Index is out of bounds\n");
		}
		else /* Removal index is in the middle of the linked list */
		{
			nodePtr = HEAD(linkedListo);
			for (i = 1; i < index; i++, nodePtr = NEXT(nodePtr));
			nodePtr2 = NEXT(nodePtr);
			NEXT(nodePtr) = NEXT(nodePtr2);
			NEXT(nodePtr2) = NULL;
			free(nodePtr2);
			LEN(linkedListo)--;
		}
	}
}

void clear(linkedList *linkedListo) /* Clears all of the nodes of a linked list */
{
	while (LEN(linkedListo) > 0)
	{
		pop(linkedListo);
	}
}

int contains(linkedList *linkedListo, int data)
{
	int indexFound = index(linkedListo, data);
	if (indexFound != -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int peekLast(linkedList *linkedListo) /* Returns the last node of the linked list */
{
	return DATA(TAIL(linkedListo));
}

int peekFirst(linkedList *linkedListo) /* Returns the first node of the linked list */
{
	return DATA(HEAD(linkedListo));
}
