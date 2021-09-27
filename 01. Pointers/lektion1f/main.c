#include <stdio.h>

void swapNumbers( int *x, int *y, int*z){
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void factorial(int x, int *f){
    *f = 1;
    for (int i = 1; i <= x; i++) {
        *f = *f*i;
    }

}

int main() {
    int e1, e2, e3, f, fact;
    printf("\n\n Pointer : Swap elements using call by reference :\n");
    printf("------------------------------------------------------\n");
    printf(" Input the value of 1st element : ");
    scanf("%d",&e1);
    printf(" Input the value of 2nd element : ");
    scanf("%d",&e2);
    printf(" Input the value of 3rd element : ");
    scanf("%d",&e3);

    printf("\n The value before swapping are :\n");
    printf(" element 1 = %d\n element 2 = %d\n element 3 = %d\n",e1,e2,e3);
    swapNumbers(&e1, &e2, &e3);
    printf("\n The value after swapping are :\n");
    printf(" element 1 = %d\n element 2 = %d\n element 3 = %d\n\n",e1,e2,e3);

    printf("Input a number to find the factorial of it: \n");
    scanf("%d", &f);
    factorial(f, &fact);
    printf(" The Factorial of %d is : %d \n\n",f,fact);

    return 0;
}
