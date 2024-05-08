#include <stdio.h>

struct RQueue {
    int id, arrival, burst, priority, remainingBT, waiting, turnaround, completion;
};

int main() {
    int n, highpriority;
    float totalwaiting = 0, totalturnaround = 0;
    printf("Enter number of processes : ");
    scanf("%d", &n);
    struct RQueue rq[n];
    printf("Enter Arrival time, Burst time and Priority for %d process :\n", n);
    for (int i = 0; i < n; i++) {
        rq[i].id = i + 1;
        scanf("%d", &rq[i].arrival);
        scanf("%d", &rq[i].burst);
        rq[i].remainingBT = rq[i].burst;
        scanf("%d", &rq[i].priority);
    }
    int time = 0, count = 0;
    while (count < n) {
        highpriority = -1;
        for (int i = 0; i < n; i++)
            if (rq[i].arrival <= time && rq[i].remainingBT > 0)
                if (highpriority == -1 || rq[i].priority < rq[highpriority].priority)
                    highpriority = i;
        if (highpriority == -1)
            time++;
        else {
            time += rq[highpriority].burst;
            rq[highpriority].completion = time;
            rq[highpriority].turnaround = rq[highpriority].completion - rq[highpriority].arrival;
            rq[highpriority].waiting = rq[highpriority].turnaround - rq[highpriority].burst;
            totalturnaround += rq[highpriority].turnaround;
            totalwaiting += rq[highpriority].waiting;
            rq[highpriority].remainingBT = 0;
            count++;
        }
    }
    printf("\nProcess Details :\nProcess \tPriority \tAT \tBT \tCT \tTAT \tWT\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\t%d\t%d\t%d\t%d\n", rq[i].id, rq[i].priority, rq[i].arrival,
               rq[i].burst, rq[i].completion, rq[i].turnaround, rq[i].waiting);

    printf("\n\nTotal Waiting Time : %.2f\t\tAvg Waiting Time : %.2f\n", totalwaiting, totalwaiting / n);
    printf("Total Turn around Time : %.2f\tAvg Turn around Time : %.2f\n", totalturnaround, totalturnaround / n);

    return 0;
}

