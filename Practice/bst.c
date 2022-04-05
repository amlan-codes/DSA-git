#include "stdio.h"
#include "stdlib.h"
struct tree
{
    struct tree *left;
    struct tree *right;
    int data;
};
struct tree *create_bst(struct tree*,int);
void inorder (struct tree*);
main()
{
    int x[8]={10,90,11,2,3,77,100,15};
    struct tree *root=0;
    int i;
    for(i=0;i<8;i++)
    {
        root=create_bst(root,x[i]);
    }
    inorder(root);
    printf("\n");
}
struct tree *create_bst(struct tree*p,int n)
{
    if(p==0)
    {
        p=(struct tree*)malloc(sizeof(struct tree));
        p->left=0;
        p->data=n;
        p->right=0;
    }
    else
    if(n>p->data)
    {
        p->right=create_bst(p->right,n);
    }
    else
        p->left=create_bst(p->left,n);


return p;
  
}
void inorder(struct tree *p)
{
    if(p!=0)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}


