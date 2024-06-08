#include<stdio.h>  
int main()    
{    
 int i,fact=1,number;    
 printf("Enter a number: ");    
  scanf("%d",&number);   
  if (number==0)
  {
    printf("Factorial of %d is: 1 ",number);
  } 
  else{
     for(i=1;i<=number;i++){    
      fact=fact*i;    
  }    
  printf("Factorial of %d is: %d ",number,fact); 

  }
      
return 0;  
}