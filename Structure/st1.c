#include "stdio.h"
struct student {
    int roll;
    char name[30];
    char branch[20];
};
//roll name and branch are all data members
main(){
    struct student p={34,"Amlan Mohanty","Cse"};
    struct student p1={35,"Akash gupta","Csit"};
// here p and p1 are variables of the structue student and hence are structure variables
    printf("%d %s %s \n",p.roll,p.name,p.branch);
    printf("%d %s %s",p1.roll,p1.name,p1.branch);
}
