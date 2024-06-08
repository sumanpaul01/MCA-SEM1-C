#include <stdio.h>
int main()
{
    int i, small, large,arr[50],n;
    printf("Enter the array size: ");
    scanf("%d",&n);
    printf("Enter the array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    

    small = arr[0];
    large = arr[0];
    
    for (i = 0; i < n; i++)
    {
        if (arr[i] < small)
        {
            small = arr[i];
        }
        if (arr[i] > large)
        {
            large = arr[i];
        }
    }
    printf("Largest element is : %d\n", large);
    printf("Smallest element is : %d\n", small);
    return 0;
}