#include <stdio.h>
struct stud
{
    int rln;
    char name[10];
    int marks;
};

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void accept(struct stud s[10], int n)
{
    printf("Enter the Rollno , Name , Marks at : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s %d", &s[i].rln, s[i].name, &s[i].marks);
    }
}

void display(struct stud s[10], int n)
{
    printf("Rollno.  Name   Marks :");
    for (int i = 0; i < n; i++)
    {
        printf("\n %d \t  %s  \t  %d", s[i].rln, s[i].name, s[i].marks);
    }
}

int linSearch(struct stud s[10], int k, int n)
{
    int flag = 0, pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (k == s[i].rln)
        {
            pos = i;
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return pos;
    }
    else
    {
        return -1;
    }
}

int binarySearchNR(struct stud s[10], int low, int high, int search)
{
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (s[mid].rln == search)
        {
            return mid;
        }
        else if (search < s[mid].rln)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int binarySearchR(struct stud s[10], int low, int high, int search)
{
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (s[mid].rln == search)
        {
            return mid;
        }
        else if (search < s[mid].rln)
        {
            return binarySearchR(s, low, mid - 1, search);
        }
        else
        {
            return binarySearchR(s, low, mid + 1, search);
        }
    }
}

void displayLinSearch(struct stud s[10], int pos)
{
    printf("Rollno.\tName\tMarks :\n");
    printf("%d \t %s \t %d", s[pos].rln, s[pos].name, s[pos].marks);
}

void displayArray(int length, struct stud s[10])
{
    for (int i = 0; i < length; i++)
    {
        printf("%d \t %s \t %d", s[i].rln, s[i].name, s[i].marks);
        printf("\n");
    }
}

void insertionSort(int len, struct stud s[10])
{
    int n = len;
    struct stud temp;
    int i = 0, j = 0;
    for (i = 1; i < len; i++)
    {
        temp = s[i];
        j = i - 1;
        while (j >= 0 && s[j].rln >  temp.rln)
        {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = temp;
        printf("Pass:%d\n", i);
        displayArray(n, s);
        printf("\n");
    }
    displayArray(n, s);
}

void shellSort(struct stud s[10], int len)
{
    struct stud temp;
    int i = 0;
    int gap = len / 2;
    int swapped = 0;
    do
    {
        do
        {
            swapped = 0;
            for (i = 0; i < len - gap; i++)
            {
                if (s[i].rln > s[i + gap].rln)
                {
                    temp = s[i];
                    s[i] = s[i + gap];
                    s[i + gap] = temp;
                    swapped = 1;
                }
            }
        } while (swapped == 1);
        printf("Pass:\n");
        displayArray(len, s);
        printf("\n");
    } while (gap = gap / 2);
    displayArray(len, s);
}

void selectionSort(int len, struct stud s[10])
{
    int min = s[0].rln;
    struct stud temp;
    for (int i = 0; i < len - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (s[j].rln < s[min].rln)
            {
                min = j;
            }
        }
        if (min != i) // if it is it means that it is in the correct position
        {
            temp = s[min];
            s[min] = s[i];
            s[i] = temp;
        }
        printf("Pass:%d\n", i);
        displayArray(len, s);
        printf("\n");
    }

    displayArray(len, s);
}

int main()
{
    int n;
    int c;
    struct stud s[10];
    printf("Enter the no. of records : ");
    scanf("%d", &n);
    accept(s, n);

    display(s, n);

    printf("\n1-Linear search\n");
    printf("2-Binary search(Non-Recursive)\n");
    printf("3-Binary search(Recursive)\n");
    printf("4-Insertion Sort\n");
    printf("5-Selection Sort\n");
    printf("6-Shell Sort\n");
    printf("Enter your choice : ");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
    {
        int pos;
        printf("\nEnter the roll no to be searched:\n");
        int search;
        scanf("%d", &search);
        pos = linSearch(s, search, n);
        displayLinSearch(s, pos);
        break;
    }
    break;
    case 2:
    {
        int pos = 0;
        printf("\nEnter the roll no to be searched:\n");
        int search;
        scanf("%d", &search);
        pos = binarySearchNR(s, 0, n - 1, search);
        displayLinSearch(s, pos);
    }
    break;
    case 3:
    {
        int pos = 0;
        printf("\nEnter the roll no to be searched:\n");
        int search;
        scanf("%d", &search);
        pos = binarySearchR(s, 0, n - 1, search);
        displayLinSearch(s, pos);
    }
    break;
    case 4:
    {
        insertionSort(n, s);
    }
    break;
    case 5:
    {
        selectionSort(n, s);
    }
    break;
    case 6:
    {
        shellSort(s, n);
    }
    }

    return 0;
}
