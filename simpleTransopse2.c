#include <stdio.h>
void matrixInput(int m, int n, int matrix[10][10]);
int sMatrix(int m, int n, int matrix[10][10], int sparseMatrix[10][10]);
int simpleT(int sparseMatrix[10][10], int sTranspose[10][10]);

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

int sMatrix(int m, int n, int matrix[10][10], int sparseMatrix[10][10])
{
    sparseMatrix[0][0] = m;
    sparseMatrix[0][1] = n;
    int k = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    sparseMatrix[0][2] = k - 1;

    return k;
}

int simpleT(int sparseMatrix[10][10], int sTranspose[10][10])
{
    int q, t,m,n;
    m=sparseMatrix[0][0];
    n=sparseMatrix[0][1];
    t = sparseMatrix[0][2];
    sTranspose[0][0] = n;
    sTranspose[0][1] = m;
    sTranspose[0][2] = t;
    if (t <= 0)
        return 0;
    q = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            if (sparseMatrix[j][1] == i)
            {
                sTranspose[q][0] = sparseMatrix[j][1];
                sTranspose[q][1] = sparseMatrix[j][0];
                sTranspose[q][2] = sparseMatrix[j][2];
                q++;
            }
        }
    }
    return q;
}

int fastT(int sparseMatrix[10][10],int fTranspose[10][10])
{
    int S[100],T[100];
    int j,m,n,t;
    m=sparseMatrix[0][0];
    n=sparseMatrix[0][1];
    t=sparseMatrix[0][2];

    fTranspose[0][1]=m;
    fTranspose[0][0]=n;
    fTranspose[0][2]=t;

    if (t<0)
    {
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        S[i]=0;
    }
    for(int i=0;i<t;i++)
    {
        S[sparseMatrix[i][1]]=S[sparseMatrix[i][1]]+1;
    }
    T[0]=1;
    for(int i=0;i<n;i++)
    {
        T[i]=T[i-1]+S[i-1];
    }
    for(int i=1;i<t;i++)
    {
        j=sparseMatrix[0][1];
        fTranspose[T[j]][0]=sparseMatrix[i][1];
        fTranspose[T[j]][1]=sparseMatrix[i][0];
        fTranspose[T[j]][2]=sparseMatrix[i][2];
        T[j]++;
    }
    return n;
}


int main()
{
    int m, n, matrix[10][10], k, q, sparseMatrix[10][10], sTranspose[10][10];
    int fTranspose[10][10];
    printf("Enter the rows:\n");
    scanf("%d", &m);
    printf("Enter the columns:\n");
    scanf("%d", &n);
    printf("Enter the values:\n");
    matrixInput(m, n, matrix);
    matrixDisplay(m, n, matrix);
    int cont = 10;
    do
    {
        int choice;
        printf("\n\n");
        printf("1 for compact matrix\n");
        printf("2 for simple transpose\n");
        printf("3 for complex transpose\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("\n\n");
            k = sMatrix(m, n, matrix, sparseMatrix);
            matrixDisplay(k, 3, sparseMatrix);
        }
        break;
        case 2:
        {
            printf("case for simple transpose");
            q = simpleT(sparseMatrix, sTranspose);
            matrixDisplay(q, 3, sTranspose);
        }
        break;
        case 3:
        {
            printf("case for fast transpose");
            n=fastT(sparseMatrix,fTranspose);
            matrixDisplay(n,3,fTranspose);
        }
        break;
        }
        printf("\nDo you want to continue? 1 for yes 0 for no:\n");
        scanf("%d", &cont);

    } while (cont != 0);
    return 0;
}