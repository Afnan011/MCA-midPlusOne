// Program-bankers.c
// C program to simulate Bankers algorithm for the purpose of deadlock avoidance

#include <stdio.h>
int main()
{
    int n, m, i, j, k, alloc[20][20], max[20][20], avail[20], maxResInstance[20], MaxAlloc[i];
    printf("Enter number of Processes : ");
    scanf("%d", &n);
    printf("Enter number of Resource types : ");
    scanf("%d", &m);

    printf("\nEnter Allocation value for each resources:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Maximum value for each resources:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Maximum resources instance:");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &maxResInstance[i]);
    }

    int visited[n], sSeq[n], curPos = 0;
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    printf("\nAllocation \t Max \t\t Need \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf(" %d ", alloc[i][j]);
        }

        printf("\t");
        for (j = 0; j < m; j++)
        {
            printf(" %d ", max[i][j]);
        }

        printf("\t");
        for (j = 0; j < m; j++)
        {
            printf(" %d ", need[i][j]);
        }

        printf("\t");
        printf("\n");
    }

    // Finding initial Available avail[0]
    for (i = 0; i < m; i++)
    {
        int temp = 0;
        for (j = 0; j < n; j++)
        {
            temp += alloc[j][i];
        }

        MaxAlloc[i] = temp;
    }
    printf("\nAvail\n");
    for (i = 0; i < m; i++)
    {
        avail[i] = maxResInstance[i] - MaxAlloc[i];
        printf(" %d ", avail[i]);
    }
    printf("\n");
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {

                int state = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        state = 1;
                        break;
                    }
                }
                if (state == 0)
                {
                    sSeq[curPos++] = i;
                    for (int y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    visited[i] = 1;

                    for (int y = 0; y < m; y++)
                    {
                        printf(" %d ", avail[y]);
                    }
                    printf("\n");
                }
            }
        }
    }

    int state = 1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            state = 0;
            printf("The following system is not in safe state");
            break;
        }
    }
    if (state == 1)
    {
        printf("The following system is in safe state");
        printf("\nFollowing is the SAFE Sequence\n");
        for (i = 0; i < n; i++)
            printf(" P%d", sSeq[i]);
    }
    return (0);
}