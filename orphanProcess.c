#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    pid_t x;
    x = fork();

    if (x > 0)
    {
        printf("Process Id of Parent : %d\n", getpid());
    }
    else
    {
        printf("Initial parent process Id of Child:%d\n", getppid());
        sleep(2);
        printf("New parent id of process:%d\n", getppid());
    }
}