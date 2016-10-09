#include<iostream>
#include <algorithm>
using namespace std;

__int64 b[100][2];

int main()
{
	__int64 i,n,j,t,x;
	scanf("%I64d",&n);
	x=0;
	i=0;
	j=2;
	t=1;
	while(i<j-1)
	{
		if(t<n)
		{
			t+=j*j;
			j++;
		}
		else if(t>n)
		{
			t-=i*i;
			i++;
		}
		else
		{
			b[x][0]=i;
			b[x][1]=j;
			x++;
			t-=i*i;
			i++;
		}
	}
	printf("%I64d\n",x);
	for(i=0;i<x;i++)
	{
		printf("%I64d",b[i][1]-b[i][0]);
		for(j=b[i][0];j<b[i][1];j++)
			printf(" %I64d",j);
		printf("\n");
	}
	return 0;
}
				
