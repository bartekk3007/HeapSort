#include <stdio.h>
#include <stdlib.h>

void printArray(int* tab, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", tab[i]);
	}
	printf("\n");
}

void swap(int* arr, int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void heapifyRecursively(int* arr, int i, int size)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	int largest = i;

	if (l < size && arr[l] > arr[largest])
	{
		largest = l;
	}
	if (r < size && arr[r] > arr[largest])
	{
		largest = r;
	}

	if (largest != i)
	{
		swap(arr, i, largest);
		heapifyRecursively(arr, largest, size);
	}
}

void heapSortRecursively(int* arr, int size)
{
	int nonLeaf = size / 2 - 1;
	for (int i = nonLeaf; i >= 0; i--)
	{
		heapifyRecursively(arr, i, size);
	}
	int i;
	for (i = size - 1; i >= 0; i--)
	{
		swap(arr, 0, i);
		heapifyRecursively(arr, 0, i);
	}
}

void buildMaxHeap(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        // if child is bigger than parent
        if (arr[i] > arr[(i - 1) / 2])
        {
            int j = i;
            // swap child and parent until parent is smaller
            while (arr[j] > arr[(j - 1) / 2])
            {
				swap(arr, j, (j - 1) / 2);
                j = (j - 1) / 2;
            }
        }
    }
}

void heapSortIteratively(int *arr, int size)
{
    buildMaxHeap(arr, size);
    for (int i = size - 1; i > 0; i--)
    {
        // swap value of first indexed with last indexed
		swap(arr, 0, i);
        // maintaining heap property after each swapping
		int j = 0;
		int index;
        do
        {
            index = (2 * j + 1);
            // if left child is smaller than right child point index variable to right child
            if (index < (i - 1) &&arr[index] < arr[index + 1] )
            {
                index++;
            }
            // if parent is smaller than child then swapping parent with child having higher value
            if (index < i && arr[j] < arr[index])
            {
				swap(arr, j, index);
            }
            j = index;

        } while (index < i);
    }
}

int main(void)
{
	int arr[] = { 55, 13, 34, 21, 89, 5, 8, 144 };
	int size = sizeof(arr) / sizeof(*arr);

	printArray(arr, size);

	//heapSortRecursively(arr, size);

    heapSortIteratively(arr, size);

	printArray(arr, size);

	return 0;
}