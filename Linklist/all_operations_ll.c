//Operatins present- Insert,Delete
#include "stdio.h"
#include "stdlib.h"
struct players 
{
    int jnum;
    char name[20];
    struct players *next;
};
struct players *createlinklist();
void traverse(struct players *);
struct players *insertnode(struct players *,int);
struct players *deletenode(struct players *,int);
main()
{
    struct player *b;
    b=createlinklist();
    traverse(b);

printf("Choose option : -\n1.Insert node \n2.Delete node \n3.Reverse the list\n");
int option;
scanf("%d",&option);


    if(option==1)
    {
    int n;
    printf("Enter position to insert node ");
    scanf("%d",&n);

    b=insertnode(b,n);
    traverse(b);
    }
    else if (option==2)
    {
        int m;
        printf("Enter position to delete node ");
        scanf("%d",&m);

        b=deletenode(b,m);
        traverse(b);
    }
    else if (option==3)
    {
        b=reverse(b);
        traverse(b);
    }
    

}
struct players *createlinklist()
{
    struct players *p,*q,*firstnode;
    char x[5];
    p=(struct players *)malloc(sizeof(struct players));
    firstnode=p;
    printf("Enter jercy number - ");
    scanf("%d",&p->jnum);
    printf("Enter name - ");
    scanf("%s",p->name);

    while(1)
    {
        printf("Do you want to continue ? yes OR no - ");
        scanf("%s",x);
        if(strcmp(x,"no")==0)
            break;
    
    q=(struct players *)malloc(sizeof(struct players));
    printf("Enter jercy number - ");
    scanf("%d",&q->jnum);
    printf("Enter name - ");
    scanf("%s",q->name);

    p->next=q;
    p=q;
    }
    p->next=0;
    return firstnode;
} 
void traverse(struct players *z)
{
    while(z!=0)
    {
        printf("%d %s\n",z->jnum,z->name);
        z=z->next;
    }
}
struct players *insertnode(struct players *z,int pos)
{
    struct players *q,*m,*temp=z;
    int i;
    if(pos==1)
    {
        q=(struct players *)malloc(sizeof(struct players));
        q->next=z;
    printf("Enter jercy number - ");
    scanf("%d",&q->jnum);
    printf("Enter name - ");
    scanf("%s",q->name);
        return q;
    }
    else
    {
        for(i=1;i<pos;i++)
        {
            m=z;
            z=z->next;
        }
    q=(struct players *)malloc(sizeof(struct players));
    printf("Enter jercy number - ");
    scanf("%d",&q->jnum);
    printf("Enter name - ");
    scanf("%s",q->name);
        m->next=q;
        q->next=z;

        return temp;
    }

}
struct players *deletenode(struct players *p,int pos)
{   
    struct players *q,*m,*temp=p;
    int i;
    if(pos==1)
    {
        q=p->next;
        free(p);
        return q;
    }
    else
    {
        for(i=1;i<pos;i++)
        {
            m=p;
            p=p->next;
        }
        m->next=p->next;
        free(p);
        return temp;
    }
}
struct players *reverse(struct players *p)
{
    struct players *nextn,*pre=0;
    while(p!=0)
    {
        nextn=p->next;
        p->next=pre;
        pre=p;
        p=nextn;
    }
    return pre;
}