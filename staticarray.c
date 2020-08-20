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
void quicksort(int *, int, int, int);


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
	quicksort(array, 0, arraylen-1, 0);
}

void quicksort(int *array, int leftindex, int rightindex, int counter)
{
	int pivot = array[rightindex], i, right_swap_index = rightindex, temp, swap_count = 0, pivot_index;
	if (counter < 5)
		printf("Entered the function for %d and %d\n", leftindex, rightindex);
	if (leftindex == rightindex)
	{
		return;
	}
	for (i = leftindex; i < right_swap_index; i++)
	{
		if (array[i] >= pivot)
		{
			temp = array[i];
			array[i] = array[right_swap_index];
			array[right_swap_index--] = temp;
			swap_count++;
			if (swap_count == 1)
			{
				pivot_index = i;
			}
		}
	}
	while (pivot <= array[right_swap_index])
	{
		right_swap_index--;
	}
	temp = array[pivot_index];
	array[pivot_index] = array[right_swap_index];
	array[right_swap_index] = temp;
	if (counter < 5)
	{
		printf("Array is now:");
		print_array(array, 4);
	}
	quicksort(array, leftindex, right_swap_index-1, counter+1);
	quicksort(array, right_swap_index+1, rightindex, counter+1);
}

int main()
{
	int array[4] = {1,1,3,4};
	int array3[4] = {4,3,2,1};
	int array2[5] = {1,2,3,4,5};
	print_array(array3, 4);
	sort(array3, 4);
	print_array(array3, 4);
	return 0;
}
