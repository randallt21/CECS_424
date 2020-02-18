/*
CECS 424 Spring 2020 Project 1
Name: Randall Thornton
I.D. #016032222
Start Date: 1-21-2020
End Date: 2-11-2020
Description: This program uses a merge sort algorithm 
and a quick sort algorithm to sort any given array of 
size n. Merge sorts a given array by making subarrays of single
vlaues, and then merging these subarrays comparatively.
Quick sorts the given array using a median pivot value
and partitioning elements comparatively.
*/

#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"
#include "quick_sort.h"

/* Prints array given passed in length argument */
void print_array(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");    
}
/* Main function establishes requested array from
    assignment and then calls both sorting functions.
    */
int main()
{
    int arr[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int n = 10;
    // int n = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, n);    //Print original array
    qsort2(arr, n);         //Quick sort array
    print_array(arr, n);    //Print sorted array

    printf("\n");

    int arrB[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int nB = 10;
    // int nB = sizeof(arrB) / sizeof(arrB[0]);
    print_array(arrB, nB);  //Print original array
    msort(arrB, nB);        //Quick sort array
    print_array(arrB, nB);  //Print sorted array
}