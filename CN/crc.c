#include <stdio.h>
void divide(int, int, int[40], int[40]);

void main()
{
    int dwLen, cwLen, gLen, i, j, error;
    int dataWord[40], codeWord[40], gen[40];
    int rCodeWord[40];

    printf("\n \t\t===== TRANSMITTER SIDE =====\n");

    printf("\n Enter the data word length : ");
    scanf("%d", &dwLen);

    printf("\n Enter Data word : ");
    for (i = 0; i < dwLen; i++)
        scanf("%d", &dataWord[i]);

    printf("\n Enter generator length : ");
    scanf("%d", &gLen);

    printf("\n Enter the generator : ");
    for (i = 0; i < gLen; i++)
        scanf("%d", &gen[i]);
    // codeword length
    cwLen = dwLen + (gLen - 1);

    // append zeros
    for (i = dwLen; i < cwLen; i++)
        dataWord[i] = 0;

    printf("\n Data word with zeros appended : ");
    for (i = 0; i < cwLen; i++)
        printf("%d", dataWord[i]);

    // copy data word to code word
    for (i = 0; i < cwLen; i++)
        codeWord[i] = dataWord[i];
        
    // divide
    divide(dwLen, gLen, dataWord, gen);

    printf("\n Reminder is : ");
    for (i = dwLen; i < cwLen; i++)
        printf("%d", dataWord[i]);

    // append the remainder to end of dataword
    for (i = dwLen; i < cwLen; i++)
        codeWord[i] = dataWord[i];

    printf("\n The  code word to be transmitted : ");
    for (i = 0; i < cwLen; i++)
        printf(" %d ", codeWord[i]);

    printf("\n\n \t\t===== RECEIVER SIDE ===== \n\n");

    printf("\n Enter the received codeword : ");
    for (i = 0; i < cwLen; i++)
        scanf("%d", &rCodeWord[i]);

    divide(dwLen, gLen, rCodeWord, gen);

    printf("\n Reminder is : ");
    for (i = dwLen; i < cwLen; i++)
        printf(" %d ", rCodeWord[i]);

    error = 0;
    for (i = dwLen; i < cwLen; i++)
    {
        if (rCodeWord[i] == 1)
            error = 1;
    }
    if (error)
        printf("\n Received code word has an error \n");
    else
        printf("\n Received code word has no error \n");
}

void divide(int dwlen, int glen, int data[40], int gen[40])
{
    int i, j;
    for (i = 0; i < dwlen; i++)
    {
        if (data[i] == 0)
        {
            for (j = 0; j < glen; j++)
            {
                data[j + i] = data[j + i] ^ 0;
            }
        }
        else
        {
            for (j = 0; j < glen; j++)
            {
                data[j + i] = data[j + i] ^ gen[j];
            }
        }
    }
}