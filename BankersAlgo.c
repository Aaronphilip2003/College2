#include <stdio.h>
int main()
{
    int n = 5; // number of processes
    int m = 3; // number of resource types
    int Allocation_Matrix[n][m];
    int Max_Matrix[n][m];
    int Available_Matrix[3];
    int Need_Matrix[n][m];
    int Work_Matrix[3];
    int Safety_Sequence[5];
    int safePos = 0;
    int finishFlags[5] = {0, 0, 0, 0, 0};

    printf("Enter the Resources for Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Enter Resource %d of Process %d:", j, i);
            scanf("%d", &Allocation_Matrix[i][j]);
        }
    }

    printf("Enter the Resources for the Max Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Enter Resource %d of Process %d:", j, i);
            scanf("%d", &Max_Matrix[i][j]);
        }
    }

    Available_Matrix[0] = 1; // 3
    Available_Matrix[1] = 1;
    Available_Matrix[2] = 2;

    for (int i = 0; i < n; i++)// Processes
    {
        for (int j = 0; j < m; j++)
        {
            Need_Matrix[i][j] = Max_Matrix[i][j] - Allocation_Matrix[i][j];
        }
    }

    printf("NEED MATRIX\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", Need_Matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
    {
        Work_Matrix[i] = Available_Matrix[i];
    }

    for (int k = 0; k <= n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < m; j++)
            {
                if (Need_Matrix[i][j] <= Work_Matrix[j])
                {
                    count++;
                }
            }
            if (count == 3 && finishFlags[i] == 0)
            {
                Safety_Sequence[safePos] = i;
                safePos++;
                finishFlags[i] = 1;
                for (int j = 0; j < m; j++)
                {
                    Work_Matrix[j] = Work_Matrix[j] + Allocation_Matrix[i][j];
                }
            }
        }
        if (safePos == 5)
        {
            break;
        }
    }

    if (safePos == 5)
    {
        printf("\nSystem is Safe\n");
        for (int i = 0; i < n; i++)
        {
            printf("P%d\n", Safety_Sequence[i]);
        }
    }
    else
    {
        printf("\nSystem is Safe:");
    }

    return 0;
}