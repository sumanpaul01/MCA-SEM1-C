#include <stdio.h>

int main() {
    int arr[20],n,i;
    printf("Enter the size of N \n");
    scanf("%d", &n);
    printf("Enter the numbers \n");
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    if (n < 2) {
        printf("Array should have at least two elements to find the second highest number.\n");
        return 1;
    }

    int first_max = arr[0];
    int second_max = arr[1];

    if (second_max > first_max) {
        int temp = first_max;
        first_max = second_max;
        second_max = temp;
    }

    for (int i = 2; i < n; i++) {
        if (arr[i] > first_max) {
            second_max = first_max;
            first_max = arr[i];
        } else if (arr[i] > second_max && arr[i] != first_max) {
            second_max = arr[i];
        }
    }

    printf("The second highest number in the array is: %d\n", second_max);

    return 0;
}
