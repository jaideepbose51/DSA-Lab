// Function to add two polynomials
#include <stdio.h>

int main()
{
    int a[10], b[10], sum[10];
    int i, j, k, m, n;

    printf("Enter the highest degree of the first polynomial: ");
    scanf("%d", &m);

    printf("Enter the coefficients of the first polynomial: ");
    for (i = 0; i <= m; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the highest degree of the second polynomial: ");
    scanf("%d", &n);

    printf("Enter the coefficients of the second polynomial: ");
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }

    k = (n > m) ? n : m;

    for (i = 0; i <= k; i++)
    {
        sum[i] = a[i] + b[i];
    }

    printf("The sum of the two polynomials is: ");
    for (i = k; i >= 0; i--)
    {
        if (i == 0)
        {
            printf("%d", sum[i]);
        }
        else if (i == 1)
        {
            printf("%dx + ", sum[i]);
        }
        else
        {
            printf("%dx^%d + ", sum[i], i);
        }
    }
    return 0;
}