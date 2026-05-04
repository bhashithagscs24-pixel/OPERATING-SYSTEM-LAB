#include <stdio.h>

#define MAX 10
#define TIME_QUANTUM 10   // Total time distributed in one cycle

typedef struct {
    int id;
    int arrival;
    int burst;
    int remaining;
    int weight;
    int completed;
} Process;

int main() {
    int n;
    Process p[MAX];
    int total_weight = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input processes
    for (int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        p[i].id = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);

        printf("Burst Time: ");
        scanf("%d", &p[i].burst);

        printf("Weight: ");
        scanf("%d", &p[i].weight);

        p[i].remaining = p[i].burst;
        p[i].completed = 0;

        total_weight += p[i].weight;
    }

    int t = 0;
    int completed_count = 0;

    printf("\nProportional Share Scheduling Execution:\n");

    while (completed_count < n) {
        int executed_in_cycle = 0;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= t && p[i].completed == 0) {

                // Step 8: Calculate proportional time slice
                int time_slice = (p[i].weight * TIME_QUANTUM) / total_weight;

                // Ensure at least 1 unit gets executed
                if (time_slice <= 0)
                    time_slice = 1;

                printf("Time %d: Process %d runs for %d units\n",
                       t, p[i].id, time_slice);

                // Execute process
                if (p[i].remaining <= time_slice) {
                    t += p[i].remaining;
                    p[i].remaining = 0;
                } else {
                    p[i].remaining -= time_slice;
                    t += time_slice;
                }

                // Check completion
                if (p[i].remaining == 0 && p[i].completed == 0) {
                    p[i].completed = 1;
                    completed_count++;
                    total_weight -= p[i].weight;

                    printf("Process %d completed at time %d\n",
                           p[i].id, t);
                }

                executed_in_cycle = 1;
            }
        }

        // If no process was ready, advance time
        if (!executed_in_cycle) {
            printf("Time %d: Idle\n", t);
            t++;
        }
    }

    return 0;
}
