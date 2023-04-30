//Addition of polynomials using Linked List
#include<stdio.h>
#include<stdlib.h>
typedef struct polyNode *polyPointer;
struct polyNode
{
    float coef;
    int exp;
    polyPointer link;
};
polyPointer padd(polyPointer a,polyPointer b){
    polyPointer c,startA,startB;
    startA=a,startB=b;
    int coeff;
    a=a->link,b=b->link;
    while(a!=startA&&b!=startB)
        switch(COMPARE(a->exp,b->exp)){
            case -1:attach(c,b->coef,b->exp);
            b=b->link;
            break;
            case 0:coeff=a->coef+b->coef;
            c=attach(c,coeff,a->exp);
            a=a->link;
            b=b->link;
            break;
            case 1: c=attach(c,a->coef,a->exp);
            a=a->link;
        }
    while(a!=startA){
        c=attach(c,a->coef,a->exp);
        a=a->link;
    }
    while(b!=startB){
        c=attach(c,b->coef,b->exp);
        b=b->link;
    }
    return c;
}
polyPointer attach(polyPointer head,float coef, int expn){
    polyPointer node,temp;
    node=getnode();
    node->coef=coef;
    node->exp=expn;
    if(!head()){
        head=getnode();
        head->link=head;
    }
    temp=head;
    while(temp->link!=head)
        temp=temp->link;
    temp->link=node;
    node->link=head;
    return head;
}
