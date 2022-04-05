#include "stdio.h"
int linearsearch(int [],int,int);
main()
{
    int len;
    printf("Enter the size of the array : ");
    scanf("%d",&len);
    int arr[len];
    printf("Enter the elements of the array - ");
    int n;

    for(int i=0;i<len;i++)
    {
        
        scanf("%d",&n);
        arr[i]=n;
    }
    printf("Enter the element you want to search - ");
    int num;
    scanf("%d",&num);
    int result=linearsearch(arr,len,num);
    if(result==1)
        printf("FOUND");
    else
        printf("NOT FOUND");


}
int linearsearch(int arr[],int len,int num)
{
    
    for(int i=0;i<len;i++)
    {
        if(arr[i]==num)
        {
            return 1;
        }
     
    }
    return 0;
}