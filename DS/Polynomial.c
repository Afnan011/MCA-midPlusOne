#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coef;
    int expo;
    struct Node *next;
} node;

node *insert(node *head, int coef, int expo)
{
    node *newNode = (node *)malloc(sizeof(node));
    node *ptr;

    newNode->coef = coef;
    newNode->expo = expo;
    newNode->next = NULL;

    if (head == NULL || expo > head->expo)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL && expo <= ptr->next->expo)
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
    int coef;
    int expo;

    printf("\nEnter how many terms : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the coefficient for the term %d: ", i + 1);
        scanf("%d", &coef);

        printf("Enter the exponent for the term %d: ", i + 1);
        scanf("%d", &expo);

        head = insert(head, coef, expo);
    }

    return head;
}

void printPoly(node *head)
{
    if (head == NULL)
    {
        printf("\nNO polynomial!");
        return;
    }

    node *ptr = head;
    while (ptr != NULL)
    {
        printf("(%dX^%d)", ptr->coef, ptr->expo);
        ptr = ptr->next;

        if (ptr != NULL)
        {
            printf(" + ");
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
            int coef = ptr1->coef + ptr2->coef;
            res = insert(res, coef, ptr1->expo);

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        else if (ptr1->expo > ptr2->expo)
        {
            res = insert(res, ptr1->coef, ptr1->expo);
            ptr1 = ptr1->next;
        }

        else if (ptr1->expo < ptr2->expo)
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

    printf("\n\nResult Polynomial is : \n");
    printPoly(res);

}

void main()
{
    node *poly1 = NULL;
    node *poly2 = NULL;

    printf("\nEnter first polynomial");
    poly1 = create(poly1);

    printf("\nEnter second polynomial");
    poly2 = create(poly2);

    printf("\n\nFirst Polynomial is : \n");
    printPoly(poly1);

    printf("\n\nSecond Polynomial is : \n");
    printPoly(poly2);

    polyAdd(poly1, poly2);
}
