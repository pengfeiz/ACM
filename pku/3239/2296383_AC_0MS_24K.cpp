#include <stdio.h>
#include <algorithm>
int	n;

void slove(int a,int b)
{
	int	i;	
	for(i=a;i<=b;i+=2)
		printf(" %d",i);
}

void dosth()
{
	int	t;
	t=n/2;	
	if((n%6!=2)&&(n%6!=3))
	{
		printf("2");
		slove(4,n);
		slove(1,n);
		printf("\n");
	}
	else
	{
		printf("%d",t);
		if(n&1)
		{
			if(t&1)
			{
				slove(t+2,n-2);
				slove(1,t-2);
				slove(t+3,n-1);
				slove(2,t+1);
				printf("%d\n",n);
			}
			else
			{
				slove(t+2,n-1);
				slove(2,t-2);
				slove(t+3,n-2);
				slove(1,t+1);
				printf("%d\n",n);
			}
		}
		else
		{
			if(t&1)
			{
				slove(t+2,n-1);
				slove(1,t-2);
				slove(t+3,n);
				slove(2,t+1);
				printf("\n");
			}
			else
			{
				slove(t+2,n);
				slove(2,t-2);
				slove(t+3,n-1);
				slove(1,t+1);
				printf("\n");
			}
		}
	}
}

int main()
{
	while(scanf("%d\n",&n),n)
		dosth();
	return 0;
}