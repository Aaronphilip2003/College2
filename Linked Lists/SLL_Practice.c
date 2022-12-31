#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct Node
{  
    char name[20];
    int roll_no;
    struct Node *next;
};

void display(struct Node *ptr)
{
    printf("NAME \t ROLLNO \t CURRENT NODE \t NEXT NODE\n");
    while (ptr != NULL)
    {
        printf("%s \t %d \t         %x \t %x\n", ptr->name, ptr->roll_no, ptr, ptr->next);
        ptr = ptr->next;
    }
}

int lengthLL(struct Node *head)
{
    struct Node *temp = head;
    int len = 0;
    while (temp->next != NULL)
    {
        len += 1;
        temp = temp->next;
    }
    return len;
}

void create(struct Node *head)
{
    struct Node *temp = head;
    int choice = 1;
    do
    {
        struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter your name:");
        scanf("%s", curr->name);
        printf("Enter your Roll No.");
        scanf("%d", &curr->roll_no);
        curr->next = NULL;
        temp->next = curr;
        temp = curr;
        printf("Enter '1' to continue and '0' to exit:");
        scanf("%d", &choice);
    } while (choice == 1);
}

void insert(struct Node *head)
{
    struct Node *temp = head;
    char choice;
    int i = 1;
    int k = 0;
    int pos = 0;
    do
    {
        struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
        struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
        curr = head;
        printf("Enter your name:");
        scanf("%s", nnode->name);
        printf("Enter your Roll No.");
        scanf("%d", &nnode->roll_no);
        printf("Enter the position to be inserted at:");
        scanf("%d", &pos);
        k = lengthLL(head);
        if (pos > k + 1)
        {
            printf("Data cannot be inserted at that position\n");
        }
        while (curr != NULL && i < pos)
        {
            i++;
            curr = curr->next;
        }
        nnode->next = curr->next;
        curr->next = nnode;

        printf("Enter 'y' to continue and 'n' to exit:");
        scanf(" %c", &choice);
    } while (choice == 'y');
}

void delete(struct Node *head)
{
    struct Node *temp = head;
    char choice;
    int ctr;
    int pos;
    int k = 0;
    do
    {
        struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
        struct Node *prev = (struct Node *)malloc(sizeof(struct Node));

        prev = head;
        curr = head->next;
        ctr = 1;
        printf("Enter the position to be inserted:");
        scanf("%d", &pos);
        k = lengthLL(head);
        if (k < pos)
        {
            printf("Cannot be deleted\n");
        }
        else
        {
            while (ctr < pos && curr != NULL)
            {
                ctr++;
                prev = curr;
                curr = curr->next;
            }
            temp = curr;
            prev->next = curr->next;
            curr->next = NULL;
            free(temp);
            printf("Enter y to continue:");
            scanf(" %c", &choice);
        }
    } while (choice == 'y');
}

void reverse(struct Node *head)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *prev = (struct Node *)malloc(sizeof(struct Node));
    struct Node *curr = (struct Node *)malloc(sizeof(struct Node));

    prev = NULL;
    curr = head->next;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head->next = prev;
}

int main()
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->next = NULL;
    create(head);
    display(head->next);
    printf("Length of the list is: %d\n", lengthLL(head));
    insert(head);
    display(head->next);
    printf("Length of the list is: %d\n", lengthLL(head));
    printf("Reverse LL");
    reverse(head);
    display(head);
    return 0;
}