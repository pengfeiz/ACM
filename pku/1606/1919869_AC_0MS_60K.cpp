#include <stdio.h>     
int main()   
{   
	int a,b,g,i,j;   
	while(scanf("%d%d%d",&a,&b,&g)!=EOF)   
	{   
		i=0,j=1;    
        while(a*i<g||(a*i-g)%b)   
		{   
			i++;   
			printf("fill A\n");   
			printf("pour A B\n");   
			if(a*i>j*b)   
			{   
				printf("empty B\n");   
				printf("pour A B\n");   
				j++;   
			}   
		}   
		printf("success\n");   
	}   
	return 0;
 }