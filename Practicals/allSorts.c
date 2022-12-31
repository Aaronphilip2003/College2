#include <stdio.h>

void accept(int n, int arr[100])
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void display(int n, int arr[100])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int n, int arr[100])
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void shellSort(int n, int arr[100])
{
    int gap = n / 2;
    int swapped = 0;
    int temp = 0;
    do
    {
        do
        {
            swapped = 0;
            for (int i = 0; i < n - gap; i++)
            {
                if (arr[i] > arr[i + gap])
                {
                    temp = arr[i];
                    arr[i] = arr[i + gap];
                    arr[i + gap] = temp;
                    swapped = 1;
                }
            }
        } while (swapped == 1);
    } while (gap = gap / 2);
}

void selectionSort(int n, int arr[100])
{
    int min = arr[0];
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

void insertionSort(int n, int arr[100])
{
    int j = 0, i = 0;
    int key = 0;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        display(n, arr);
    }
}

void bucketSort(int n, int arr[20])
{
    int bucket[20];
    int i, j;
    for (i = 0; i < 20; i++)
    {
        bucket[i] = 0;
    }
    for (j = 0; j < n; j++)
    {
        ++bucket[arr[j]];
    }
    for (i = 0, j = 0; i < 20; i++)
    {
        for (; bucket[i] > 0; --bucket[i])
        {
            arr[j] = i;
            j++;
        }
    }
}

int main()
{
    printf("Enter n:\n");
    int n = 0;
    int array[100];
    scanf("%d", &n);
    printf("Enter elements:\n");
    accept(n, array);
    display(n, array);
    // bubbleSort(n, array);
    // selectionSort(n, array);
    // insertionSort(n, array);
    // shellSort(n, array);
    bucketSort(n, array);
    printf("THE SORTED ARRAY IS:\n");
    display(n, array);
}