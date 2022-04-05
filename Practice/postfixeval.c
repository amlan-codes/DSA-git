#include "stdio.h"
#include "string.h"
int pre(char);
main()
{
	char x[30];
	char opd[30],opr[30];
	int i,j=-1,k=-1,a,b,c;
	printf("Enter infix Exp:");
	scanf("%s",x);
	for(i=0;i<strlen(x);i++)
	{
		if(x[i] >=48 && x[i]<=57)
		{
			j++;
			opd[j]=x[i];
		}
		else
		{
			if(k==-1)
			{
				k++;
				opr[k]=x[i];
			}
			else
			{
				a=pre(x[i]);
				b=pre(opr[k]);
				while(k>=0 && a<=b)
				{
					j++;
					opd[j]=opr[k];
					k--;
					if(k==-1)
						break;
					b=pre(opr[k]);
				}		
				k++;
				opr[k]=x[i];	
			}
		}
	}
	while(k>=0)
	{
		j++;
		opd[j]=opr[k];
		k--;
	}
	//evaluation
	
	for(i=0;i<=j;i++)
	{
		if(opd[i]>=48 && opd[i]<=57)
		{
			k++;
			opr[k]=opd[i];
		}
		else
		{
			b=opr[k]-48;
			k--;
			a=opr[k]-48;
			k--;
			if(opd[i]=='+')
				c=a+b;
			else
			if(opd[i]=='-')
				c=a-b;
			else
			if(opd[i]=='/')
				c=a/b;
			else
			if(opd[i]=='*')
				c=a*b;

			k++;
			opr[k]=c+48;
		}
	}	
	//finally
	printf("%d ",opr[k]-48);
}

int pre(char m)
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