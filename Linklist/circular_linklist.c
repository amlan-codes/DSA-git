void circular(struct student *p)
{
    struct student *q=p;
    while(p->link != 0)
    {
        printf("%d %s \n",p->roll,p->name);
        p=p->link;
    }
    printf("%d %s \n",p->roll,p->name);
}