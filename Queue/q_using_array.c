//Queue implementation using Array
#include "stdio.h"
int q[5];
int f=-1,r=-1;
void push(int);
int pop();
int full();
int empty();
main()
{   int choice,data;
    
    do
    {
        printf("Enter choice to do operations in a queue");
        printf("\n 1 to push");
        printf("\n 2 to pop");
        printf("\n 0 to stop\n");
        scanf("%d",&choice);
            if(choice==1)
            {
                if(full())
                {
                    printf("The queue is full");
                    continue;
                }
                printf("Enter data to push  ");
                scanf("%d",&data);
                push(data);
                    
            }
            if(choice==2)
            {
                if(empty())
                {
                    printf("Queue is empty now\n");
                    continue;
                }
                data=pop();
                printf("%d\n",data);
            }
    }while(choice!=0);
}
void push(int x)
{
    if(r==-1)
    {
        f=0;
        r=0;
    }
    q[r]=x;
    r++;
}
int pop()
{
    int k=q[f];
    f++;
    return k;
}
int full()
{
    if(r==5)
        return 1;
    else
        return 0;
}
int empty()
{
    if(f==r)
    {
        f=r=-1;
        return 1;
    }
    else
        return 0;
}
