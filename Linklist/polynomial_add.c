#include "stdio.h"
#include "stdlib.h"
struct math
{
    int cof;
    int exp;
    struct student *link;
};
struct math * createlinklist();
struct math * addpoly(struct math *,struct math *);
void traverse(struct math *);
main()
{
    struct math *a,*b,*c;
    
    a=createlinklist();
    traverse(a);

    b=createlinklist();
    traverse(b);

    c=addpoly(a,b);
    traverse(c);
}
struct math * createlinklist()
{
    struct math *p,*q,*temp;
    p=(struct math *)malloc(sizeof(struct math));
    temp=p;

    printf("Enter cooficient - ");
    scanf("%d",&p->cof);
    printf("Enter Exponent - ");
    scanf("%d",&p->exp);

    int x;

    while(1)
    {
        printf("Do you want to add elements in polynomial ?\nIf yes press 1 or press 2 - ");
        scanf("%d",&x);
        if(x==2)
            break;
    q=(struct math *)malloc(sizeof(struct math));
    p->link=q;
    p=q;
    printf("Enter cooficient - ");
    scanf("%d",&p->cof);
    printf("Enter Exponent - ");
    scanf("%d",&p->exp);
    }
    p->link=0;
    return temp;
}
void traverse(struct math *p)
{
    while(p!=0)
    {
        printf("%dx^%d + ",p->cof,p->exp);
        
        p=p->link;
    }
    printf("\n");
}
struct math *addpoly(struct math *p,struct math *q)
{
    struct math *a=0,*b,*temp;
    while(p!=0 && q!=0)
    {
        if(p->exp > q->exp)
        {
            if(a==0)
            {
                a=(struct math *)malloc(sizeof(struct math));
                a->cof=p->cof;
                a->exp=p->exp;
                temp=a;
            }
            else
            {
                b=(struct math *)malloc(sizeof(struct math));
                a->link=b;
                a=b;
                a->cof=p->cof;
                a->exp=p->exp;
            }
            p=p->link;

        }
        else
        if(p->exp < q->exp)
        {
            if(a==0)
            {
                a=(struct math *)malloc(sizeof(struct math));
                a->cof=q->cof;
                a->exp=q->exp;
                temp=a;
            }
            else
            {
                b=(struct math *)malloc(sizeof(struct math));
                a->link=b;
                a=b;
                a->cof=q->cof;
                a->exp=q->exp;
            }
            q=q->link;
        }
        else
        {
            if(a==0)
            {
                a=(struct math *)malloc(sizeof(struct math));
                a->cof=p->cof+q->cof;
                a->exp=p->exp;
                temp=a;
            }
            else
            {
                b=(struct math *)malloc(sizeof(struct math));
                a->link=b;
                a=b;
                a->cof=p->cof+q->cof;
                a->exp=p->exp;
            }
            p=p->link;
            q=q->link;
        }
    }
    //rest part of p
    while(p!=0)
    {
        b=(struct math *)malloc(sizeof(struct math));
        a->link=b;
        a=b;
        a->cof=p->cof;
        a->exp=p->exp;
        p=p->link;

    }
    //rest part of q
    while(q!=0)
    {
        b=(struct math *)malloc(sizeof(struct math));
        a->link=b;
        a=b;
        a->cof=q->cof;
        a->exp=q->exp;
        q=q->link;
    }
    a->link=0;
    return temp;
}   
