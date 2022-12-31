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

void selectionSort(int len,int a[10])
{
    int min=a[0],temp;
    for(int i=0;i<len-1;i++)
    {
        min=i;
        for(int j=i+1;j<len;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if (min!=i) // if it is it means that it is in the correct position
        {
            temp=a[min];
            a[min]=a[i];
            a[i]=temp;
        }
    }
    
    displayArray(len,a);
}


int main()
{
    int array[10];
    printf("Enter 10 numbers in an array:\n");
    input(10, array);
    displayArray(10, array);
    selectionSort(10,array);
    return 0;
}