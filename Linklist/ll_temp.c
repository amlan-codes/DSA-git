//createlinklist
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
struct student *deletenode(struct student *,int);
main()
{
    struct student *b;
    b=createlinklist();
    traverse(b);

    int n;
    printf("Enter position to delete - ");
    scanf("%d",&n);

    b=deletenode(b,n);
    traverse(b);
    

}
struct student *deletenode(struct student *p,int pos)
{
    struct student *q,*m,*temp=p;
    int i;
    if(pos==1)
    {
        q=p->link;
        free(p);
        return q;
    }
    else
    {
        for(i=1;i<pos;i++)
        {
            m=p;
            p=p->link;
        }
        m->link=p->link;
        free(p);
        return temp;
    }
}

struct student *createlinklist()
{
    struct student *p,*q,*firstnode;
    char x[5];
    p=(struct student *)malloc(sizeof(struct student));
    firstnode=p;
    printf("Enter roll - ");
    scanf("%d",&p->roll);
    printf("Enter name - ");
    scanf("%s",p->name);
    while(1)
    {
        printf("Do you want to continue ? yes OR no \n");
        scanf("%s",x);
        if(strcmp(x,"no")==0)
            break;
    
    q=(struct student *)malloc(sizeof(struct student));
    p->link=q;
    p=q;
    printf("Enter roll - ");
    scanf("%d",&p->roll);
    printf("Enter name - ");
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