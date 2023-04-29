#include <stdio.h>
#include <stdbool.h>

void main()
{
    int i, j, m, n, temp, count;
    int seq[10], visited[10], MaxAlloc[10];
    int need[10][10], avail[10];
    // int alloc[10][10], max[10][10], need[10][10], avail[10][10];
    bool state = false;

    n = 5;
    m = 3;

    // printf("Enter number of Processes : ");
    // scanf("%d", &n);
    // printf("Enter number of Resource types : ");
    // scanf("%d", &m);

    int alloc[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}};

    int max[5][3] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3},
    };

    int maxResInstance[10] = {10, 5, 7};

    // avail[0][] = {3, };

    // printf("Enter allocation for each processes: \n");
    //
    //
    /* Input data into  alloc and max and need matrix */
    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j < m; j++)
    //     {
    //         //printf("Enter data in P[%d] and R[%d]: ", i, j);
    //         scanf("%d", &alloc[i][j]);
    //     }
    // }

    // printf("Enter Max value for each processes: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            // printf("Enter data in P[%d] and R[%d]: ", i, j);
            //  scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Finding Avail
    // 1. finding Maximum allocated value for each resource instances
    for (i = 0; i < m; i++)
    {
        temp = 0;
        for (j = 0; j < n; j++)
        {
            temp += alloc[j][i];
        }

        MaxAlloc[i] = temp;
    }

    // 2. Finding initial Available avail[0]
    for (i = 0; i < m; i++)
    {
        avail[i] = maxResInstance[i] - MaxAlloc[i];

        printf(" %d ", avail[i]);
    }

    // 3. Finding Remaining 'avail' values

    // 3.1 Initialization
    count = 0;
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    // while (count != n)
    // {
        count = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {

                if (visited[i] == 1)
                {
                    count++;
                    continue;
                }

                for (int k = 0; k < m; k++)
                {
                    if (visited[i] == 0 && need[i][k] <= avail[k])
                    {
                        state = true;
                    }
                }

                if (state)
                {
                    avail[i] += alloc[i][j];
                    visited[i] = 1;
                }
            }
        }
    // }

    /* Display the matrix */

    printf("\nAllocation \t Max \t\t Need \t\t Avail\n");
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
}
