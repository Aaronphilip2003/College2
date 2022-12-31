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

int icp(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    if (ch == '(')
        return 4;
    else
        return 0;
}

int isp(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    else
        return 0;
}

int postfix(char expression[])
{
    int k = 0, i = 0;
    char postexpression[100];
    char token;
    token = expression[i];
    while (token != '\0')
    {
        if (isalpha(token) != 0)//isalpha returns non zero for chars
        {
            postexpression[k] = expression[i];
            k++;
        }
        else
        {
            if (token == '(')
            {
                push('(');
            }
            else
            {
                if (token == ')')
                {
                    while ((token = pop()) != '(')
                    {
                        postexpression[k] = token;
                        k++;
                    }
                }
                else
                {
                    while (!isEmpty() && isp(stack[top]) >= icp(token))
                    {
                        postexpression[k] = pop();
                        k++;
                    }
                    push(token);
                }
            }
        }
        i++;
        token = expression[i];
    }
    while (!isEmpty())
    {
        postexpression[k] = pop();
        k++;
    }
    expression[++k] = '\0';
    printf("%s", postexpression);
}

int calc(int c1,int c2,char op)
{
    int ans;
    switch(op)
    {
        case '+':
        {
            ans=c1+c2;
        }
        break;
        case '-':
        {
            ans=c1-c2;
        }
        break;
        case '*':
        {
            ans=c1*c2;
        }
        break;
        case '/':
        {
            ans=c1/c2;
        }
        break;
    }
    return ans;
}

void eval(char post[MAXSIZE])
{
    int z;
    int op1,op2;
    int ans;
    for(int i=0;post[i]!='\0';i++)
    {
        if(isalpha(post[i])!=0)
        {
            printf("Enter the value of %c:",post[i]);
            scanf("%d",&z);
            push(z);
        }
        else
        {
            op1=pop();
            op2=pop();
            ans=calc(op2,op1,post[i]);
            push(ans);
        }
    }
    printf("Evaluation is :");
    printf("%d",stack[top]);
}

int main()
{
    char expression[20] = "A*(B*C+D*E)+F";
    char expression2[20] = "A*B/(A-D)+C*B";
    char expression3[20] = "A*B+B*B";
    char expression4[20]="aaa*+bca/bc*+";
    char expression5[20]="A+B";
    // eval(expression4);
    // a=2 b=1 c=0
    
    postfix(expression5);
    

    return 0;
}

// int choice, cont = 0;
// char element;
// do
// {
//     printf("1-Push Element\n");
//     printf("2-Pop Element\n");
//     printf("Enter your choice:\n");
//     scanf("%d", &choice);
//     switch (choice)
//     {
//     case 1:
//     {
//         printf("Enter the character to be pushed:\n");
//         scanf(" %c", &element);
//         push(element);
//     }
//     break;
//     case 2:
//     {
//         element = pop();
//         printf("Popped Element:%c\n", element);
//     }
//     break;
//     default:
//     {
//         printf("INVALID INPUT\n");
//     }
//     }

//     printf("Enter 0 to continue 1 to terminate:");
//     scanf("%d", &cont);
// } while (cont == 0);