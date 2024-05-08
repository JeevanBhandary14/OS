#include<stdio.h>
#include<string.h>

struct RQueue
{   
    char name[10];
    int  burst, waiting, turnaround;
};

void bubbleSort(struct RQueue *rq, int n)
{   
    struct RQueue temp;
    for(int i = 0; i < n; i++)
    {   
        for(int j = 0; j < n - i - 1; j++)
        {   
            if(rq[j].burst > rq[j+1].burst)
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

    printf("\nEnter process name and Burst time for %d Processes : \n", n);
    for(int i = 0; i < n; i++)
    {   
        scanf("%s %d", rq[i].name, &rq[i].burst);
    }

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

    printf("\nProcess Details :\n");
    for(int i = 0; i < n; i++)
       	printf("Name : %s\tBurst Time : %d\tWaiting Time : %d\tTurn around Time : %d\n", rq[i].name, rq[i].burst, rq[i].waiting, rq[i].turnaround);
    
    printf("\nTotal Waiting Time : %d\t\tAvg Waiting Time : %.2f\n", totalwaiting, avgwaiting);
    printf("Total Turn around Time : %d\tAvg Turn around Time : %.2f\n", totalturnaround, avgturnaround);

    return 0;
}

