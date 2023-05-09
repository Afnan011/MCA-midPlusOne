#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coef;
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
        printf("(%d^%d)", ptr->coef, ptr->expo);
        ptr = ptr->next;

        if (ptr != NULL)
        {
            printf("+");
        }
        
    }    
}

void polyAdd(node *poly1, node *poly2)
{
    node *ptr1 = poly1;
    node *ptr2 = poly2;

    node *res = NULL;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            float coef = ptr1->coef + ptr2->coef;
            res = insert(res, coef, ptr1->expo);

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        else if(ptr1->expo > ptr2->expo)
        {
            res = insert(res, ptr1->coef, ptr1->expo);
            ptr1 = ptr1->next;
        }

        else if(ptr1->expo < ptr2->expo)
        {
            res = insert(res, ptr2->coef, ptr2->expo);
            ptr2 = ptr2->next;
        }  
    }

    while (ptr1 != NULL)
    {
        res = insert(res, ptr1->coef, ptr1->expo);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL)
    {
        res = insert(res, ptr2->coef, ptr2->expo);
        ptr2 = ptr2->next;
    }
    
    printf("\n\nAdded Polynomial is : \n");
    printPoly(res);
    
}

void main()
{
    node *poly1 = NULL;
    node *poly2 = NULL;

    printf("Enter the first polynomial: \n");
    poly1 = create(poly1);                      //poly1 --> head pointer for exp1


    printf("\n\nEnter the second polynomial: \n");
    poly2 = create(poly2);                      //poly2 --> head pointer for exp2

    printPoly(poly1);
    printf("\n");
    printPoly(poly2);

    polyAdd(poly1, poly2);

}
