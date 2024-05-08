#include <stdio.h>

struct Process {
    char name[10]; 
    int arrival;   
    int burst;    
    int waiting; 
    int turnaround; 
};

int main() {
    int n;
    float avgWaiting = 0, avgTurnaround = 0;

    printf("Enter total number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];

    printf("Enter process name, arrival time, and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%s %d %d", processes[i].name, &processes[i].arrival, &processes[i].burst);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst > processes[j + 1].burst) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrival) {
            currentTime = processes[i].arrival;
        }
        processes[i].waiting = currentTime - processes[i].arrival;
        processes[i].turnaround = processes[i].waiting + processes[i].burst;
        currentTime += processes[i].burst;
    }

    for (int i = 0; i < n; i++) {
        avgWaiting += processes[i].waiting;
        avgTurnaround += processes[i].turnaround;
    }
    avgWaiting /= n;
    avgTurnaround /= n;

    printf("\nProcess Details:\n");
    printf("Name\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].name, processes[i].arrival, processes[i].burst,
               processes[i].waiting, processes[i].turnaround);
    }

    printf("\nAverage Waiting Time: %.2f\n", avgWaiting);
    printf("Average Turnaround Time: %.2f\n", avgTurnaround);

    return 0;
}

