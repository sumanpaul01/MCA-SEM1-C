#include <stdio.h>

// Define the structure "company"
struct company {
    char name[50];
    char address[100];
    char phone[15];
    int noOfEmployee;
};

int main() {
    // Declare a structure variable of type "company"
    struct company myCompany;

    // Read input from the user
    printf("Enter company name: ");
    fgets(myCompany.name, sizeof(myCompany.name), stdin);

    printf("Enter company address: ");
    fgets(myCompany.address, sizeof(myCompany.address), stdin);

    printf("Enter company phone: ");
    fgets(myCompany.phone, sizeof(myCompany.phone), stdin);

    printf("Enter the number of employees: ");
    scanf("%d", &myCompany.noOfEmployee);

    // Display the company information
    printf("\nCompany Information:\n");
    printf("Name: %s", myCompany.name);
    printf("Address: %s", myCompany.address);
    printf("Phone: %s", myCompany.phone);
    printf("Number of Employees: %d\n", myCompany.noOfEmployee);

    return 0;
}
