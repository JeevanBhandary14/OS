#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include <stdlib.h>
int main() {
    int i;

    for (i = 1; i <= 10; i++)
    {
        if (fork() == 0)
        {
            printf("%d\n", i);
            break;
        }
        else
            wait(NULL);
    }

    return 0;
}
