#include "singly.h"

/* We will be using singly linked lists for stack, all of the functions can be found in the linked list folder */

/* All of the functions included in the singly.h file can be used here
 * append, pop, count, index, contains, clear, peekfirst, peeklast, remove, insert, delete, print */

void push(linkedList *, int);
int peek(linkedList *);
linkedList *createStack();
void printStack();

void push(linkedList *linkedListo, int data)
{
	append(linkedListo, data);
}

int peek(linkedList *linkedListo)
{
	return peekLast(linkedListo);
}

linkedList *createStack()
{
	linkedList *stack = createLinkedList();
	return stack;
}

void printStack(linkedList *linkedListo)
{
	printLinkedList(linkedListo);
}

int main()
{
	return 0;
}
