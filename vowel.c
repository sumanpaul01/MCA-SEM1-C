#include <stdio.h>
int main() {
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);
    int lower= (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

    int upper= (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    if ((lower || upper))
         printf("%c is a vowel.", c);
    else
        printf("%c is a consonant.", c);

    return 0;
}