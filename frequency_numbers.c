#include <stdio.h>

int main() {
    int number, digit, frequency[10] = {0}; // Initialize frequency array with zeros

    // Input the number
    printf("Enter an integer: ");
    scanf("%d", &number);

    // Calculate the frequency of each digit
    while (number != 0) {
        digit = number % 10;
        frequency[digit]++;
        number /= 10;
    }

    // Display the frequency of each digit
    printf("Frequency of each digit:\n");
    for (int i = 0; i < 10; i++) {
        if (frequency[i] > 0) {
            printf("Digit %d: %d times\n", i, frequency[i]);
        }
    }

    return 0;
}
