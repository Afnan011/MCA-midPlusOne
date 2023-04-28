//Program dinphilo.c
//C program to simulate the working of dining philosophers problem for 5 philosophers and with maximum 2 eaters

#include<stdio.h>
#define NP 5

void forks(int eatp)
{
	int frk0,frk1;
	if(eatp==0)
	{
		frk0=eatp;
		frk1=NP-1;
	}
	else
	{
		frk0=eatp;
		frk1=eatp-1;
	}
	printf("\n%d can use Fork%d and Fork%d",eatp,frk0,frk1);
}

void eat1(int eatp)
{
		printf("\nPhilosopher %d is allowed to eat",eatp);
		forks(eatp);
}

void eat2()
{
	int eatp1,eatp2;
	printf("\nEnter which 2 different philosphers wants eat(0-4):");
	printf("\nPhilosopher:");
	scanf("%d",&eatp1);
	printf("\nPhilosopher:");
	scanf("%d",&eatp2);
	if(eatp2==eatp1+1 || eatp2==eatp1-1)
	{
		printf("\nAt a time these two philosophers cant eat as they are neighbors");
		eat1(eatp1);
		printf("\n%d is waiting",eatp2);
		printf("\n%d is completed eating",eatp1);
		eat1(eatp2);
	}
	else if(eatp2==0 && eatp1==NP-1 || eatp1==0 && eatp2==NP-1)
	{
		printf("\nAt a time these two philosophers cant eat as they are neighbors");
		eat1(eatp1);
		printf("\n%d is waiting",eatp2);
		printf("\n%d is completed eating",eatp1); 
		eat1(eatp2);
	}
	else 
	{
		eat1(eatp1);
		eat1(eatp2);
	}
}
void main()
{
	int WEat,eatp;
	/*for(i=0;i<NP;i++)
		philo[i]=i;*/
	printf("Enter how many philosphers wants to eat:");
	scanf("%d",&WEat);
	if(WEat==1)
	{
		printf("\nEnter which philospher wants eat(0-4 values):");
		scanf("%d",&eatp);
		eat1(eatp);
	}
	else if(WEat==2)
	{
		eat2();
	}
	else 
	{
		printf("\nDeadlock state");
	}
	
}
