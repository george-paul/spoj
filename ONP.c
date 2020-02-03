/*input
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void setZero(char* a, int n)
{
	for(int i=0; i<n; i++)
	{
		a[i]='\0';
	}
}

void main()
{
	char exp[400], stack[400], res[400];
	int e,s,r,T;
	scanf("%d", &T);
	do
	{
		setZero(exp,400);
		setZero(res,400);
		setZero(stack,400);
		scanf("%s", exp);
		e=0;s=0;r=0;
		for(;e<strlen(exp);e++)
		{
			printf("%s  %s\n", stack, res);		//debug
			stack[s]=exp[e];
			if(isalpha(stack[s]))
			{
				res[r]=stack[s];
				r++;
				s--;
				continue;
			}
			if(stack[s]==')')
			{
				s--;
				while(stack[s]!='(')
				{
					res[r]=stack[s];
					r++;
					s--;
				}
				s--;
				continue;
			}
			if(stack[s]=='+'||stack[s]=='-')
			{
				if(stack[s-1]=='*'||stack[s-1]=='/'||stack[s-1]=='^')
					while(stack[s]=='*'||stack[s]=='/'||stack[s]=='^')
					{
						res[r]=stack[s];
						r++;
						s--;
					}
				continue;
			}
			if(stack[s]=='*'||stack[s]=='/')
			{
				if(stack[s-1]=='^')
					while(stack[s]=='^')
					{
						res[r]=stack[s];
						r++;
						s--;
					}
					continue;
			}
			s++;
		}
		T--;
		printf("\nRES = %s\n", res);	//debug
	}while(T>0);
}