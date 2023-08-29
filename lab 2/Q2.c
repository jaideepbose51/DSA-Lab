/*
Write a program to create a structure to store the information of n number of Employees. Employee’s information includes data members: Emp-id, Name, Designation, basic_salary. Use array of structure.
*/

#include <stdio.h>
#include <string.h>

struct employee
{
    char nm[20];
    int empid;
    char des[50];
    int sal;
};

int main()
{
    int n, i;
    printf("Enter no of entries you want to make: ");
    scanf("%d", &n);
    struct employee arr[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter Employee details:\n");
        printf("Enter Employee name: ");
        getchar();
        fgets(arr[i].nm, sizeof(arr[i].nm), stdin);
        printf("Enter Employee ID: ");
        scanf("%d", &arr[i].empid);
        printf("Enter Employee Designation: ");
        getchar();
        fgets(arr[i].des, sizeof(arr[i].des), stdin);
        printf("Enter Employee salary: ");
        scanf("%d", &arr[i].sal);
    }
    for (i = 0; i < n; i++)
    {
        printf("Employee name: ");
        printf("%s", arr[i].nm);
        printf("Employee ID: %d\n", arr[i].empid);
        printf("Employee Designation: %s", arr[i].des);
        printf("Employee salary: %d\n", arr[i].sal);
    }
    return 0;
}
