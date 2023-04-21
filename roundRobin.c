#include <stdio.h>

void main()
{
    int n, i, qt, count, temp, seq;
    int bt[10], wt[10], tt[10], rem_bt[10];
    float awt, att;

    printf("Enter how many processes: ");
    scanf("%d", &n);

    printf("Enter burst time of %d processes: \n", n);
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter the time quantom: ");
    scanf("%d", &qt);

    // calculation part

    count = 0;
    seq = 0;
    while (count != n)
    {
        temp = qt;
        count = 0;
        for (i = 0; i < n; i++)
        {
            if (rem_bt[i] == 0)
            {
                count++;
                continue;
            }

            if (rem_bt[i] > qt)
            {
                rem_bt[i] -= qt;
            }
            else
            {
                if (rem_bt[i] >= 0)
                {
                    temp = rem_bt[i];
                    rem_bt[i] = 0;
                }
            }

            seq += temp;
            tt[i] = seq;
        }
    }

    for (i = 0; i < n; i++)
    {
        wt[i] = tt[i] - bt[i];

        awt += wt[i];
        att += tt[i];
    }

    awt = awt / n;
    att = att / n;
    

    // printing the results
    printf("Process# \tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf(" P%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tt[i]);
    }

    printf("Average Waiting Time = %0.2f\n", awt);
    printf("Average Turnaround Time = %0.2f\n", att);
}
