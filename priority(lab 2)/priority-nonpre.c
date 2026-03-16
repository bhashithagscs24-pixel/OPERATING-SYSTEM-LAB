#include <stdio.h>

int main() {
    int n, bt[20], at[20], wt[20], tat[20], ct[20], pr[20], p[20];
    int i, j, temp, time = 0, completed = 0;
    float twt = 0, ttat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p[i] = i+1;
        printf("Enter Arrival Time for Process %d: ", i+1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for Process %d: ", i+1);
        scanf("%d", &bt[i]);
        printf("Enter Priority for Process %d: ", i+1);
        scanf("%d", &pr[i]);
    }

    int done[20] = {0}; // track completed processes

    while(completed < n) {
        int idx = -1;
        int minPr = 9999;

        // find process with highest priority among those that have arrived
        for(i = 0; i < n; i++) {
            if(at[i] <= time && !done[i]) {
                if(pr[i] < minPr) {
                    minPr = pr[i];
                    idx = i;
                }
            }
        }

        if(idx == -1) {
            time++; // no process has arrived yet, idle CPU
            continue;
        }

        wt[idx] = time - at[idx];
        time += bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        done[idx] = 1;
        completed++;
    }

    printf("\nPROCESS\tAT\tBT\tPR\tWT\tTAT\tCT");
    for(i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d", p[i], at[i], bt[i], pr[i], wt[i], tat[i], ct[i]);
        twt += wt[i];
        ttat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", twt/n);
    printf("\nAverage Turnaround Time = %.2f", ttat/n);

    return 0;
}
