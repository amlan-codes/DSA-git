//using linklist
#include "stdlib.h"
#include "stdio.h"
void push(int);
int pop();
int full();
int empty();
	struct queue
	{
		int data;
		struct queue *link;
	};
	struct queue *r=0,*f=0,*temp;
main()
{
	int n;
	int data;
	do
	{
		printf("\n1 for push");
		printf("\n2 for pop");
		printf("\n0 to stop");
		printf("\nEnter choice ");
		scanf("%d",&n);
		if(n==1)
		{
			printf("enter data to push");
			scanf("%d",&data);
			push(data);
		}
		else
		if(n==2)
		{
			if(empty())
			{
				printf("queue is empty\n");
				continue;
			}
			data=pop();
			printf("%d\n",data);
		}
	}while(n!=0);	
}
void push(int data)
{
	if(r==0)
	{
		r=(struct queue *)malloc(sizeof(struct queue));
		if(r==0)
		{
			printf("Insufficient memory");
			return;
		}
		r->data=data;
		r->link=0;
		f=r;
	}
	else
	{
		temp=(struct queue *)malloc(sizeof(struct queue));
		if(temp==0)
		{
			printf("Insufficient memory");
			return;
		}
		r->link=temp;
		r=temp;
		r->data=data;
		r->link=0;
			
	}
}
int pop()
{
	int k=f->data;
	temp=f->link;
	free(f);
	f=temp;
	return k;	

}

int full()
{
}
int empty()
{
	if(f==0)
	{
		r=0;
		return 1;
	}
	else
		return 0;
}