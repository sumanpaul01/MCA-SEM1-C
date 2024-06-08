#include<stdio.h>
int main()
{
    int n,i,s,arr[50],f;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
    {
         scanf("%d",&arr[i]);
    }
    printf("Enter the element to search:");
    scanf("%d",&s);
    for(i=0;i<n;i++)
    {
        if(arr[i]==s)
        {
            f=1;
            break;
        }
    }
    if(f == 1)
    {
        printf("\n%d is found at position %d", s, i + 1);
    }
    else
    {
        printf("\n%d is not found in the array", s);
    }
    return 0;
}