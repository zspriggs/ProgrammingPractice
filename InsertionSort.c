#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int length);
void printArray(int *arr, int length);

int main(void)
{
    int arr[] = {1, 7, 5, 6, 9, 8, 2, 4, 3, 0};
    printf("Unsorted array: ");
    printArray(arr, 10);
    sort(arr, 10);
    printf("\nSorted array: ");
    printArray(arr, 10);
}

/* Helper method, prints an array of integers

Input = int * arr, the array to be printed
        int length, the length of arr       */
void printArray(int *arr, int length)
{
    int *end = arr + length;
    for(; arr < end; arr++)
    {
        printf("%d ", *arr);
    }
}


/* Insertion sort method. Sorts an array of integers

Input = int * arr, the array that is to be sorted
        int length, the length of arr           */
void sort(int *arr, int length)
{
	int key, j;

    for(int i = 1; i < length; i++)
    {
    	key = arr[i];
    	j = i-1;
    	while(j >= 0 && arr[j] > key)
    	{
    		arr[j+1] = arr[j];
    		j--;
    	}
    	arr[j+1] = key;
    }

}