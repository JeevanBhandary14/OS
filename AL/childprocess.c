#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include <stdlib.h>
int main()
{   pid_t pid;
    for (int i = 0; i < 5; i++)
    {   pid = fork();
        if(pid == 0)
        {   printf("\nChild process %d with PID: %d\n", i+1, getpid());
            exit(0);
        }
        else
            wait(NULL);
    }
    return 0;
}
