#include "stdio.h"

void push() ;
int pop();
int full();
int empty();

int x[5];
int i=-1;

main()
{
    int n,data;


do
{
printf("\n 1 for push");
printf("\n 2 for pop");
printf("\n 0 to stop");

printf("\nchoose your option");
scanf("%d",&n);

if(n==1){
    if(full()){
        printf("The stack is full");
        continue;
    }
printf("Enter the data ");
scanf("%d",&data);
push(data);
}
else if(n==2){
    if(empty()){
        printf("The stack is empty");
        continue;
    }
data=pop();
printf("%d",data);
}

}while(n!=0);

}
void push(int data){
    i++;
    x[i]=data;
}
int pop(){
    int k=x[i];
    i--;
    return k;

}
int full(){
    if(i>=4)
        return 1;
    else 
        return 0;
}
int empty(){
    if(i==-1)
        return 1;
    else 
        return 0;
}
