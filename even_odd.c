
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

void even_nos(int n)
{
	int i;
	i = 1;
	while (i <= n)
	{
		if (i % 2 == 0)
		{
			printf("%d", i);
		}
		i++;
	}
}

void odd_nos(int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (i % 2 != 0)
		{
			printf("%d", i);
		}
	}
}

int main()
{
	pid_t x;
	int l;
	printf("enter the limit \n");
	scanf("%d", &l);
	x = fork();
	if (x == 0)
	{
		even_nos(l);
	}
	else
	{
		// wait(NULL);
		odd_nos(l);
	}
	return 0;
}
