#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

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

void bubbleSort(int len, int arr[100])
{
    int temp;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    int array[100];
    printf("Enter Number of colors:\n");
    int n;
    scanf("%d",&n);
    printf("Enter n colors in an array:\n");
    input(n, array);
    displayArray(n, array);
    bubbleSort(n, array);
    displayArray(n, array);
    return 0;
}