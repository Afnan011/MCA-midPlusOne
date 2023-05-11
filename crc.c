#include<stdio.h>

void divide(int,int,int [20],int [20]);

void main()
{
    int dwlen,cwlen,glen,i,j,error;
    int dataword[20],codeword[40],gen[20];
    int rcodeword[40],rdataword[20];

    printf("\n Transmitter side\n\n");
    printf("Enter the length of dataword:");
    scanf("%d",&dwlen);
    printf("Enter the dataword:");
    for(i=0;i<dwlen;i++)
    {
        scanf("%d",&dataword[i]);
    }
    printf("Enter the length of the generator:");
    scanf("%d",&glen);
    printf("Enter the generator:");
    for ( j = 0; j < glen; j++)
    {
        scanf("%d",&gen[j]);
    }
    
    cwlen=dwlen+(glen-1);

    //append zeros
    for ( i = dwlen; i < cwlen; i++)
    {
        dataword[i]=0;
    }
    
    printf("\n\n Dataword with zeros appended:");

    for ( i = 0; i < cwlen; i++)
    {
        printf("%d",dataword[i]);
    }
    
    //copy the dataword as it is to codeword
    for ( i = 0; i < cwlen; i++)
    {   
        codeword[i]=dataword[i];
    }

    //divide
    divide(dwlen,glen,dataword,gen);

    printf("\n\nThe remainder is:");
    for ( i = dwlen; i < cwlen; i++)
    {
        printf("%d",dataword[i]);
    }
    
    //subtract the remainder to the end of dataword
    for(i=dwlen;i<cwlen;i++)
        codeword[i]=dataword[i];
    printf("\n\nThe codeword to the transmitted:");
    for(i=0;i<cwlen;i++)
        printf("%d",codeword[i]);
    
    printf("\n\nReceiver side\n\n");

    printf("Enter the received codeword:");
    for(i=0;i<cwlen;i++)   
        scanf("%d",&rcodeword[i]);
    
    //divide
    divide(dwlen,glen,rcodeword,gen);

    printf("\n\nThe remainder is:");
    for(i=dwlen;i<cwlen;i++)   
        printf("%d",rcodeword[i]);

    error=0;
    for ( i = dwlen; i < cwlen; i++)
    {
        if(rcodeword[i]==1)
            error=1;
    }
    if (error==1)
        printf("\n\nThe received codeword has error\n\n");
    else
        printf("\n\nThe received codeword has no error\n\n");
    
}

void divide(int dwlen,int glen,int data[20],int gen[20])
{
    int i,j;
    for ( i = 0; i < dwlen; i++)
    {
        if (data[i]==0)
        {
            for ( j = 0; j < glen; j++)
            {
                data[j+i]=data[j+i]^0;
            }
        }
        else
        {
            for ( j = 0; j < glen; j++)
            {
                data[j+i]=data[j+i]^gen[j];
            }
        }
        
    }
    
}