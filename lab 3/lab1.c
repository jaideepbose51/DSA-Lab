// WAP to store the data of a sparse matrix in three tuple format


#include <stdio.h>
#include <stdlib.h>

void assign(int);
void store(int, int, int[][*]);

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    assign(n);
}

void assign(int n)
{
    int nonZero = 0;
    int arr[n][n], i, j;
    printf("Enter values:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] != 0)
                nonZero++;
        }
    }
    store(n, nonZero, arr);
}

void store(int n, int nonZero, int arr[][n])
{
    int i, j, k = 0;
    int newArr[3][nonZero];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                newArr[0][k] = i;
                newArr[1][k] = j;
                newArr[2][k] = arr[i][j];
                k++;
            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < nonZero; j++)
        {
            printf("%d ", newArr[i][j]);
        }
        printf("\n");
    }
}
