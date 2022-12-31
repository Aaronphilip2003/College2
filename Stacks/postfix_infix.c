#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSIZE 100
char s[30][30];
int top = -1;

int isFull()
{
    if (top == MAXSIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(char str[MAXSIZE])
{
    if (isFull())
    {
        printf("The stack is Full\n");
    }
    else
    {
        strcpy(s[++top], str);
    }
}

void pop(char str[20])
{
    if (isEmpty() == 1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        strcpy(str, s[top--]);
    }
}

void postToinfx(char post[MAXSIZE])
{
    char s1[MAXSIZE], s2[MAXSIZE], s3[MAXSIZE], temp[MAXSIZE], inf[MAXSIZE];
    for (int i = 0; post[i] != '\0'; i++)
    {
        s1[0] = post[i];
        s1[1] = '\0';
        if (isalpha(post[i]) != 0)
        {

            push(s1);
        }
        else
        {
            pop(s2);
            pop(s3);
            strcpy(inf, "(");
            strcat(inf, s3);
            strcat(inf, s1);
            strcat(inf, s2);
            strcat(inf, ")");
            push(inf);
        }
    }
    pop(inf);
    printf("The infix expression is:");
    printf("\n%s", inf);
}

void postToPrefx(char post[MAXSIZE])
{
    char s1[MAXSIZE], s2[MAXSIZE], s3[MAXSIZE], temp[MAXSIZE], pre[MAXSIZE];
    for (int i = 0; post[i] != '\0'; i++)
    {
        s1[0] = post[i];
        s1[1] = '\0';
        if (isalpha(post[i]) != 0)
        {
            push(s1);
        }
        else
        {
            pop(s2);
            pop(s3);
            strcat(pre, s1);
            strcat(pre, s3);
            strcat(pre, s2);
            push(pre);
        }
    }
    pop(pre);
    printf("The prefix expression is:");
    printf("\n%s", pre);
}

int main()
{
    char exp[20];
    printf("Enter the exp:");
    scanf("%s", exp);
    postToinfx(exp);
    // postToPrefx(exp);
}

// AB+C-D*EF+-
// ((((A+B)-C)*D)-(E+F))