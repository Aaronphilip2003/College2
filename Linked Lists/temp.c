#include <stdio.h>
struct student
{
    int rln;
    char name[10];

    int marks;
};
void accept(struct student s[10], int n)
{
    printf("Enter the roll no., name, marks: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s %d", &s[i].rln, s[i].name, &s[i].marks);
    }
}

void display(struct student s[10], int n)
{
    printf("Roll no.\t Name \t Marks\n");

    for (int i = 0; i < n; i++)
    {

        printf("%d\t\t\t %s\t %d\n", s[i].rln, s[i].name, s[i].marks);
    }
}

int linsearch(struct student s[10], int n, int k)
{
    printf("Enter the roll no. to be searched:");
    scanf("%d", &k);

    for (int i = 0; i < n; i++)
    {
        if (s[i].rln == k)
        {
            return i;
            break;
        }
    }
    return -1;
}
int main()
{
    int n, k;
    int pos = 0;
    struct student s[10];
    printf("Enter number of records:");
    scanf("%d", &n);
    accept(s, n);
    pos = linsearch(s, n, k); // 1
    printf("%d\t %s\t %d\n", s[pos].rln, s[pos].name, s[pos].marks);
    return 0;
}

// 1 3 5 6 7 8 9 10 22