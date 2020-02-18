/*
CECS 424 Spring 2020 Project 1
Name: Randall Thornton
I.D. #016032222
Start Date: 1-21-2020
End Date: 2-11-2020
Description: This is a merge sort algorithm that 
sorts a given array by mkaing subarrays of single
vlaues, and then merging these subarrays comparatively.
*/

#include <stdio.h>
#include <stdlib.h>

// /* Prints array given passed in length argument */
// void print_array(int arr[], int n)
// {
//     n = 10;
//     for(int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n\n");    
// }

/* Take given bounds and merge the values contained
   within left and right subarrays in to allocated space.
   Then append all of the values back to the array in thier
   given spots.
*/
void merge(int arr[], int left, int middle, int right)
{
    int* merged_arr = (int*) malloc(sizeof(int) * (right - left + 1)); //Allocate space to store elements as they are ordered
    int position = 0; //Holds position in temp to place new element
    int left_pointer = left; //Points to the left most value of left subarray
    int right_pointer = middle + 1; //Points to left most value of right subarray

    //While the left pointer hasn't reached the end and
    // the right pointer hasn't reached the end, append 
    // the next lowest value to temp
    // printf("Left:%d  Middle:%d  Right:%d\n", left, middle, right);
    while(left_pointer <= middle && right_pointer <= right)
    {
        // printf("Left bound:%d Right bound:%d\n", middle, right);
        if(arr[left_pointer] < arr[right_pointer]) //If the left value of subarray is less than right value of subarray
        {
            // printf("left:%d  count:%d\n", arr[left_pointer], left_pointer);
            merged_arr[position++] = arr[left_pointer++]; //Append left value to temporary space
        }
        else
        {
            // printf("right:%d  count:%d\n", arr[right_pointer], right_pointer);
            merged_arr[position++] = arr[right_pointer++]; //Append right value to temporary space
        }
    }
    while(left_pointer <= middle) merged_arr[position++] = arr[left_pointer++]; //While there is still values from left subarray, append them
    while(right_pointer <= right) merged_arr[position++] = arr[right_pointer++]; //While there is still values from right subarray, append them
    for(int offset = 0; offset < position; offset++) //Transfer all of the temporary values in to their proper spots of array
    {
        arr[left+offset] = merged_arr[offset];
    }
    free(merged_arr); //Free up allocated space
    // print_array(arr, right);
}

/* Recursive structure to sort given array on 
    any length using lower and upper bound. */
void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        //Calls partition function, returns pivot index in array
        int middle = (left + right) / 2;
        
        // sort lower bound of pivot
        merge_sort(arr, left, middle);
        //Quick sort upper bound of pivot
        merge_sort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

// Call of array of length n to be sorted
void msort(int arr[], int n)
{
    merge_sort(arr, 0, n - 1);
}

// int main()
// {
//     int arr[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 3};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     print_array(arr, n);
//     msort(arr, n);
//     print_array(arr, n);
// }