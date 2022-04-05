#include "stdio.h"
main()
{
    int x[]={10,20,30,40,50};
    int large=x[0];

    for(int i =1;i<5;i++)
    {
        if(large<x[i])
            large=x[i];
        
    }
    printf("%d ",large);
   
}
