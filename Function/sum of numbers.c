#include "stdio.h"

void sum(){
    int sum=0;
    int n;
    printf("Enter the number ");
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        sum=sum+i;
    }
    printf("The sum of all numbers upto %d is %d ",n,sum);
}
int main()
{
    
    sum();
}