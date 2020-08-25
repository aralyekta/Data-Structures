#include <stdio.h>
#include <stdlib.h>
#define LEN(linkedListPtr) (linkedListPtr)->length
#define HEAD(linkedListPtr) (linkedListPtr)->head
#define TAIL(linkedListPtr) (linkedListPtr)->tail
#define DATA(nodePtr) (nodePtr)->data
#define NEXT(nodePtr) (nodePtr)->next
#define PREV(nodePtr) (nodePtr)->previous

/* Our functions are
 * print, append, pop, count, index, insert, remove, delete */

/* Structs used below */

/* Struct for a node */
typedef struct node
{
	int data;
	struct node* next, *previous;
} node;

/* Struct for the linked list */
typedef struct linkedList
{
	node *head, *tail;
	int length;
} linkedList;

/* Structs used above */

node *createNode(int); 
linkedList *createLinkedList();
void freeNode(node *);
void printLinkedList(linkedList *);
void append(linkedList *, int); 
int pop(linkedList *);
int count(linkedList *, int);
int index(linkedList *, int);
void insert(linkedList *, int, int);
void removeNode(linkedList *, int);
void delete(linkedList *, int);

node *createNode(int data)
{
	node *nodePtr = malloc(sizeof(node)); /* Don't forget to free this malloc when removing or deleting nodes */
	DATA(nodePtr) = data;
	NEXT(nodePtr) = NULL;
	PREV(nodePtr) = NULL;
	return nodePtr;
}

linkedList *createLinkedList()
{
	linkedList *linkedListo = malloc(sizeof(linkedList)); /* Don't forget to free the linked list after done */
	HEAD(linkedListo) = NULL;
	TAIL(linkedListo) = NULL;
	LEN(linkedListo) = 0;
	return linkedListo;
}

void printLinkedList(linkedList *linkedListo)
{
	int i, len = LEN(linkedListo);
	node *currentNode = HEAD(linkedListo);
	if (len == 0)
	{
		printf("The linked list doesn't have any elements\n");
	}
	else
	{
		for (i = 0; i < len; i++)
		{
			/* Print all elements iteratively and move the pointer forward */
			printf("%d ", DATA(currentNode));
			currentNode = NEXT(currentNode);
		}
		printf("\n%d\n", LEN(linkedListo));
	}
}

void append(linkedList *linkedListo, int data)
{
	node *nodeToAdd;
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
		PREV(nodeToAdd) = TAIL(linkedListo);
		TAIL(linkedListo) = nodeToAdd;
		LEN(linkedListo)++;
	}
}

int pop(linkedList *linkedListo)
{
	int len = LEN(linkedListo), valToReturn;
	node *nodePtr;
	if (len == 0)
	{
		printf("The linked list doesn't have any elements\n");
		return -1;
	}
	else
	{
		valToReturn = DATA(TAIL(linkedListo)); /* Store the value to be returned */
		if (len == 1) /* If the linked list has only one node, simply free it and set the pointers of the linked list to null */
		{
			free(HEAD(linkedListo));
			HEAD(linkedListo) = NULL;
			TAIL(linkedListo) = NULL;
			LEN(linkedListo)--;
		}
		else /* If the linked list has multiple nodes, do the regular pop */
		{
			nodePtr = PREV(TAIL(linkedListo));
			NEXT(nodePtr) = NULL;
			free(TAIL(linkedListo));
			TAIL(linkedListo) = nodePtr;
			LEN(linkedListo)--;
		}
		return valToReturn;
	}
}

int count(linkedList *linkedListo, int data)
{
	int counter = 0, i, len = LEN(linkedListo);
	node *nodePtr = HEAD(linkedListo);
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
	node *nodePtr = HEAD(linkedListo);
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
	node *nodePtr, *nodeToAdd, *nodePtr2;
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
		PREV(HEAD(linkedListo)) = nodeToAdd;
		HEAD(linkedListo) = nodeToAdd;
		LEN(linkedListo)++;
	}
	else if (index >= len) /* If the index to insert is beyond the last element, simply append */
	{
		append(linkedListo, data);
	}
	else /* Index to insert is between the first and the last node (not included), and the linked list has multiple nodes (because the last 2 cases handle all of the linked lists with one node)*/
	{
		if (index <= len/2) /* Move forward from the head if the index to insert is in the first half */
		{
			nodePtr = HEAD(linkedListo);
			for (i = 1; i < index; i++, nodePtr = NEXT(nodePtr));
			nodePtr2 = NEXT(nodePtr);
			nodeToAdd = createNode(data);
			NEXT(nodePtr) = nodeToAdd;
			PREV(nodeToAdd) = nodePtr;
			NEXT(nodeToAdd) = nodePtr2;
			PREV(nodePtr2) = nodeToAdd;
			LEN(linkedListo)++;
		}
		else /* Move backward from the tail if the index to insert is in the second half */
		{
			nodePtr = TAIL(linkedListo);
			for (i = len-1; i > index; i--, nodePtr = PREV(nodePtr));
			nodePtr2 = PREV(nodePtr);
			nodeToAdd = createNode(data);
			PREV(nodePtr) = nodeToAdd;
			NEXT(nodeToAdd) = nodePtr;
			PREV(nodeToAdd) = nodePtr2;
			NEXT(nodePtr2) = nodeToAdd;
			LEN(linkedListo)++;
		}
	}
}

