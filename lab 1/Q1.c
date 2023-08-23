/*
Write a menu driven program to create a structure to represent complex number and perform the following operation using function :

1. addition of two complex number  (call by value)


Sample Input/Output:

Enter complex number 1: 3  4
Enter complex number 2: 4  5

MENU
1. addition
2. exit
Enter your choice: 1

Sum=7+9i
Enter your choice: 2

*/

#include <stdio.h>
#include <stdlib.h>

struct complex
{
    double real;
    double img;
};

double add(double, double);

int main()
{
    double real, img; // Use double instead of int for real and img
    int ch;
    struct complex obj1;
    struct complex obj2;
    while (1)
    {
        printf("Enter real and imaginary part of no 1\n");
        scanf("%lf%lf", &obj1.real, &obj1.img);
        printf("Enter real and imaginary part of no 2\n");
        scanf("%lf%lf", &obj2.real, &obj2.img);
        printf("Enter 1 to add\n");
        printf("Enter 2 to exit\n");
        printf("ENTER YOUR CHOICE :");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            real = add(obj1.real, obj2.real);
            img = add(obj1.img, obj2.img);
            printf("Result is : %.1lf + %.1lfi\n", real, img);
            break;
        case 2:
            exit(0);
        default:
            printf("Wrong choice \n");
            break;
        }
    }

    return 0;
}

double add(double n1, double n2)
{
    return (n1 + n2);
}
