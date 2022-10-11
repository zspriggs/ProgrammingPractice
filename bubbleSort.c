#include <stdio.h>

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
    printf("A = {");
    for(; arr < end; arr++)
    {
        printf("%d ", *arr);
    }
    printf("}\t");
}

/* Bubble sort method. Sorts an array of integers

Input = int * arr, the array that is to be sorted
        int length, the length of arr           */
void sort(int *arr, int length)
{
    int hold;

    for(int i = 0; i < length; i++)
    {
        for(int y = 0; y < length-1; y++)
        {
            if(arr[y] > arr[y + 1])
            { 
                hold = arr[y]; 
                arr[y] = arr[y+1];
                arr[y +1] = hold;

                printArray(arr, length);
                printf("i = %d, j = %d\n", i, y);
            }

        }


    }

}
