#include <stdio.h>

#define MAX 10

typedef struct {
    int id;
    int Ci;
    int Ti;
    int remaining;
    int next_release;
} Task;

// GCD
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n;
    Task t[MAX];
    int hyperperiod = 1;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    // INPUT
    for (int i = 0; i < n; i++) {
        printf("\nTask %d\n", i + 1);
        t[i].id = i + 1;

        printf("Execution Time (Ci): ");
        scanf("%d", &t[i].Ci);

        printf("Period (Ti): ");
        scanf("%d", &t[i].Ti);

        if (t[i].Ci > t[i].Ti) {
            printf("Warning: Ci > Ti (task may miss deadlines)\n");
        }

        t[i].remaining = 0;
        t[i].next_release = 0;

        hyperperiod = lcm(hyperperiod, t[i].Ti);
    }

    printf("\nHyperperiod (LCM) = %d\n\n", hyperperiod);

    // RMS Scheduling (priority = smaller period)
    for (int time = 0; time < hyperperiod; time++) {

        // Release jobs
        for (int i = 0; i < n; i++) {
            if (time == t[i].next_release) {
                t[i].remaining += t[i].Ci;
                t[i].next_release += t[i].Ti;
            }
        }

        // Pick highest priority (smallest Ti first)
        int selected = -1;

        for (int i = 0; i < n; i++) {
            if (t[i].remaining > 0) {
                selected = i;
                break; // already sorted assumption
            }
        }

        if (selected == -1) {
            printf("Time %d: Idle\n", time);
        } else {
            printf("Time %d: Task %d running\n", time, t[selected].id);
            t[selected].remaining--;
        }
    }

    return 0;
}
