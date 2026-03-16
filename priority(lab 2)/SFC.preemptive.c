#include <stdio.h>
#include <limits.h>

int main() {
    int n, at[20], bt[20], rt[20];
    int ct[20], wt[20], tat[20];
    int time = 0, remain, smallest;
    int i;
    float twt = 0, ttat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time for Process %d: ", i+1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for Process %d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    remain = n;

    while(remain != 0) {
        smallest = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(smallest == -1 || rt[i] < rt[smallest])
                    smallest = i;
            }
        }

        if(smallest == -1) {
            time++;
            continue;
        }

        rt[smallest]--;
        time++;

        if(rt[smallest] == 0) {
            ct[smallest] = time;
            tat[smallest] = ct[smallest] - at[smallest];
            wt[smallest] = tat[smallest] - bt[smallest];
            remain--;
        }
    }

    for(i = 0; i < n; i++) {
        twt += wt[i];
        ttat += tat[i];
    }

    printf("\nPROCESS\tAT\tBT\tCT\tWT\tTAT");
    for(i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
               i+1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", twt/n);
    printf("\nAverage Turnaround Time = %.2f", ttat/n);

    return 0;
}
