#include<stdio.h>

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

void insertionSort(int len,int a[10])
{
    int key=0;
    int i=0,j=0;
    for(i=1;i<len;i++)
    {
        key=a[i];// value picked
        j=i-1;
        while(j>=0 && a[j]>key)// going back and checking w every element
        {
            a[j+1]=a[j];// swapping the values
            j=j-1;// going back (decrementing)
        }
        a[j+1]=key;
    }
    displayArray(10,a);
}

int main()
{
    int array[10];
    printf("Enter 10 numbers in an array:\n");
    input(10, array);
    displayArray(10, array);
    insertionSort(10,array);
    return 0;
}