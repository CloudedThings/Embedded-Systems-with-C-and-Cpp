#include <stdio.h>

int sumNumbers(int *x, int *y) {
    return *x + *y;
}

int maxOfTwo(int *pt1, int *pt2) {
    if (*pt1 > *pt2) {
        return pt1;
    }
    else if (*pt2 > *pt1) {
        return *pt2;
    }
    else {
        printf("Numbers are equal");
    }
}

int main() {
    int x, y;
    int *pt1 = &x;
    int *pt2 = &y;

    printf("Type the first number: \n");
    scanf("%d", pt1);
    printf("Type the second number: \n");
    scanf("%d", pt2);

    int result = *pt1 + *pt2;
    printf("The sum of the entered numbers is: %d\n", sumNumbers(pt1, pt2));

    printf("%d is the maximum number of those two provided", maxOfTwo(pt1, pt2));

    return 0;
}
