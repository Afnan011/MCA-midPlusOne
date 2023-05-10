// Banker's Algorithm
#include <stdio.h>
void main()
{

    int n, m, i, j;
    int state = 0, curPos = 0;          //state is a boolean variable


    printf("Enter number of Processes : ");
    scanf("%d", &n);
    printf("Enter number of Resource types : ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m], dispAvail[n][m];
    int visited[n], safeSeq[n], avail[n];

    // Input data into  alloc and max and need matrix
    printf("Enter allocation for each processes: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            // printf("Enter data in P[%d] and R[%d]: ", i, j);
            scanf("%d", &alloc[i][j]);
        }
    }

    // Reading Max[][] and calculating Need[][]
    printf("Enter Maximum resource required for each processes: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Reading Avail[]
    printf("\nEnter avail: ");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }

    // Initialization
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }


    /* Display the matrix :-> {Alloc, Max, need} */

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
        
        printf("\n");
    }

    //Print Avail
    printf("\nAvail\n");
    for(i=0; i<m; i++)
        printf(" %d ", avail[i]);


    printf("\n");
    // calculation part
    for (int count = 0; count < n; count++)
    {
        for (i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                state = 0;              // initially false

                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        state = 1;              // true only when any need[i,j] > avail[k]
                        break;
                    }
                }

                if (state == 0)                 // true only if process i can complete its task
                {
                    safeSeq[curPos++] = i;
                    for (j = 0; j < m; j++)
                    {
                        avail[j] += alloc[i][j];
                        printf(" %d ", avail[j]);
                    } 
                    printf("\n");

                    visited[i] = 1;
                }
            }
        }
    }

    //Checking for the safe state
    state = 1;
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            state = 0;
            printf("\nThe system is not safe");
            break;
        }
    }

    if (state == 1)
    {
        printf("\nhe system is in safe state. \nThe safe Sequence is: \n");
        for (int i = 0; i < n - 1; i++)
            printf(" P%d ->", safeSeq[i]);
        printf(" P%d\n", safeSeq[n - 1]);
    }
}
