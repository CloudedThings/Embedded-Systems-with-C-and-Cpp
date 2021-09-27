#include <stdio.h>
#include "stdlib.h"

/*
 * Write a program in C to compute the sum of all elements in an array using pointers
 * PASS BY REFERENCE    
 */

void sumArray(const int *array, int length, int * const result){
    int i;
    for(i = 0; i < length; i++){
        *result += *(array + i);
    }
}

int main() {
    int i, n;
    int result = 0;
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
    sumArray(arr, n, &result);

    printf("The sum of array is: %i", result);
    free(arr);

    return 0;
}
