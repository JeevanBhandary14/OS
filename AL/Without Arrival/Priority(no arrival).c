#include<stdio.h>
#include<string.h>

struct RQueue
{   
    char name[10];
    int  priority, burst, waiting, turnaround;
};

void bubbleSort(struct RQueue *rq, int n)
{   
    struct RQueue temp;
    for(int i = 0; i < n; i++)
    {   
        for(int j = 0; j < n - i - 1; j++)
        {   
            if(rq[j].priority > rq[j+1].priority)
            {   
                temp = rq[j];
                rq[j] = rq[j+1];
                rq[j+1] = temp;
            }
        }
    }
}

int main()
{   
    int n, totalwaiting = 0, totalturnaround = 0;
    float avgwaiting, avgturnaround;
    printf("Enter total number of process : ");
    scanf("%d", &n);
    struct RQueue rq[n];

    printf("\nEnter process name, Priority and Burst time for %d Processes : \n", n);
    for(int i = 0; i < n; i++)
        scanf("%s %d %d", rq[i].name, &rq[i].priority, &rq[i].burst);

    bubbleSort(rq, n);

    for(int i = 0; i < n; i++)
    {   
        if(i == 0)
            rq[i].waiting = 0;
        else
           rq[i].waiting = rq[i-1].waiting + rq[i-1].burst;
        rq[i].turnaround = rq[i].waiting + rq[i].burst;

        totalwaiting += rq[i].waiting;
        totalturnaround += rq[i].turnaround;
    }
    avgwaiting = (float)totalwaiting / n;
    avgturnaround = (float)totalturnaround / n;

    printf("\nProcess Details :\nName\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(int i = 0; i < n; i++)
       	printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n", rq[i].name, rq[i].priority, rq[i].burst, rq[i].waiting, rq[i].turnaround);
    
    printf("\n\nTotal Waiting Time : %d\t\tAvg Waiting Time : %.2f\n", totalwaiting, avgwaiting);
    printf("Total Turnaround Time : %d\tAvg Turnaround Time : %.2f\n", totalturnaround, avgturnaround);

    return 0;
}

