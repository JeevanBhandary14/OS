
#include <unistd.h>
#include<stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    pid = fork();

    if (pid == 0)
        printf("I am child, my ID is %d and my parent's ID is %d\n", getpid(), getppid());
    else
        printf("I am parent, my ID is %d and my child's ID is %d\n", getpid(), pid);

    return 0;
}
