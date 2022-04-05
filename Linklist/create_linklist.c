#include "stdio.h"
#include "stdlib.h"
struct student
{
    int roll;
    char name[20];
    struct student *link;
};
main()
{
    struct student *p,*q,*temp;
    p=(struct student *)malloc(sizeof(struct student));
    temp=p;
    char x[5];
    while(1)
    {
        printf("Do you want to continue ? yes OR no ");
        scanf("%s",x);
        if(strcmp(x,"no")==0)
            break;
        
    q=(struct student *)malloc(sizeof(struct student));
    p->link=q; //adress of q is stored in p(in last block out of 3 blocks of p) or we can say we joint p and q
    p=q; ;//p now points to q because if again yes is selected a new q will be created and the only reference to this node will be p
    }
    p->link=0;//refers to the last node and adress stored in last node is null
}

//linux cmd to check the number of blocks created using malloc 
//valgrind --tool=memcheck ./a.out