/*
CECS 424 Spring 2020 Project 1
Name: Randall Thornton
I.D. #016032222
Start Date: 1-21-2020
End Date: 2-11-2020
Description: This is a quick sort algorithm that
sorts the given array using a median pivot value
and partitioning elements comparatively.
*/

#include <stdio.h>

//Swaps elements in array
void swap(int* element, int* swap)
{
    int val = *element;
    *element = *swap;
    *swap = val;
}

// /* Prints array given passed in length argument */
// void print_array(int arr[], int n)
// {
//     n = 10;
//     for(int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");    
// }

/* Selects the best pivot option between the
    front, middle, and end values, then returns it */
void position_pivot(int arr[], int low, int high)
{
    int middle = (low + high) / 2; //Select index of middle value as pivot option
    if(arr[low] > arr[middle]) //Check if middle value is less than front pivot
    {
        if(arr[middle] > arr[high]) //Given middle pivot is less than front, check if middle is greater than end
        {
            swap(&arr[middle], &arr[high]); //Swap middle to pivot position
        }
        else if(arr[high] > arr[low]) //Given middle pivot is less than front, middle is less than end, check if end is greater than front
        {
            swap(&arr[low], &arr[high]); //Swap front to pivot position
        }
    } else {
        if (arr[low] > arr[high]) //Given middle is greater than front, check front is greater than end
        {
            swap(&arr[low], &arr[high]); //Swap front to pivot position
        }
        else if (arr[high] > arr[middle]) //Given middle is greater than front, front less than end, check if end is greater than middle
        {
            swap(&arr[middle], &arr[high]); //Swap middle to pivot position
        }
    }
}

/*  Partition the rest of the values 
    to the left and the right of the pivot.
    Then swap pivot in to middle of partitions
*/

int partition(int arr[], int low, int high)
{
    position_pivot(arr, low, high - 1); //Select pivot option
    int pivot = arr[high - 1];

    int left_pointer = low; //Select left most index
    int right_pointer = high - 2; //Select right most index

    // While left pointer does not cross with right pointer
    while (left_pointer < right_pointer) {
        if (arr[left_pointer] < pivot) { //If the value is less than pivot, move right in array
            left_pointer++;
        }
        else if (arr[right_pointer] >= pivot) { //If the value is greater than pivot, move left in array
            right_pointer--;
        }
        else
        {
            swap(&arr[left_pointer], &arr[right_pointer]); //If the left value is greater than pivot, and right value less than pivot, swap elements
        }
    }
    if(high - low > 2) swap(&arr[left_pointer], &arr[high - 1]); //Swap pivot in to middle of partitions
    return left_pointer; //Return index of pivot in proper location
}

/* Recursive structure to sort given array on 
    any length using lower and upper bound. */
void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        //Calls partition function, returns pivot index in array
        int pivot_index = partition(arr, low, high);
        
        //Quick sort lower bound of pivot
        quick_sort(arr, low, pivot_index);
        //Quick sort upper bound of pivot
        quick_sort(arr, pivot_index + 1, high);
    }
}

// Call of array of length n to be sorted
void qsort2(int arr[], int n)
{
    quick_sort(arr, 0, n);
}