#include <stdio.h>
#include <stdlib.h>
#define CLEARKEY 0
/* These are the methods of lists from Python 
 * Note that all of these functions work aswell for char arrays*/
void clear(int *, int);
int *copy(int *, int);
int count(int *, int, int);
int index(int *, int, int);
void reverse(int *, int);
void sort(int *, int);
void print_array(int *, int);
void quicksort(int *, int, int);


void reverse(int *array, int arraylen)
{
	int i, temp;
	for (i = 0; i < arraylen/2; i++)
	{
		temp = array[i];
		array[i] = array[arraylen-1-i];
		array[arraylen-1-i] = temp;
	}
}

int index(int *array, int arraylen, int elem_searched)
{
	int i;
	for (i = 0; i < arraylen; i++)
	{
		if (array[i] == elem_searched)
		{
			return i;
		}
	}
	return -1;
}

int count(int *array, int arraylen, int elem_searched)
{
	int i, counter = 0;
	for (i = 0; i < arraylen; i++)
	{
		if (array[i] == elem_searched)
		{
			counter++;
		}
	}
	return counter;
}

void print_array(int *array, int arraylen)
{
	int i;
	for (i = 0; i < arraylen; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void clear(int *array, int arraylen)
{
	int i;
	for (i = 0; i < arraylen; i++)
	{
		array[i] = CLEARKEY;
	}
}

int *copy(int *array, int arraylen)
{
	/* Don't forget to free the returned array */
	int *new_array = malloc(arraylen * sizeof(int));
	int i;
	for (i = 0; i < arraylen; i++)
	{
		new_array[i] = array[i];
	}
	return new_array;
}

void sort(int *array, int arraylen)
{
	/* Using quicksort */
	quicksort(array, 0, arraylen-1);
}

void quicksort(int *array, int leftindex, int rightindex)
{
	int pivot = array[rightindex], i, right_swap_index = rightindex, temp, swap_count = 0, pivot_index, previous_swap_index;
	/* Checks if the string to work with is big enough */
	if (leftindex == rightindex)
	{
		return;
	}
	for (i = leftindex; i < right_swap_index; i++)
	{
		if (array[i] >= pivot && i != right_swap_index)
		{
			previous_swap_index = right_swap_index;
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
		previous_swap_index = right_swap_index;
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
	int array[4] = {1,1,3,4};
	int array3[4] = {4,3,1,2};
	int array4[5] = {10, 1, 20, 30, 15};
	int array5[5] = {10, -1, 20, 30, -10};
	int array6[5] = {1, 9, 5, 7, 3};
	int array2[5] = {1,2,3,4,5};
	int array7[10] = {10, 9, 7, -1, 5, 3, 2, 1, 5, -10};
	int array8[10] = {10, 9, 7, -1, -5, 3, 2, 1, 5, -10};
	int array9[8] = {5, 2, -1, 5, 3, 7, 10, 9};
	int array10[8] = {5, 2, -1, 3, 3, 7, 10, 9};
	int array11[5] = {10, 3, 2, 1, 9};
	print_array(array11, 5);
	sort(array11, 5);
	print_array(array11, 5);
	return 0;
}
