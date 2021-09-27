#include <stdio.h>
#include "stdlib.h"

/*
 * Write a program in C to sort an array using Pointer.
 */

void sortArray(int *a, int n) {
    int tmp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if( *(a+i) > *(a+j))
            {
                tmp = *(a+i);
                *(a+i) = *(a+j);
                *(a+j) = tmp;
            }
        }
    }
}

int main() {
    int i, n, n1;

    printf("Input the number of elements to store in the array: \n");
    scanf("%d", &n);
    int *a = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        printf("Input %d element in the array: ", i + 1);
        scanf("%i", a + i);
    }
    for (i = 0; i < n; i++) {
        printf("Element %d of array is: %i\n", i, *(a + i));
    }
    sortArray(a, n);
    for (i = 0; i < n; i++) {
        printf("Sorted element %d of array is: %i\n", i, *(a + i));
    }
    printf("Input the number of elements to store in the new array: \n");
    scanf("%d", &n1);
    a = realloc(a, sizeof(int) * n1);
    sortArray(a, n1);
    for (i = 0; i < n1; i++) {
        printf("Sorted element %d of array is: %i\n", i, *(a + i));
    }

    free(a);

    return 0;
}
