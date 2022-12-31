#include <stdio.h>
void matrixInput(int m, int n, int matrix[10][10]);
void matrixDisplay(int m1, int n1, int matrix[10][10]);
void matrixAddition(int m1, int n1, int m2, int n2, int matrix1[10][10], int matrix2[10][10], int addMatrix[10][10]);
void matrixMultiplication(int m1, int n1, int m2, int n2, int matrix1[10][10], int matrix2[10][10], int multMatrix[10][10]);
void diagonalAddition(int m1, int n1, int matrix[10][10]);

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

void matrixDisplay(int m1, int n1, int matrix[10][10])
{
    for (int i = 0; i < m1; i++)
    {
        printf("\n");
        for (int j = 0; j < n1; j++)
        {
            printf("%d ", matrix[i][j]);
        }
    }
}

void matrixAddition(int m1, int n1, int m2, int n2, int matrix1[10][10], int matrix2[10][10], int addMatrix[10][10])
{

    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            addMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrixSubtraction(int m1, int n1, int m2, int n2, int matrix1[10][10], int matrix2[10][10], int addMatrix[10][10])
{

    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            addMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void matrixMultiplication(int m1, int n1, int m2, int n2, int matrix1[10][10], int matrix2[10][10], int multMatrix[10][10])
{

    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            multMatrix[i][j] = 0;
            for (int k = 0; k < n1; k++)
            {
                multMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    matrixDisplay(m1, n2, multMatrix);
}

void matrixTranspose(int m1, int n1, int matrix[10][10])
{
    int transpose[10][10];
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
    matrixDisplay(n1, m1, transpose);
}

void diagonalAddition(int m1, int n1, int matrix[10][10])
{
    int add = 0;
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            if (i == j)
            {
                add += matrix[i][j];
            }
        }
    }
    printf("\nAddition:%d", add);
}

int matrixTriangularityCheckU(int m,int n,int matrix[10][10])
{
    for(int i=1;i<m;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(matrix[i][j]!=0)
            return 0;
        }
    }
    return 1;
}

int matrixTriangularityCheckL(int m,int n,int matrix[10][10])
{
    for(int i=0;i<m-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(matrix[i][j]!=0)
            return 0;
        }
    }
    return 1;
}


