#include <stdio.h>
#include <stdlib.h>

void MySort(int* arr) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 99; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
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
    MySort(arr);
    printf("After\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}