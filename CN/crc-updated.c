#include<stdio.h>
void divide(int ,int ,int [40],int [40]);

void main()
{
    int dwlen,cwlen,glen,i,j,error;
    int dataword[40],codeword[40],gen[40];
    int rcodeword[40],rdataword[40];

    printf("\n \t\t===== TRANSMITTER SIDE =====\n");

    printf("\n Enter the data word length : ");
    scanf("%d",&dwlen);

    printf("\n Enter Data word : ");
    for(i=0;i<dwlen;i++)
        scanf("%d",&dataword[i]);

    printf("\n Enter generator length : ");
    scanf("%d",&glen);

    printf("\n Enter the generator : ");
    for(i=0;i<glen;i++)
        scanf("%d",&gen[i]);
    //codeword length 
    cwlen=dwlen+(dwlen-1);

    //append zeros 
    for(i=dwlen;i<cwlen-1;i++)
        dataword[i]=0;

    printf("\n Data word with zeros appended : ");
    for(i=0;i<cwlen-1;i++)
        printf("%d",dataword[i]);
    //copy data word to code word 
    for(i=0;i<cwlen;i++)
        codeword[i]=dataword[i];
    //divide
    divide(dwlen,glen,dataword,gen);

    printf("\n Reminder is : ");
    for(i=dwlen;i<cwlen-1;i++)
        printf("%d",dataword[i]);

    //subtract the remider to end of dataword
    for(i=dwlen;i<cwlen;i++)
        codeword[i]=dataword[i];

    printf("\n The  code word to be transmitted : ");
    for(i=0;i<cwlen-1;i++)
        printf("%d",codeword[i]);

    printf("\n\n \t\t===== RECEIVER SIDE ===== \n\n");
    
    printf("\n Enter the received codeword : ");
    for(i=0;i<cwlen-1;i++)
        scanf("%d",&rcodeword[i]);

    divide(dwlen,glen,rcodeword,gen);

    printf("\n Reminder is : ");
    for(i=dwlen;i<cwlen-1;i++)
        printf("%d",rcodeword[i]);

    error=0;
    for(i=dwlen;i<cwlen-1;i++)
    {
        if(rcodeword[i]==1)
            error=1;
    }
    if(error)
        printf("\n Received code word has an error \n");
    else
        printf("\n Received code word has no error \n");
}

void divide(int dwlen,int glen,int data[40],int gen[40])
{
    int i,j;
    for(i=0;i<dwlen;i++)
    {
        if(data[i]==0)
        {
            for(j=0;j<glen;j++)
            {
                data[j+i]=data[j+i]^0;
            }
        }
        else
        {
            for(j=0;j<glen;j++)
            {
                data[j+i]=data[j+i]^gen[j];
            }
        }
    }
}