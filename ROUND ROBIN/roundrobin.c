#include <stdio.h>

int main() {
    int n, tq;
    int i, time = 0, remain;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

    printf("\nEnter Arrival Time and Burst Time:\n");

    for(i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i+1);
        scanf("%d", &at[i]);

        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;

    while(remain > 0) {

        int executed = 0;

        for(i = 0; i < n; i++) {

            if(at[i] <= time && rt[i] > 0) {

                executed = 1;

                if(rt[i] <= tq) {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    remain--;
                }
                else {
                    rt[i] -= tq;
                    time += tq;
                }
            }
        }

        if(executed == 0)
            time++;
    }
    float twt=0,ttat=0;


    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        twt+=wt[i];
        ttat+=tat[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\ntwt=%f",twt/n);
    printf("\nttat=%f",ttat/n);


    return 0;
}
