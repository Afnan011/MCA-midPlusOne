#include<stdio.h>

int cost[20][20], d[20], v[20], p[20], n;

void dijik(int s)
{
	int i, j, u, min, count = 1;
	
	for (i = 0; i < n; i++)
	{
		v[i] = 0;
		p[i] = s;
		d[i] = cost[s][i];
	}
	v[s] = 1;


	while (count < n)
	{
		u = -1;
		min = 99;
		
		for (i = 0; i < n; i++)
		{
			if (v[i] == 0 && d[i] < min)
			{
				min = d[i];
				u = i;
			}
		}
		
		
		v[u] = 1;
		
		for (i = 0; i < n; i++)
		{
			if (v[i] == 0 && d[u]+cost[u][i] < d[i])
			{
				d[i] = d[u]+cost[u][i];
				p[i] = u;
			}
		}
					
		count = count + 1;
	}
		
}

void printMatrix()
{
	
	printf("\n\nD: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", d[i]);
	}
	
	printf("\nP: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", p[i]);
	}
	printf("\n");
}


void printPath(int src)
{

	for (int dest = 0; dest < n; dest++)
	{	
	
		int i = dest;
		while (i != src)
		{
			printf("%d<--", i); 
			i = p[i];
		}
		
		printf("%d = %d \n", i,  d[dest] ); 
	}	
}



void main()
{
	int i, j, s;
	
	printf("Enter number of vertices: ");
	scanf("%d", &n);
	
	printf("Enter adjacency matrix: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &cost[i][j]);
		}
	}
	
	printf("\nEnter Source: "); 
	scanf("%d", &s);
	

	printf("\nCost matrix is: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d\t", cost[i][j]);
		}
		printf("\n");
	}
	
	dijik(s);
	printMatrix();
	
	printf("paths : \n ");
	printPath(s);
	
}



