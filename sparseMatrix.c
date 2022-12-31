#include <stdio.h>
void matrixInput(int m, int n, int matrix[10][10]);
void sparseMatrix(int m, int n, int matrix[10][10]);

void matrixInput(int m, int n, int matrix[10][10])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void matrixDisplay(int m, int n, int matrix[10][10])
{
    for (int i = 0; i < m; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
    }
}

void sparseMatrix(int m, int n, int matrix[10][10])
{
    int sparseMatrix[10][10];
    sparseMatrix[0][0] = m;
    sparseMatrix[0][1] = n;
    int k = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparseMatrix[k][0] = i;            // m
                sparseMatrix[k][1] = j;            // n
                sparseMatrix[k][2] = matrix[i][j]; // values
                k++;                               // 9
            }
        }
    }
    sparseMatrix[0][2] = k - 1; // 9-1=8
    matrixDisplay(k, 3, sparseMatrix);
}

int main()
{
    int m, n, matrix[10][10];
    printf("Enter the rows:\n");
    scanf("%d", &m);
    printf("Enter the columns:\n");
    scanf("%d", &n);
    printf("Enter the values:\n");
    matrixInput(m, n, matrix);
    matrixDisplay(m, n, matrix);
    printf("--------------------------------------\n");
    sparseMatrix(m, n, matrix);
    return 0;
}
