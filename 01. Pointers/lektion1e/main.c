#include <stdio.h>
#include "stdlib.h"
#include "string.h"

int calculateLength(char* str) {
    int count = 0;
    while (*str != '\0'){
        count++;
        str++;
    }
    return count-1;
}


int main() {
    char str[25];
    printf("Input a string: \n");
    fgets(str, sizeof str, stdin);
    printf("The length of given string: %s\nis : %lu\n", str, strlen(str)-1);

    printf("The length of given string %s\nis : %d", str, calculateLength(str));

    return 0;
}
