/*
wap to print both the main diagonal of a 2d matrix
*/

#include <stdio.h>
void insert(int);

int main()
{
    int n;
    printf("Enter size of matrix you want to enter \n");
    scanf("%d", &n);
    insert(n);
    return 0;
}

void insert(int n)
{
    int arr[n][n], i, j;
    printf("Enter value in the matrix : \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Main diagonal :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i][i]);
    }
    printf("\nSecond diagonal :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i + j == (n - 1))
                printf("%d  ", arr[i][j]);
        }
    }
}
