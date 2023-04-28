//Program - cp.c
//C program to simulate the working of consumer producer problem in operating system

#include<stdio.h>
#define Maxf 4

int front=-1,rear=-1,plate[Maxf];

void produce(int quan)
{
	
	if((front==rear+1)|| (front==0 && rear==Maxf-1))
	{
		printf("\nNot possible to produce");
		return;
	}
 	else if(front==-1)
		front=0;
	rear=(rear+1)%Maxf;
	plate[rear]=quan;
	printf("\n%d item is produced and ready to consume",quan);
}

void consume()
{
	int food;
	if(front==-1 && rear==-1)
		printf("\nPlate is empty");
	else 
	{
		food=plate[front];
			if(front==rear)
			{
				front=-1;
				rear=-1;
			}
			else
				front=(front+1)%Maxf;
		printf("\n%d item is consumed",food);
	}
}
 
void main()
{
	int quan,i,ch,temp=0;
	printf("Enter what operation to perform");
	while(1)
	{
		printf("\n1.Produce 2.Consume 3.Exit :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter how much quantity want to produce:");
					scanf("%d",&quan);
					produce(quan);
					break;
			case 2: consume();
					break;
			case 3: printf("\nExiting");
					return;	
			default: printf("\nEnter proper choice");
					 break;		
		}
	}
	
}
