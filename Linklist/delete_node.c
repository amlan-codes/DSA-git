//delete node
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
        
        int m;
        printf("Enter position to delete node ");
        scanf("%d",&m);

        b=deletenode(b,m);
        traverse(b);
    
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