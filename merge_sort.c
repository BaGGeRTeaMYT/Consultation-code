#include <stdio.h>
#include <stdlib.h>

void Merge(int *arr, int lhs1, int rhs1, int lhs2, int rhs2) {
    int i = lhs1;
    int j = lhs2;
    int t = 0;
    int *tmp_arr = malloc(sizeof(int)*(rhs2 - lhs1 + 1));
    while (i <= rhs1 && j <= rhs2) {
        if (arr[i] > arr[j]) {
            tmp_arr[t++] = arr[j++];
        }  else {
            tmp_arr[t++]  = arr[i++];
        }
    }
    while (i <= rhs1) {
        tmp_arr[t++] = arr[i++];
    }
    while (j <= rhs2) {
        tmp_arr[t++] = arr[j++];
    }
    for (i = 0; i < t; i++) {
        arr[lhs1 + i] = tmp_arr[i];
    }
    free(tmp_arr);
}

void MergeSort(int* arr, int lhs, int rhs) {
    if (rhs <= lhs) return;
    MergeSort(arr, lhs, (lhs + rhs)/2);
    MergeSort(arr, (lhs + rhs)/2 + 1, rhs);
    Merge(arr, lhs, (lhs + rhs)/2, (lhs + rhs)/2 + 1, rhs);
}

int PseudoRand(int i, int mod) {
    return 100 - i;
}

int main(void) {
    int* arr = malloc(100*sizeof(int));
    for (int i = 0; i < 100; i++) {
        arr[i] = PseudoRand(i, 100);
    }
    printf("Before\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", arr[i]);
    }
    MergeSort(arr, 0, 99);
    printf("\nAfter\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}