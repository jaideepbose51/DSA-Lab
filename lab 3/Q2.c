#include <stdio.h>

struct SparseMatrixEntry
{
    int row, col, value;
};

void transposeSparseMatrix(struct SparseMatrixEntry matrix[], int numEntries)
{
    struct SparseMatrixEntry transposedMatrix[numEntries];

    for (int i = 0; i < numEntries; i++)
    {
        transposedMatrix[i].row = matrix[i].col;
        transposedMatrix[i].col = matrix[i].row;
        transposedMatrix[i].value = matrix[i].value;
    }

    printf("\nTranspose of sparse matrix:\n");
    printf("R   C  Element\n");

    for (int i = 0; i < numEntries; i++)
    {
        printf("%d   %d   %d\n", transposedMatrix[i].row, transposedMatrix[i].col, transposedMatrix[i].value);
    }
}

int main()
{
    printf("Enter sparse matrix in 3-tuple format\n");

    int numEntries;
    scanf("%d", &numEntries);

    struct SparseMatrixEntry sparseMatrix[numEntries];
    for (int i = 0; i < numEntries; i++)
    {
        scanf("%d %d %d", &sparseMatrix[i].row, &sparseMatrix[i].col, &sparseMatrix[i].value);
    }

    printf("\nSample Output:\n");
    transposeSparseMatrix(sparseMatrix, numEntries);

    return 0;
}
