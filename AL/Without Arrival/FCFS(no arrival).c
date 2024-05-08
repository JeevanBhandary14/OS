#include<stdio.h>

struct RQueue
{   
    char name[10];
    int  burst, waiting, turnaround;
};

int main()
{   
    int n,totalwaiting=0,totalturnaround=0;
    float avgwaiting, avgturnaround;
    printf("Enter total number of process : ");
    scanf("%d", &n);
    struct RQueue rq[n];

    printf("\nEnter process name and Burst time for %d Processes : \n", n);
    for(int i=0;i<n;i++)
    {   
        scanf("%s %d", rq[i].name, &rq[i].burst);
    }


    for(int i=0;i<n;i++)
    {   
        if(i==0)
            rq[i].waiting = 0;
        else
           rq[i].waiting = rq[i-1].waiting + rq[i-1].burst;
        rq[i].turnaround = rq[i].waiting + rq[i].burst;

        totalwaiting += rq[i].waiting;
        totalturnaround += rq[i].turnaround;
    }
    avgwaiting = (float)totalwaiting/n;
    avgturnaround = (float)totalturnaround/n;

    printf("\nProcess Details :");
    for(int i=0;i<n;i++)
       	printf("\nName : %s\tBurst Time : %d\tWaiting Time : %d\tTurn around Time : %d", rq[i].name, rq[i].burst, rq[i].waiting, rq[i].turnaround);
    
    printf("\n\nTotal Waiting Time : %d\t\tAvg Waiting Time : %.2f", totalwaiting, avgwaiting);
    printf("\nTotal Turn around Time : %d\tAvg Turn around Time : %.2f", totalturnaround, avgturnaround);

    return 0;
}

