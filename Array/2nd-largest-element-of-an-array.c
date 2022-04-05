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
    
    int large2=x[0];
   
    for(int j=1;j<5;j++)
    {
        if (large2<x[j] && large2 < large)
            if(large2 == large)
            large2=x[j];
    }

    printf("%d ",large2);

}