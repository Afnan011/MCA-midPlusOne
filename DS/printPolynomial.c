#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    float coef;
    int expo;
    struct Node *next;
}node;

node *insert(node *head, int coef, int expo)
{
    node *newNode = (node*) malloc (sizeof(node));
    node *ptr;

    newNode->coef = coef;
    newNode->expo = expo;
    newNode->next = NULL;

    if (head == NULL || head->expo < expo)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL && ptr->next->expo >= expo)
        {
             ptr = ptr->next;
        }

        newNode->next = ptr->next;
        ptr->next = newNode;
    }

    return head;
    
}

node *create(node *head)
{
    int n;
    
    float coef;
    int expo;

    printf("\nEnter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter coefficient for the term %d : ", i+1);
        scanf("%f", &coef);

        printf("Enter Exponent for the term %d : ", i+1);
        scanf("%d", &expo);

        head = insert(head, coef, expo);
    }

    return head;
    
}

void printPoly(node *head)
{
    if (head == NULL)
    {
        printf("\nNo polynomial");
        return;
    }

    node *ptr = head;
    while (ptr != NULL)
    {
        printf("(%0.1fx^%d)", ptr->coef, ptr->expo);
        ptr = ptr->next;

        if (ptr != NULL)
        {
            printf("+");
        }
        else
        {
            printf("\n");
        }
        
    }    
}

void main()
{
    node *poly1 = NULL;
    node *poly2 = NULL;

    printf("Enter polynomial 1: \n");
    poly1 = create(poly1);


    printf("\n\nEnter polynomial 2: \n");
    poly2 = create(poly2);

    printPoly(poly1);
    printf("\n");
    printPoly(poly2);

}
