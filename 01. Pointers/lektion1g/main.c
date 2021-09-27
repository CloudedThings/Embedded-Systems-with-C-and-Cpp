#include <stdio.h>

int main() {
    char str[20], *p;
    int i, vowels = 0, consonants = 0;
    printf("Input a string: \n");
    gets(str);

    for (i = 0; i < str[i]; ++i) {
        if((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) {
            if(str[i]=='a'|| str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u' || str[i] == 'y' || str[i] == 'Y'
                ||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O' ||str[i]=='U') {
                vowels++;
            }
            else
                consonants++;
        }
    }
    printf("Vowels: %d\nConsonants: %d\n", vowels, consonants);
    vowels = 0, consonants = 0;

    p = str;

    while (*p) {
        if ((*p >= 65 && *p <=90) || (*p >= 97 && *p <= 122)) {
            if(*p=='a'|| *p=='e'||*p=='i'||*p=='o'||*p=='u' || *p == 'y' || *p == 'Y'
                ||*p=='A'||*p=='E'||*p=='I'||*p=='O' ||*p=='U')
                vowels++;
            else
                consonants++;
        }
        p++;
    }


    printf("Vowels: %d\nConsonants: %d\n", vowels, consonants);

    return 0;
}
