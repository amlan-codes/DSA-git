//DOUBLY LINKLIST
#include "stdio.h"
#include "stdlib.h"
struct student 
{
    struct student *left;
    int roll;
    int name[20];
    struct student *right;
};
void createlinklist(struct student**,struct student**);
void traverse_ltor(struct student *);
void traverse_rtol(struct student *);
main()
{
    struct student *l,*r;
    createlinklist(&l,&r);
    traverse_ltor(l);
    traverse_rtol(r);

}
void createlinklist(struct student **ll,struct student **rr)
{
    struct student *p,*q,*temp=p;
    p=(struct student *)malloc(sizeof(struct student));
    p->left=0;
    printf("Enter roll - ");
    scanf("%d",&p->roll);
    printf("Enter name - ");
    scanf("%s",p->name);
    
    char x[5];

    while(1)
    {
        printf("Do you want to continue? yes OR no - ");
        scanf("%s",x);
        if(strcmp(x,"no")==0)
            break;

        q=(struct student *)malloc(sizeof(struct student));
        p->right=q;
        q->left=p;
        p=q;
    printf("Enter roll- ");
    scanf("%d",&p->roll);
    printf("Enter name- ");
    scanf("%s",p->name);
    }
    p->right=0;
    *ll=temp;
    *rr=p;
}
void traverse_ltor(struct student *p)
{
    while(p!=0)
    {
        printf("%d %s \n",p->roll,p->name);
        p=p->right;
    }
}
void traverse_rtol(struct student *p)
{
    while(p!=0)
    {
        printf("%d %s \n",p->roll,p->name);
        p=p->left;
    }
}