int main()
{
    int cont = 10;
    do
    {
        int choice;
        printf("1-Addition of two Matrices\n");
        printf("2-Multiplication of two Matrices\n");
        printf("3-Transpose of two Matrices\n");
        printf("4-Subtraction of two Matrices\n");
        printf("5-Addition of Diagonal\n");
        printf("6-Check for upper triangular matrix\n");
        printf("7-Check for lower triangular matrix\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int m1, n1;
            printf("Enter the number of rows of the first matrix:");
            scanf("%d", &m1);
            printf("Enter the number of columns of the first matrix:");
            scanf("%d", &n1);
            int matrix1[10][10];

            int m2, n2;
            printf("\nEnter the number of rows of the second matrix:");
            scanf("%d", &m2);
            printf("Enter the number of columns of the second matrix:");
            scanf("%d", &n2);
            int matrix2[10][10];
            int addMatrix[10][10];

            if (m1 == m2 && n1 == n2)
            {
                printf("\nEnter the elements of the first matrix\n");
                matrixInput(m1, n1, matrix1);

                printf("Enter the elements of the second matrix\n");
                matrixInput(m2, n2, matrix2);

                printf("Matrix 1:");
                matrixDisplay(m1, n1, matrix1);

                printf("\nMatrix 2:");
                matrixDisplay(m2, n2, matrix2);

                printf("\nAddition:");
                matrixAddition(m1, n1, m2, n2, matrix1, matrix2, addMatrix);
                matrixDisplay(m1, n1, addMatrix);
            }
            else
            {
                printf("You cannot add the two matrices!");
            }
        }
        break;
        case 2:
        {
            int m1, n1;
            printf("Enter the number of rows of the first matrix:");
            scanf("%d", &m1);
            printf("Enter the number of columns of the first matrix:");
            scanf("%d", &n1);
            int matrix1[10][10];

            int m2, n2;
            printf("\nEnter the number of rows of the second matrix:");
            scanf("%d", &m2);
            printf("Enter the number of columns of the second matrix:");
            scanf("%d", &n2);
            int matrix2[10][10];

            int multMatrix[10][10];

            if (n1 == m2)
            {
                printf("\nEnter the elements of the first matrix\n");
                matrixInput(m1, n1, matrix1);

                printf("Enter the elements of the second matrix\n");
                matrixInput(m2, n2, matrix2);

                printf("Matrix 1:");
                matrixDisplay(m1, n1, matrix1);

                printf("\nMatrix 2:");
                matrixDisplay(m2, n2, matrix2);

                printf("\nMultiplication:");
                matrixMultiplication(m1, n1, m2, n2, matrix1, matrix2, multMatrix);
            }
            else
            {
                printf("You cannot multiply the two matrices!");
            }
        }
        break;
        case 3:
        {
            int m1, n1;
            printf("Enter the number of rows of the matrix:");
            scanf("%d", &m1);
            printf("Enter the number of columns of the matrix:");
            scanf("%d", &n1);
            int matrix1[10][10];
            printf("\nEnter the elements:\n");
            matrixInput(m1, n1, matrix1);
            matrixTranspose(m1, n1, matrix1);
        }
        break;
        case 4:
        {
            int m1, n1;
            printf("Enter the number of rows of the first matrix:");
            scanf("%d", &m1);
            printf("Enter the number of columns of the first matrix:");
            scanf("%d", &n1);
            int matrix1[10][10];

            int m2, n2;
            printf("\nEnter the number of rows of the second matrix:");
            scanf("%d", &m2);
            printf("Enter the number of columns of the second matrix:");
            scanf("%d", &n2);
            int matrix2[10][10];
            int addMatrix[10][10];

            if (m1 == m2 && n1 == n2)
            {
                printf("\nEnter the elements of the first matrix\n");
                matrixInput(m1, n1, matrix1);

                printf("Enter the elements of the second matrix\n");
                matrixInput(m2, n2, matrix2);

                printf("Matrix 1:");
                matrixDisplay(m1, n1, matrix1);

                printf("\nMatrix 2:");
                matrixDisplay(m2, n2, matrix2);

                printf("\nAddition:");
                matrixSubtraction(m1, n1, m2, n2, matrix1, matrix2, addMatrix);
                matrixDisplay(m1, n1, addMatrix);
            }
            else
            {
                printf("You cannot subtract the two matrices!");
            }
        }
        break;
        case 5:
        {
            int m1, n1;
            printf("Enter the number of rows of the first matrix:");
            scanf("%d", &m1);
            printf("Enter the number of columns of the first matrix:");
            scanf("%d", &n1);
            int matrix1[10][10];
            printf("\nEnter the elements of the first matrix\n");
            matrixInput(m1, n1, matrix1);
            matrixDisplay(m1, n1, matrix1);
            diagonalAddition(m1, n1, matrix1);
        }
        break;
        case 6:
        {
            int m, n;
            printf("Enter the number of rows of the first matrix:");
            scanf("%d", &m);
            printf("Enter the number of columns of the first matrix:");
            scanf("%d", &n);    
            int matrix1[10][10];
            printf("\nEnter the elements of the matrix\n");
            matrixInput(m, n, matrix1);
            matrixDisplay(m, n, matrix1);
            if(matrixTriangularityCheckU(m,n,matrix1)==1)
            {
                printf("\nUpper Triangular\n");
            }
            else
            {
                printf("\nNot Upper Triangular\n");
            }
        }
        break;
        case 7:
        {
            int m, n;
            printf("Enter the number of rows of the first matrix:");
            scanf("%d", &m);
            printf("Enter the number of columns of the first matrix:");
            scanf("%d", &n);    
            int matrix1[10][10];
            printf("\nEnter the elements of the matrix\n");
            matrixInput(m, n, matrix1);
            matrixDisplay(m, n, matrix1);
            if(matrixTriangularityCheckL(m,n,matrix1)==1)
            {
                printf("\nLower Triangular\n");
            }
            else
            {
                printf("\nNot Lower Triangular\n");
            }
        }
        }
        printf("\nDo you want to continue? 1 for yes 0 for no:\n");
        scanf("%d", &cont);
    } while (cont != 0);

    return 0;
}