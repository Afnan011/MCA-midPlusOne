#include<stdio.h>

int cost[20][20], n, v1, v2;


void findMin()
{
	int min = 99;
	int i, j;
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (cost[i][j] > 0 && cost[i][j] < min)
			{
				min = cost[i][j];
				v1 = i;
				v2 = j;
			}
		}
	}	

}


void doUnion(int root[])
{
	int i, temp;
	temp = root[v2];
	
	for (i = 0;  i < n ;  i++)
	{
		if (temp == root[i])
		{
			root[i] = root[v1];
		}
	}
	
}


void kruskals()
{
	int i, edgWt = 0, min;
	int root[n];
	
	for(i=0; i<n; i++)
		root[i] = i;
	
	i=0;
	while(i < n-1)
	{
		findMin();
		min = cost[v1][v2];
		cost[v1][v2] = cost[v2][v1] = 0;
			
		if (root[v1] != root[v2])
		{
			printf(" %d-%d \n", v1, v2);
			doUnion(root);
			
			edgWt += min;
			i++;
		}
	}
	
	printf("Total Minimum Cost = %d\n", edgWt);
	

}


void main()
{
	int i, j;
	
	printf("Enter number of vertices: ");
	scanf("%d", &n);
	
	printf("Enter cost adjacency matrix: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &cost[i][j]);
		}
	}
	

	printf("\nCost matrix is: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d\t", cost[i][j]);
		}
		printf("\n");
	}
	
	
	printf("\nMinimum path is: \n");
	kruskals();
	
}



