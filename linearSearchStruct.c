#include <stdio.h>

struct Stud
{
    int rollno;
    char name[100];
    int marks;
};

void accept(struct Stud s[10], int n)
{
    printf("Enter the Roll no, Name and Marks:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s %d", &s[i].rollno, s[i].name, &s[i].marks);
    }
}

void display(struct Stud s[10], int n)
{
    printf("\nROLLNO.\tNAME\tMARKS\t\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t%d\t\n", s[i].rollno, s[i].name, s[i].marks);
    }
}

void displayLinearSearch(struct Stud s[10], int pos)
{
    printf("\nROLLNO.\tNAME\tMARKS\t\n");
    printf("%d\t%s\t%d\t\n", s[pos].rollno, s[pos].name, s[pos].marks);
}

int linearSearch(struct Stud s[10], int search, int n)
{
    int flag = 0;
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].rollno == search)
        {
            flag = 1;
            pos = i;
            break;
        }
    }
    if (flag == 1)
    {
        return pos;
    }
}

int main()
{
    struct Stud s[10];
    int n;
    printf("Enter the number of records to be entered:");
    scanf("%d", &n);
    accept(s, n);
    display(s, n);
    printf("Enter the roll no. whose marks need to be searched:");
    int rollno;
    scanf("%d", &rollno);
    printf("-----------------------MENU-----------------------\n");
    printf("1-Linear Search\n");
    printf("2-Binary Search (Non-recursive)\n");
    printf("3-Binary Search (Recursive)\n");
    printf("Enter your choice:\n");
    int ch = 0;
    scanf("%d", &ch);
    int cont = 0;
    do
    {
        switch (ch)
        {
        case 1:
        {
            int pos;
            pos = linearSearch(s, n, rollno);
            displayLinearSearch(s, pos);
        }
        break;

        default:
            break;
        }
        printf("Do you wish to continue? (1 for yes 0 for no):\n");
        scanf("%d", &cont);

    } while (cont != 0);
    return 0;
}