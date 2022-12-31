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
    printf("NAME \t ROLL NO. \t CURRENT NODE \t NEXT NODE \n");
    while (ptr != NULL)
    {
        printf("%s \t %d \t %x \t %x \t \n", ptr->name, ptr->roll_no, ptr, ptr->next);
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
    char choice;
    do
    {
        struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter Roll No. of student: ");
        scanf("%d", &curr->roll_no);
        printf("Enter the name of student: ");
        scanf("%s", curr->name);
        curr->next = NULL;
        temp->next = curr;
        temp = curr;
        printf("Enter your choice (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');
}

void insert(struct Node *head)
{
    struct Node *temp = head;
    char choice;
    int k = 0;
    int i = 1;
    int pos = 0;
    do
    {
        struct Node *curr = (struct Node *)malloc(sizeof(struct Node)); 
        struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
        curr = head;
        printf("Enter Roll No. of student: ");
        scanf("%d", &nnode->roll_no);
        printf("Enter the name of student: ");
        scanf("%s", nnode->name);
        printf("Enter position to be inserted at: ");
        scanf("%d", &pos);
        k = lengthLL(head);
        if (pos > k + 1)
        {
            printf("Data cannot be inserted\n");
        }
        while (curr != NULL && i < pos)
        {
            i++;
            curr = curr->next;
        }
        nnode->next = curr->next;
        curr->next = nnode;
        printf("Enter your choice (y/n): ");
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
        ctr = 1;
        curr = head->next;
        printf("Enter position to be deleted:\n");
        scanf("%d", &pos);
        k = lengthLL(head);
        if (k < pos)
        {
            printf("Data cannot be deleted\n");
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
            printf("Enter your choice (y/n): ");
            scanf(" %c", &choice);
        }
    } while (choice == 'y');
}

void reverse(struct Node *head)
{
    struct Node *temp = head;
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
    int choice = 0;
    char cont;
    do
    {
        printf("1-INSERT AN ELEMENT\n");
        printf("2-DELETE AN ELEMENT\n");
        printf("3-DISPLAY THE LIST\n");
        printf("4-LENGTH OF THE LIST\n");
        printf("5-INSERT AT POSITION\n");
        printf("6-REVERSE THE LINKED LIST\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            create(head);
        }
        break;
        case 2:
        {
            delete (head);
        }
        break;
        case 3:
        {
            display(head->next);
        }
        break;
        case 4:
        {
            printf("%d\n", lengthLL(head));
        }
        break;
        case 5:
        {
            insert(head);
        }
        break;
        case 6:
        {
            printf("Reversing Linked List....\n");
            reverse(head);
        }
        }
        printf("Do you want to continue (y/n): ");
        scanf(" %c", &cont);
    } while (cont == 'y');

    return 0;
}