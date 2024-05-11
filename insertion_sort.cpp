#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10000];
    int n = sizeof(arr) / sizeof(arr[0]);

    // Generate a sorted list
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
        //cout<<arr[i]<<" ";
    }

    // Record start time
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    insertionSort(arr,n);
    // Record end time
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate the time taken in seconds
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Time necesar pentru a sorta prin insertie: %f seconds\n", time_taken);

    return 0;
}
