#include "stdio.h"
#include "stdlib.h"
struct queue
{
    int data;
    struct queue *link;
};
void push(int);
int pop();

int data,z=0;
struct queue *f=0,*r=0,*temp;
main()
{   
    int choice;
    do
    {
    printf("Enter the desired operation you want to do in the Queue : \n");
    printf("1 for push\n");
    printf("2 for pop\n");
    printf("0 to stop \n");
    scanf("%d",&choice);

    if(choice == 1)
    {
        printf("Enter data to push - ");
        int data;
        scanf("%d",&data);
        push(data);

    }
    else
    if(choice==2)
    {   
        if(z==0)
        {
            printf("Cant POP. Queue is empty !!!");
        }
        int n=pop();
        printf("Poped element- %d\n",n);
    }
   
    }while(choice !=0);
    

}
void push(int data)
{
    if(r==0)
    {
        r=(struct queue*)malloc(sizeof(struct queue));
        r->data=data;
        r->link=0;
        f=r;
        z++;
    }
    else
    {
        temp=(struct queue*)malloc(sizeof(struct queue));
        r->link=temp;
        r=temp;
        temp->data=data;
        temp->link=0;
        z++;
    }
}
int pop()
{   
   
    int k=f->data;
    temp=f->link;
    free(f);
    f=temp;
    z--;
    return k;
}

