#include <stdio.h>
#include <stdlib.h>
#define CLEARKEY 0

typedef struct dynamicArray
{
	int *array;
	int arraylen;
} dynamicArray;

/* Methods 
 * append
 * extend
 * remove
 * insert
 * pop*/

/* Note, implement this for also lists with strings. Also implement string operations */

void append(dynamicArray*, int);
void extend(dynamicArray*, dynamicArray*);
void remove_elem(dynamicArray*, int);
void insert(dynamicArray*, int);
void pop(dynamicArray*);
void clear(dynamicArray);
dynamicArray form_array(int);
void print_dynamic_array(dynamicArray);

void print_dynamic_array(dynamicArray dynamicArray)
{
	int arraylen = dynamicArray.arraylen, i;
	for (i = 0; i < arraylen; i++)
	{
		printf("%d ", dynamicArray.array[i]);
	}
	printf("\n");
}

dynamicArray form_array(int val)
{
	dynamicArray ptr;
	ptr.array = malloc(sizeof(int));
	ptr.arraylen = 1;
	ptr.array[0] = val;
	return ptr;
}

void append(dynamicArray *dynamic_array, int val)
{
	int i, arraylen = dynamic_array[0].arraylen, *ptr = malloc((arraylen + 1) * sizeof(int)), *handle = dynamic_array[0].array;
	for (i = 0; i < arraylen; i++)
	{
		ptr[i] = handle[i];
	}
	ptr[arraylen] = val;
	dynamic_array[0].arraylen = arraylen+1;
	dynamic_array[0].array = ptr;
	free(handle);
}

void extend(dynamicArray *dynamic_array_host, dynamicArray *dynamic_array_guest)
{
	int arraylen1 = dynamic_array_host[0].arraylen, arraylen2 = dynamic_array_guest[0].arraylen, i, *handle = dynamic_array_host[0].array, *ptr = malloc((arraylen1 + arraylen2) * sizeof(int));
	for (i = 0; i < arraylen1; i++)
	{
		ptr[i] = dynamic_array_host[0].array[i];
	}
	for (i = 0; i < arraylen2; i++)
	{
		ptr[i+arraylen1] = dynamic_array_guest[0].array[i];
	}
	dynamic_array_host[0].arraylen = arraylen1 + arraylen2;
	dynamic_array_host[0].array = ptr;
	free(handle);
}

void remove_elem(dynamicArray* dynamic_array, int remove_val)
{
	int arraylen = dynamic_array[0].arraylen, i;
	for (i = 0; i < arraylen; i++)
	{
		i
	}
}

int main()
{
	dynamicArray array2 = form_array(30);
	dynamicArray array = form_array(10);
	append(&array, 15);
	append(&array, 20);
	append(&array2, 40);
	print_dynamic_array(array);
	print_dynamic_array(array2);
	extend(&array, &array2);
	print_dynamic_array(array);
	print_dynamic_array(array2);
	/* Don't  forget to free the dynamic arrays */
	free(array.array);
	free(array2.array);
	return 0;
}

void clear(dynamicArray dynamic_array)
{
	int i;
	for (i = 0; i < dynamic_array.arraylen; i++)
	{
		dynamic_array.array[i] = CLEARKEY;
	}
}
