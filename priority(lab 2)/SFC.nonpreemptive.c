
#include <stdio.h>

int main() {
    int n, i, j, pos, temp,w=0,t=0;
    int bt[20], at[20], wt[20], tat[20], ct[20], p[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        p[i]=i+1;
        printf("Arrival time of P%d: ",p[i]);
        scanf("%d",&at[i]);
        printf("Burst time of P%d: ",p[i]);
        scanf("%d",&bt[i]);
    }

    for(i=0;i<n;i++){
        pos=i;
        for(j=i+1;j<n;j++){
            if(bt[j]<bt[pos])
                pos=j;
        }

        temp=bt[i]; bt[i]=bt[pos]; bt[pos]=temp;
        temp=at[i]; at[i]=at[pos]; at[pos]=temp;
        temp=p[i]; p[i]=p[pos]; p[pos]=temp;
    }

    ct[0]=at[0]+bt[0];

    for(i=1;i<n;i++)
        ct[i]=ct[i-1]+bt[i];

    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
        w+=wt[i];
        t+=tat[i];


    printf("\nAverage Waiting Time = %f",(float)wt/n);
    printf("\nAverage Turnaround Time = %f",(float)tat/n);
    return 0;
}