void removeNode(linkedList *linkedListo, int data)
{
	int len = LEN(linkedListo);
	node *nodePtr, *nodePtr2;
	if (len == 0) /* Check if the linked list is empty */
	{
		printf("Linked list doesn't have any elements\n");
		return;
	}
	else if (len == 1) /* Check if the linked list has only one node */
	{
		if (DATA(HEAD(linkedListo)) == data) /* Check if the only node is the value to be removed */
		{
			pop(linkedListo);
			return;
		}
		else /* If the only node isn't the value to be removed */
		{
			printf("The element doesn't exist in the linked list\n");
			return;
		}
	}
	else /* Linked list has multiple nodes */
	{
		nodePtr = HEAD(linkedListo);
		while (nodePtr && DATA(nodePtr) != data) /* Move iteratively until finding the value */
		{
			nodePtr = NEXT(nodePtr);
		}
		if (nodePtr == HEAD(linkedListo)) /* Case1: The data is at the beginning of the linked list */
		{
			nodePtr2 = NEXT(nodePtr);
			PREV(nodePtr2) = NULL;
			free(nodePtr);
			HEAD(linkedListo) = nodePtr2;
			LEN(linkedListo)--;
		}
		else if (nodePtr == TAIL(linkedListo)) /* Case2: The data is at the end of the linked list */
		{
			nodePtr2 = PREV(nodePtr);
			NEXT(nodePtr2) = NULL;
			free(nodePtr);
			TAIL(linkedListo) = nodePtr2;
			LEN(linkedListo)--;
		}
		else /* Case3: The data is in the middle of the linked list. */
		{
			nodePtr = PREV(nodePtr);
			nodePtr2 = NEXT(NEXT(nodePtr));
			free(NEXT(nodePtr));
			LEN(linkedListo)--;
			NEXT(nodePtr) = nodePtr2;
			PREV(nodePtr2) = nodePtr;
		}
	}
}

void delete(linkedList *linkedListo, int index)
{
	int len = LEN(linkedListo), i;
	node *nodePtr, *nodePtr2;
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
		if (index < 0) /* Check for erroneous input, this case index is below the bounds */
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
		else if (index >= len) /* Check for erroneous input, this case index is above the bounds */
		{
			printf("Index is out of bounds\n");
		}
		else /* Removal index is in the middle of the linked list */
		{
			if (index < len/2) /* If the index is in the first half of the linked list, move forward from the head */
			{
				nodePtr = HEAD(linkedListo);
				for (i = 0; i < index; i++, nodePtr = NEXT(nodePtr));

			}
			else /* If the index is in the second half of the linked list, move backward from the tail */
			{
				nodePtr = TAIL(linkedListo);
				for (i = len-1; i > index; i--, nodePtr = PREV(nodePtr));
			}
			nodePtr = PREV(nodePtr);
			nodePtr2 = NEXT(NEXT(nodePtr));
			free(NEXT(nodePtr));
			NEXT(nodePtr) = nodePtr2;
			PREV(nodePtr2) = nodePtr;
			LEN(linkedListo)--;
		}
	}
}

int main()
{
	linkedList *linkedListo;
	linkedListo = createLinkedList();
	append(linkedListo, 20);
	append(linkedListo, 30);
	append(linkedListo, 30);
	insert(linkedListo, 0, 0);
	insert(linkedListo, 20, 20);
	insert(linkedListo, 2, 2);
	insert(linkedListo, 4, 4);
	removeNode(linkedListo, 0);
	removeNode(linkedListo, 20);
	removeNode(linkedListo, 20);
	removeNode(linkedListo, 4);
	pop(linkedListo);
	append(linkedListo, 20);
	append(linkedListo, 300);
	insert(linkedListo, 3, 200);
	printLinkedList(linkedListo);
	delete(linkedListo, 0);
	delete(linkedListo, 1);
	delete(linkedListo, 1);
	printLinkedList(linkedListo);
	free(linkedListo);
	/* Don't forget to free the existing linked lists
	 * Also, don't forget to remove all of the nodes to free the mallocs required for them */
	return 0;
}
