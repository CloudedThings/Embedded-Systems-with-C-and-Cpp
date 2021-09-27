#include <stdio.h>

/*
 * Write a program in C to show how a function returns a pointer
 */

int* maxNumber(int *x, int *y){
    int *even;
    if (*x > *y)
        return x;
    else if (*y > *x)
        return y;
    else
        return even = 0;
}

int main() {
    int n, m;
    int *max;
    printf("input the first number: \n");
    scanf("%i", &n);
    printf("input the second number: \n");
    scanf("%i", &m);

    max = (maxNumber(&n, &m));ÖÖ

    if (max == 0)
        printf("Both numbers are equal");
    else
        printf("The highest number is: %d", *max);

    return 0;
}
