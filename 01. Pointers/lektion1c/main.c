#include <stdio.h>
#include "stdlib.h"

int main() {
    int n;

    printf("Input the number of elements to store in the array: \n");
    scanf("%d", &n);

    int arr[n];
    printf("Input %d number of elements in the array :\n", n);

    for (int i = 0; i <=n; i++) {
        printf("Type element %d: ", i);
        scanf("%d", arr+i);
    }

    for (int i = 0; i < n; ++i) {
        printf("element %d : %d\n", i, *arr+i);
    }


    return 0;
}
