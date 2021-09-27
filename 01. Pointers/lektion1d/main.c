#include <stdio.h>
#include "stdlib.h"

int main() {
    int n;
    float *element;
    printf("Input total number of elements (1 to 100):\n");
    scanf("%d", &n);
    element = (float*) calloc(n, sizeof(float));
    if(element==NULL){
        printf("No memory is allocated.");
        exit(0);
    }


    for (int i = 0; i <n; ++i) {
        printf("Type element %d: ", i+1);
        scanf("%f", element+i);
    }
    for (int i = 0; i < n; i++) {
        printf("element %d : %f\n", i, *(element+i));
    }
    for(int i = 1; i <n; ++i){
        if(*element < *(element+i))
            *element = *(element+i);
    }
    printf("The largest element is: %.2f \n", *element);

    return 0;
}
