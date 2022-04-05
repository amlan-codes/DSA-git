#include "stdio.h"
#include "string.h"
int precedence(char);
main()
{
    char inf[30];
    printf("Enter infix expresssion : ");
    scanf("%s",inf);
    //char res[30];
    char opr[30];
    int i,j=-1;
//traverse the infix expression
    for(i=0;i<strlen(inf);i++)
    {
        
        if(inf[i]=='(')
        {
            j++;
            opr[j]=inf[i];//push
        }
        else
        if(inf[i] >=48 && inf[i]<=57)//ASCII value of 1 is 49 and 9 is 57
            {
                printf("%d",inf[i]-48);
            }
        else
        if(inf[i]==')')
            {
                j++;
            while(inf[j]!='(')
                printf("%s",inf[i]);
                j--;
            }
        else
        {
            if(j==-1)
            {
                j++;
                opr[j]=inf[i];
                //printf("%s",opr[j]);
            }
            else
            {   
                char a=opr[j];
                int c=precedence(a);
                char b=inf[i];
                int d=precedence(b);
                while(j!=-1)
                {
                    
                    if(c<d)
                    {
                        j++;
                        opr[j]=inf[i];
                        break;
                    }
                    else
                    {
                        printf("%c",opr[j]);
                        opr[j]=inf[i];
                         break;
                    }
                   
                }
               
            }
        }
    }
    while(j!=-1)
    {   
        
        printf("%c",opr[j]);
        j--;
        
    }

}
int precedence(char m)
{
    switch(m)
    {
        case '+':
		case '-':
			return 5;
		case '*':
		case '/':
		case '%':
			return 6;
    }
}