//
// Created by harri on 11/7/2018.
//

#include "methods.h"

#ifndef PROJECT_SORTING_H
#define PROJECT_SORTING_H


void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - 1) / 2;

        merge_sort(arr, 1, m);
        merge_sort(arr, m + 1, r);

        merge(arr, 1, m, r);
    }
}

static void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; i < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    return;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int partition_index = partition(arr, low, high);

        quick_sort(arr, low, partition_index - 1);
        quick_sort(arr, partition_index + 1, high);
    }
}

#endif //PROJECT_SORTING_H
