#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main()
{
    pid_t x;
    x = fork();

    if (x == 0)
    {
        printf("Process Id of Parent : %d\n", getpid());
    }
    else
    {
        sleep(2);
        system("ps -axj | tail");
    }
}