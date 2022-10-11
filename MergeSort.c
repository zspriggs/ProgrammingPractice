#include <stdio.h>
#include <stdlib.h>

/* Note, code was written by zyshff for group assignment (implementation of MedianOfMedians algorithm). 
See repository Fall22-4050-HW2 for full assignment  */

/* Sorts an array using a recursive divide and conquer method. 

Input:  int * array, an array of integers to be sorted
        int l = the leftmost index of the array
        int r = the rightmost index of the array        */
void MergeSort(int * array, int l, int r) 
{
    if((r-l) >= 1)
    {
        int mid = (l+r)/2;

        MergeSort(array, l, mid);
        MergeSort(array, mid+1, r);
        

        Merge(&array, l, mid, r);
    }

}

/*  Merges two adjacent sections of an array in sorted order (helper method for MergeSort)
    Merge method takes the pointer to the array so that it can modify the array itself 
    Essentially sorts the array "in place"
    
Input = int ** arr, a pointed to an array that is to be sorted
        int l, the leftmost index of the array section that will be sorted
        int mid, the cutoff between the left and right sections of the array that will be merged together
        int r, the rightmost index of the array section that will be sorted
*/
void Merge(int ** arr, int l, int mid, int r) 
{
    //leftIndex and rightIndex keep track of the current indeces being merged
    int leftIndex = 0; 
    int rightIndex = 0;

    if(l == r)
    {
        return;
    }

    int * array  = *arr; 
    int l1 = (mid - l + 1) ;

    int l2 = r-mid;

    int * a1 = (int *)malloc(sizeof(int) * (l1));
    int * a2 = (int *)malloc(sizeof(int) * (l2));

    for(int i = 0; i < l1; i++)
    {
        a1[i] = array[l+i];
    }

    for(int i = 0; i < l2; i++)
    {
        a2[i] = array[mid+i+1];
    }

    leftIndex = 0;
    rightIndex = 0;

    for(int i = l; i <= r; i++)
    {
        if(leftIndex < l1 && rightIndex < l2)
        {
            if(a1[leftIndex] <= a2[rightIndex])
            {
                array[i] = a1[leftIndex];
                leftIndex++;
            }
            else if(a2[rightIndex] < a1[leftIndex])
            {
                array[i] = a2[rightIndex];
                rightIndex++;

            }
        }
        else if (leftIndex >= l1)
        {
            array[i] = a2[rightIndex];
            rightIndex++;
        }
        else if (rightIndex >= l2)
        {
            array[i] = a1[leftIndex];
            leftIndex++;
        }
    }
    free(a1);
    free(a2);

}
