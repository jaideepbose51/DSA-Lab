/*
Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of all the prime elements of the array using function and de-allocate the memory of the array after its use.
Sample Input:
Enter size of the array: 5
Enter array elements: 3  9  7  4  8
Sample Output:
Sum =10
*/

#include <stdio.h>
#include <stdlib.h>

int prime(int *);

int main()
{
    int n, *p, i = 0, sum = 0;
    printf("Enter size of array :");
    scanf("%d", &n);
    p = (int *)malloc(sizeof(int) * n);
    printf("Enter value to be entered in array \n");
    for (; i < n; i++)
    {
        printf("Enter value :");
        scanf("%d", (p + i));
    }
    for (i = 0; i < n; i++)
    {
        if (prime(p + i) == 1)
            sum += *(p + i);
    }
    printf("Sum of prime element is :%d", sum);
    free(p);
    return 0;
}

int prime(int *p)
{
    int i = 2;
    if (*p == 1 || *p == 0)
    {
        return 0;
    }
    else
    {
        for (; i < *p; i++)
        {
            if (*p % i == 0)
                return 0;
        }
        return 1;
    }
}