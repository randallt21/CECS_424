#ifndef QUICK_SORT_H_

#define QUICK_SORT_H_

void swap(int* element, int* swap);

void position_pivot(int arr[], int low, int high);

int partition(int arr[], int low, int high);

void quick_sort(int arr[], int low, int high);

void qsort2(int arr[], int n);

#endif //QUICK_SORT_H_