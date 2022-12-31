#include <stdio.h>
#include <ctype.h>
#define MAXSIZE 100
char stack[MAXSIZE];
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

void push(char item)
{
    if (!isFull())
    {
        top = top + 1;
        stack[top] = item;
    }
    else
    {
        printf("Stack is Full\n");
    }
}

char pop()
{
    if (!isEmpty())
    {
        char temp = stack[top];
        top = top - 1;
        return temp;
    }
    else
    {
        printf("The stack is empty\n");
    }
}

int main()
{
    char string[20];
    scanf("%s", string); // a+((b-c)+d)
    for (int i = 0; i < 12; i++)
    {
        if (string[i] == 'a' || string[i] == 'b' || string[i] == 'c' || string[i] == 'd' || string[i] == '+' || string[i] == '-')
        {
            printf("%c", string[i]);
        }
        else if (string[i] == '(')
        {
            push(string[i]);
        }
        else if (string[i] == ')')
        {
            pop();
        }
    }
}