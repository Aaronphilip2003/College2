#include <stdio.h>

void displayArray(int length, int arr[10])
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void input(int length, int arr[10])
{
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void bucketSort(int array[], int n)
{
    int i, j;
    int bucket[20];
    for (i = 0; i < 20; i++)
    {
        bucket[i] = 0;
    }
    for (j = 0; j < n; j++)
    {
        ++bucket[array[j]];
    }
    for (i = 0, j = 0; i < 20; i++)
    {
        for (; bucket[i] > 0; --bucket[i])
        {
            array[j] = i;
            j++;
        }
    }
    displayArray(n, array);
}

int main()
{
    int marks[10];
    int records;
    printf("Enter the number of records:\n");
    scanf("%d", &records);
    printf("Enter the marks\n");
    input(records, marks);
    displayArray(records, marks);
    bucketSort(marks, records);
    return 0;
}