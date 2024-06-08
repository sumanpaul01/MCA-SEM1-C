#include <stdio.h>

// Recursive function to calculate the sum of the first n natural numbers
int sumOfNaturalNumbers(int n) {
    if (n == 0) {
        return 0; // Base case: the sum of 0 natural numbers is 0.
    } else {
        return n + sumOfNaturalNumbers(n - 1); // Recursive case: sum n and the sum of the first (n-1) natural numbers.
    }
}

int main() {
    int n = 20;
    int result = sumOfNaturalNumbers(n);

    printf("The sum of the first %d natural numbers is %d\n", n, result);

    return 0;
}
