#include<stdio.h>

void input(int a[10])
{
    for(int i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
}

void display(int a[10])
{
    for(int i=0;i<10;i++)
    {
        printf("%d\n",a[i]);
    }
}


int linearSearch(int a[10],int search)
{
    int pos=0;
    int flag=0;
    for(int i=0;i<10;i++)
    {
        if(a[i]==search)
        {
            flag=1;
            pos=i;
        }
    }
    if(flag==1)
    {
        return pos;
    }
    else
    {
        return -1;
    }

}

int main()
{
    int a[10];
    printf("Enter 10 numbers:\n");
    input(a);
    int search;
    printf("Enter the number to be searched:\n");
    scanf("%d",&search);
    int pos=0;
    pos=linearSearch(a,search);
    printf("Element found at %d",pos+1);
    return 0;
}