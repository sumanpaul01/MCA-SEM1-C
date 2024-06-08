

#include <stdio.h>

int main() {
  int n;
  printf("Enter array Size: ");
  scanf("%d",&n);

  int values[n];

  printf("Enter  Array Elements: ");
  for(int i = 0; i < n; ++i) {
     scanf("%d", &values[i]);
  }

  printf("Displaying Array Elements : ");
  for(int i = 0; i < n; ++i) {
     printf("%d\n", values[i]);
  }
  return 0;
}
