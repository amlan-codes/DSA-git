#include "stdio.h"
int bianrysearch(int arr[],int,int,int);
main()
{
    int len;
    printf("Enter the length of the array : ");
    scanf("%d",&len);
    int arr[len];
    int n;
    printf("enter the elements of the array : ");
    for(int i=0;i<len;i++)
    {   
        scanf("%d",&n);
        arr[i]=n;
    }
    printf("Enter the number you wnat to search : ");
    int num;
    scanf("%d",&num);
    int l=0;
    int u=len-1;
    int result=binarysearch(arr,l,u,num);
    if(result==1)
        printf("Found");
    else
        printf("Not found");
}
int binarysearch(int arr[],int l,int u,int num)
{
    int m;
    while(l<=u)
    {
        m=(l+u)/2;
        printf("hi");
        if(arr[m]==num)
        {
            return 1;
        }
        // else
        // if((arr[l] || arr[u])==num)
        // {
        //     return 1;
        // }
        else
        if(num>arr[m])
        {
            l=m+1;
        }
        else
        if(num<arr[m])
        {
            u=m-1;
        }
    }
}