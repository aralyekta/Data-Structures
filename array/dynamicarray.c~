#include <stdio.h>
#include <stdlib.h>
#define CLEARKEY 0

/* Here are my implementations of dynamic array functions such as append, extend, remove, insert and pop. 
 * This file also includes methods from the static array file. This time, they are implemented regarding the struct dynamicArray. */

typedef struct dynamicArray
{
	int *array;
	int arraylen;
} dynamicArray;


void clear (dynamicArray*);
dynamicArray *copy(dynamicArray*);
int count(dynamicArray*, int);
int index(dynamicArray*, int);
void reverse(dynamicArray*);
void sort(dynamicArray *);
void quicksort(int *, int, int);

void print_array(int *, int);
void append(dynamicArray*, int);
void extend(dynamicArray*, dynamicArray*);
void remove_elem(dynamicArray*, int);
void insert(dynamicArray*, int, int);
int pop(dynamicArray*);
dynamicArray form_array(int);
void print_dynamic_array(dynamicArray);

void print_array(int *array, int arraylen)
{
	int i;
	for (i = 0; i < arraylen; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

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
	/* Move all of the elements to the new array. */
	for (i = 0; i < arraylen; i++)
	{
		ptr[i] = handle[i];
	}
	/* Put the value provided as the last element. */
	ptr[arraylen] = val;
	dynamic_array[0].arraylen = arraylen+1;
	dynamic_array[0].array = ptr;
	free(handle);
}

void extend(dynamicArray *dynamic_array_host, dynamicArray *dynamic_array_guest)
{
	int arraylen1 = dynamic_array_host[0].arraylen, arraylen2 = dynamic_array_guest[0].arraylen, i, *handle = dynamic_array_host[0].array, *ptr = malloc((arraylen1 + arraylen2) * sizeof(int));
	/* Move the first array */
	for (i = 0; i < arraylen1; i++)
	{
		ptr[i] = dynamic_array_host[0].array[i];
	}
	/* Move the second array */
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
	int arraylen = dynamic_array[0].arraylen, i, *handle = dynamic_array[0].array, j, *ptr = malloc((arraylen-1) * sizeof(int)), c = 0;
	/* Find the index of the element to be removed */
	for (i = 0; i < arraylen; i++)
	{
		if (dynamic_array[0].array[i] == remove_val)
			break;
	}
	/* Exit the function if the value to remove does not exist in the array */
	if (i == arraylen)
		return;
	/* Move all of the elements except the value to be removed to the new array */
	for (j = 0; j < arraylen; j++)
	{
		if (j != i)
		{
			ptr[c++] = handle[j];
		}
	}
	dynamic_array[0].array = ptr;
	dynamic_array[0].arraylen--;
	free(handle);
}

void insert(dynamicArray* dynamic_array, int index, int val)
{
	int i, arraylen = dynamic_array[0].arraylen, *ptr = malloc((arraylen+1)*sizeof(int)), *handle = dynamic_array[0].array, j;
	/* Check if the insert index is bigger than the array length, if that is the case, simply perform an append operation as done in Python. */
	if (index >= arraylen)
	{
		append(dynamic_array, val);
		return;
	}
	/* Move all of the elements to the new array. However, if we encounter the index to insert, we put the value provided. Then we move on. */
	for (i = 0, j = 0; i <= arraylen; i++)
	{
		if (i != index)
		{
			ptr[i] = handle[j++];
		}
		else
		{
			ptr[i] = val;
		}
	}
	dynamic_array[0].array = ptr;
	dynamic_array[0].arraylen++;
	free(handle);
}

int pop(dynamicArray* dynamic_array)
{
	int i, arraylen = dynamic_array[0].arraylen, *handle = dynamic_array[0].array, *ptr = malloc((arraylen-1)*sizeof(int)), val_to_return = dynamic_array[0].array[arraylen-1];
	/* Move all of the elements to the new array except the last one. */
	for (i = 0; i < arraylen-1; i++)
	{
		ptr[i] = handle[i];
	}
	dynamic_array[0].array = ptr;
	dynamic_array[0].arraylen--;
	free(handle);
	return val_to_return;
}

void clear(dynamicArray* dynamic_array)
{
	/* Sets all of the values of the array to the value defined as CLEARKEY at the top. */
	int i, arraylen = dynamic_array[0].arraylen;
	for (i = 0; i < arraylen; i++)
	{
		dynamic_array[0].array[i] = CLEARKEY;
	}
}

dynamicArray *copy(dynamicArray* dynamic_array)
{
	/* Don't forget to free both the array and the dynamicArray structure after using this. 
	 * We could just return the dynamicArray structure, but it would consume more resources. So we return the pointer to it. */
	
	dynamicArray *array_to_return = malloc(sizeof(dynamicArray));
	int i, arraylen = dynamic_array[0].arraylen, *ptr = malloc(arraylen*sizeof(int));
	array_to_return[0].arraylen = arraylen;
	for (i = 0; i < arraylen; i++)
	{
		ptr[i] = dynamic_array[0].array[i];
	}
	array_to_return[0].array = ptr;
	return array_to_return;

}

int count(dynamicArray* dynamic_array, int val)
{
	int i, arraylen = dynamic_array[0].arraylen, counter;
	for (i = 0, counter = 0; i < arraylen; i++)
	{
		if (dynamic_array[0].array[i] == val)
			counter++;
	}
	return counter;
}

int index(dynamicArray* dynamic_array, int val)
{
	int i, arraylen = dynamic_array[0].arraylen;
	for (i = 0; i < arraylen; i++)
	{
		if (dynamic_array[0].array[i] == val)
			return i;
	}
	return -1;
}

void reverse(dynamicArray* dynamic_array)
{
	int i, arraylen = dynamic_array[0].arraylen, temp;
	for (i = 0; i < arraylen/2; i++)
	{
		temp = dynamic_array[0].array[i];
		dynamic_array[0].array[i] = dynamic_array[0].array[arraylen-1-i];
		dynamic_array[0].array[arraylen-1-i] = temp;
	}
}

void sort(dynamicArray *dynamic_array)
{
	/* Using quicksort */
	quicksort(dynamic_array[0].array, 0, dynamic_array[0].arraylen-1);
}

void quicksort(int *array, int leftindex, int rightindex)
{
	int pivot = array[rightindex], i, right_swap_index = rightindex, temp, swap_count = 0, pivot_index;
	/* Checks if the string to work with is big enough */
	if (leftindex == rightindex)
	{
		return;
	}
	for (i = leftindex; i < right_swap_index; i++)
	{
		if (array[i] >= pivot && i != right_swap_index)
		{
			/* The loop below searches an index to swap the i'th element with */
			if (right_swap_index != rightindex)
			{
				while (array[right_swap_index] >= pivot && right_swap_index > leftindex)
				{
					right_swap_index--;
				}
				/* Checks if we have a bounded index to swap to. If it does not, exit the loop. */
				if (right_swap_index == leftindex)
					break;
			}
			/* Swap the values */
			temp = array[i];
			array[i] = array[right_swap_index];
			array[right_swap_index--] = temp;
			swap_count++;
			/* Remember the position of the pivot */
			if (swap_count == 1)
			{
				pivot_index = i;
			}
		}
	}
	/* If the pivot has been swapped before, swap it back to the middle point. We are checking whether it was swapped before because if it didn't, then we have no reason to put it back, it is already the biggest value and it is at the rightmost index. */
	if (swap_count > 0)
	{
		/* Find a middle index to swap */
		while (array[right_swap_index] > pivot && right_swap_index > leftindex)
		{
			right_swap_index--;
		}
		/* Check if we have a middle index in bounds to swap to */
		if (right_swap_index > leftindex)
		{
			temp = array[pivot_index];
			array[pivot_index] = array[right_swap_index];
			array[right_swap_index] = temp;
		}
	}
	/* Don't forget to check if the array is exceeded. Because at the beginning, we only check whether start index and stop index are the same. */
	if (right_swap_index != 0)
	quicksort(array, leftindex, right_swap_index-1);
	if (right_swap_index+1 <= rightindex)
	quicksort(array, right_swap_index+1, rightindex);
}

int main()
{
	int i;
	dynamicArray array = form_array(10);
	dynamicArray array2 = form_array(-10);
	dynamicArray *array3;
	for (i = 1; i <= 3; i++)
	{
		append(&array, i*10);
		append(&array2, (-10)*i);
	}
	extend(&array, &array2);
	array3 = copy(&array);
	array.array[2] = -100;
	print_dynamic_array(array);
	print_dynamic_array(array2);
	print_dynamic_array(*array3);
	reverse(&array);
	print_dynamic_array(array);
	sort(&array);
	print_dynamic_array(array);
	/* Don't  forget to free the dynamic arrays 
	 * Also, free both the array and the dynamicArray pointer if you have used copy function. */
	free(array.array);
	free(array2.array);
	free(array3[0].array);
	free(array3);
	return 0;
}
