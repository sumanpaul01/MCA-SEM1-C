
#include <stdio.h>

int main() {
    float a;
    printf("Enter Distance in kilometre: ");
    scanf("%f",&a);
    printf("Distance in Meter :%f \n",a*1000);
    printf("Distance in Feet :%f \n",a*3280.84);
    printf("Distance in Inches :%f ",a*39370.07874);
    

    return 0;
}