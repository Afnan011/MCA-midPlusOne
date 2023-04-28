// Banker's Algorithm
#include <stdio.h>
int main()
{
    // P0, P1, P2, P3, P4 are the Process names here

    int n, m, i, j, k;
    printf("Enter number of Processes : ");
    scanf("%d", &n);
    printf("Enter number of Resource types : ");
    scanf("%d", &m);
    int alloc[5][3] = {{0, 1, 0},  // P0 // Allocation Matrix
                       {2, 0, 0},  // P1
                       {3, 0, 2},  // P2
                       {2, 1, 1},  // P3
                       {0, 0, 2}}; // P4

    int max[5][3] = {{7, 5, 3},  // P0 // MAX Matrix
                     {3, 2, 2},  // P1
                     {9, 0, 2},  // P2
                     {2, 2, 2},  // P3
                     {4, 3, 3}}; // P4

    int avail[3] = {3, 3, 2}; // Available Resources

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
            printf("The following system is not safe");
            break;
        }
    }
    if (state == 1)
    {
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < n - 1; i++)
            printf(" P%d ->", sSeq[i]);
        printf(" P%d", sSeq[n - 1]);
    }
    return (0);
}
