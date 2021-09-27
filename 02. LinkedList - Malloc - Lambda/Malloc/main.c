#include <stdio.h>
#include "stdlib.h"

int main() {
    int n, i;
    char *mem;
    printf("How many bytes to allocate?\n");
    scanf("%d", &n);

    mem = (char*) malloc(n * sizeof(char));

    if (mem == NULL){
        printf("Out of memory\n");
        exit(-1);
    }

    for(i = 1; i <= n; i++){
        mem[i-1] = i;
    }

    for(i = 0; i < n; i++){
        printf("%d ", mem[i]);
    }

    free(mem);
    mem = NULL;

    return 0;
}
