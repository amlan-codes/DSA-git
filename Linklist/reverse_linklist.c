#include "stdio.h"
#include "stdlib.h"
struct student 
{
    int roll;
    char name[20];
    struct student *link;
};
struct student *createlinklist();
void traverse(struct student *);
struct student *reverse(struct student *);
main()
{
    struct student *b;
    b=createlinklist();
    traverse(b);

    b=reverse(b);
    traverse(b);
}
struct student *reverse(struct student *p)
{
    struct student *next,*pre=0;
    while(p!=0)
    {
        next=p->link;
        p->link=pre;
        pre=p;
        p=next;
    }
    return pre;
}
struct student *createlinklist()
{
    struct student *p,*q,*firstnode;
    p=(struct student *)malloc(sizeof(struct student));
    firstnode=p;
    printf("Enter roll- ");
    scanf("%d",&p->roll);
    printf("Enter name- ");
    scanf("%s",p->name);
    char x[5];
    while(1)
    {
        printf("Do you want to continue? yes OR no - ");
        scanf("%s",x);
        if(strcmp(x,"no")==0)
            break;
    
    q=(struct student *)malloc(sizeof(struct student));
    p->link=q;
    p=q;
    printf("Enter roll- ");
    scanf("%d",&p->roll);
    printf("Enter name- ");
    scanf("%s",p->name);

    }
    p->link=0;
    return firstnode;


}
traverse(struct student *p)
{
    while(p!=0)
    {
        printf("%d %s \n",p->roll,p->name);
        p=p->link;
    }
}


