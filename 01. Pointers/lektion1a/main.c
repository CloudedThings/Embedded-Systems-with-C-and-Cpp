#include <stdio.h>

int main() {
    int m = 300;
    float fx = 300.600006;
    char cht = 'z';

    int *pt1 = &m;
    float *pt2 = &fx;
    char *pt3 = &cht;

    printf("address of m = %p\n", &m);
    printf("address of fx = %p\n", &fx);
    printf("address of cht = %p\n", &cht);

    printf("value at address of m = %d\n", *(&m));
    printf("value at address of fx = %f\n", *(&fx));
    printf("value at address of cht = %c\n", *(&cht));

    printf("address of m = %p\n", pt1);
    printf("address of fx = %p\n", pt2);
    printf("address of cht = %p\n", pt3);

    printf("value at address of m = %d\n", *(pt1));
    printf("value at address of fx = %f\n", *(pt2));
    printf("value at address of cht = %c\n", *(pt3));

    return 0;
}
