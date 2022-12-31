#include <stdio.h>

void displayArray(int length, int arr[10])
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void shellSort(int arr[10], int len)
{
    int gap = len / 2;
    int swapped = 0;
    do
    {
        do
        {
            swapped = 0;
            for (int i = 0; i < len - gap; i++)
            {
                if (arr[i] > arr[i + gap])
                {
                    swap(&arr[i], &arr[i + gap]);
                    swapped = 1;
                }
            }
        } while (swapped == 1);
    } while (gap = gap / 2);
}


void input(int length, int arr[10])
{
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
    }
}


int main()
{
    int array[10];
    printf("Enter 10 numbers in an array:\n");
    input(10, array);
    displayArray(10, array);
    shellSort(array,10);
    displayArray(10,array);
    return 0;
}
