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

void linearSearch(int n, int arr[100], int search)
{
    int flag = 0;
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
            flag = 1;
            pos = i;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Search Element found at %d position", pos + 1);
    }
    else
    {
        printf("Search Element not found");
    }
}

void binarySearchNR(int n, int low, int high, int arr[100], int search)
{
    int mid = 0;
    high = n - 1;
    int pos = 0;
    int flag = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == search)
        {
            flag = 1;
            pos = mid;
            break;
        }
        else if (search < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (flag == 1)
    {
        printf("Search Element found at %d position", pos + 1);
    }
    else
    {
        printf("Search Element not found");
    }
}

void binarySearchR(int n, int low, int high, int arr[100], int search)
{
    int mid = 0;
    high = n - 1;
    int pos = 0;
    int flag = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == search)
        {
            flag = 1;
            pos = mid;
            break;
        }
        else if (search < arr[mid])
        {
            binarySearchR(n, 0, mid - 1, arr, search);
        }
        else
        {
            binarySearchR(n, 0, mid + 1, arr, search);
        }
    }
    if (flag == 1)
    {
        printf("Search Element found at %d position", pos + 1);
    }
    else
    {
        printf("Search Element not found");
    }
}

int main()
{
    printf("Enter n:");
    int n = 0;
    int arr[100];
    int search = 0;
    scanf("%d", &n);
    printf("Enter the values in the array:\n");
    accept(n, arr);
    display(n, arr);
    printf("Enter the value to be searched:");
    scanf("%d", &search);
    // linearSearch(n, arr, search);
    // binarySearchNR(n, 0, n - 1, arr, search);
    binarySearchR(n, 0, n - 1, arr, search);
}
