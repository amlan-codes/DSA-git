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
struct student *insertnode(struct student *,int);
main()
{
    struct student *b;
    b=createlinklist();
    traverse(b);

    int n;
    printf("Enter position");
    scanf("%d",&n);

    b=insertnode(b,n);
    traverse(b);
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
void traverse(struct student *p)
{
    while(p!=0)
    {
        printf("%d %s \n",p->roll,p->name);
        p=p->link;
    }
}
struct student *insertnode(struct student *p,int pos)
{
    int i;
    struct student *m,*q,*temp=p;
    if(pos==1)
    {
        q=(struct student *)malloc(sizeof(struct student));
        q->link=p;
        printf("Enter roll ");
        scanf("%d",&q->roll);
        printf("Enter name - ");
        scanf("%s",q->name);
        return q;
    }
    else
    {
        for(i=1;i<pos;i++)
        {
            m=p;
            p=p->link;
        }
        q=(struct student *)malloc(sizeof(struct student));
        m->link=q;
        q->link=p;
        printf("Enter roll ");
        scanf("%d",&q->roll);
        printf("Enter name - ");
        scanf("%s",q->name);
        return temp;

    }
}

