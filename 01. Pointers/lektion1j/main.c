#include <stdio.h>
#include "stdlib.h"

/*
 * Write a program in C to compute the sum of all elements in an array using pointers
 */

int *sumArray(const int *array, int length, int i1) {
    int i;
    printf("The value of ptResult is: %i\n", i1);

    for(i = 0; i < length; i++){
        i1 += *(array + i);
    }
    return i1;
}

int main() {
    int i, n;
    int result = 0;
    int* ptResult = &result;
    printf("Type the number of elements to store in the array:\n");
    scanf("%i", &n);
    int *arr = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++){
        printf("Input %i element to store in the array", i + 1);
        scanf("%i", arr + i);
    }
    for (int j = 0; j < n; j++) {
        printf("Element %i in the array: %i\n", j + 1, *(arr + j));
    }

    sumArray(arr, n, *ptResult);
    result = *ptResult;
    printf("The sum of array is: %i", result);
    free(arr);

    return 0;
}
