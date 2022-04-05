//create two polynomials and add them
#include "stdio.h"
#include "stdlib.h"
struct math
{
    int cof;
    int exp;
    struct math *link;
};
struct math *createpoly();
struct math *addpoly(struct math *,struct math *);
void traverse(struct math *);
main()
{

}
struct math *createpoly()
{
    struct math *p,*temp,*q;
    p=(struct math *)malloc(sizeof(struct math));
    temp=p;
    
    
}