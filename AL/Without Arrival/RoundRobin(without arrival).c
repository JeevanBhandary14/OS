#include <stdio.h>

struct Process {
    int id;
    int burst;
    int remainingBT;
    int completion;
    int turnaround;
    int waiting;
};

int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    struct Process proc[n];
    printf("Enter Burst time for %d processes:\n", n);
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        scanf("%d", &proc[i].burst);
        proc[i].remainingBT = proc[i].burst;
    }

    int time = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (proc[i].remainingBT > 0) {
                done = 0;
                if (proc[i].remainingBT > quantum) {
                    time += quantum;
                    proc[i].remainingBT -= quantum;
                } else {
                    time += proc[i].remainingBT;
                    proc[i].completion = time;
                    proc[i].turnaround = proc[i].completion;
                    proc[i].waiting = proc[i].turnaround - proc[i].burst;
                    proc[i].remainingBT = 0;
                }
            }
        }
        if (done == 1)
            break;
    }

    printf("\nProcess Details:\n");
    printf("Process\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burst,
               proc[i].completion, proc[i].turnaround, proc[i].waiting);
    }

    float totalwaiting = 0, totalturnaround = 0;
    for (int i = 0; i < n; i++) {
        totalwaiting += proc[i].waiting;
        totalturnaround += proc[i].turnaround;
    }

    printf("\nTotal Waiting Time: %.2f\t\tAvg Waiting Time: %.2f\n", totalwaiting, totalwaiting / n);
    printf("Total Turnaround Time: %.2f\tAvg Turnaround Time: %.2f\n", totalturnaround, totalturnaround / n);

    return 0;
}

