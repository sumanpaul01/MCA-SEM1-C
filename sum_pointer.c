#include <stdio.h>

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int n = sizeof(array) / sizeof(array[0]);

    int *ptr = array; // Initialize a pointer to the start of the array
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += *ptr; // Add the value pointed to by ptr to the sum
        ptr++;       // Move the pointer to the next element
    }

    printf("Sum of array elements: %d\n", sum);

    return 0;
}
