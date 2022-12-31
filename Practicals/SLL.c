#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[20];
    int prn;
    struct Node *next;
};

void display(struct Node *ptr)
{
    printf("NAME\tPRN\t        CURRENT_NODE\tNEXT_NODE\n");
    while (ptr != NULL)
    {
        printf("%s\t%d\t %x\t      %x\n", ptr->name, ptr->prn, ptr, ptr->next);
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
    char ch;
    do
    {
        struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the Name of the student:");
        scanf("%s", curr->name);
        printf("Enter the PRN of the student:");
        scanf("%d", &curr->prn);
        curr->next = NULL;
        temp->next = curr;
        temp = curr;

        printf("Do you want to add more Nodes (y/n)\n");
        scanf(" %c", &ch);
    } while (ch == 'y');
}

void insert(struct Node *head)
{
    struct Node *temp = head;
    int i = 1, k = 0, pos = 0;
    char ch;
    do
    {
        struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
        struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
        curr = head;
        printf("Enter the Name of the student:");
        scanf("%s", nnode->name);
        printf("Enter the PRN of the student:");
        scanf("%d", &nnode->prn);
        printf("Enter the position to be inserted:");
        scanf("%d", &pos);
        k = lengthLL(head);
        if (pos > k + 1)
        {
            printf("Data cannot be inserted at the specified position\n");
        }
        while (curr != NULL && i < pos)
        {
            i++;
            curr = curr->next;
        }
        nnode->next = curr->next;
        curr->next = nnode;
        printf("Do you want to add more Nodes (y/n)\n");
        scanf(" %c", &ch);
    } while (ch == 'y');
}

void delete(struct Node *head)
{
    struct Node *temp = head;
    int k = 0, pos = 0, ctr;
    char ch;
    do
    {
        struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
        struct Node *prev = (struct Node *)malloc(sizeof(struct Node));
        prev = head;
        ctr = 1;
        curr = head->next;
        printf("Enter the position to be deleted:");
        scanf("%d", &pos);
        k = lengthLL(head);
        if (k < pos)
        {
            printf("Data cannot be deleted at the specified location\n");
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
        }
        printf("Do you want to delete more Nodes (y/n)\n");
        scanf(" %c", &ch);
    } while (ch == 'y');
}

void reverse(struct Node *head)
{
    struct Node *temp = head;
    struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *prev = (struct Node *)malloc(sizeof(struct Node));
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
    insert(head);
    display(head->next);
    delete (head);
    display(head->next);
    int len = lengthLL(head);
    printf("The Length of the Linked List is: %d\n", len);
    reverse(head);
    printf("The Reverse of the Linked List is:\n");
    display(head->next);

    return 0;
}