#include <stdio.h>
#include <string.h>
#define MAX 240

__int64 a[MAX][MAX];

int main()
{
	__int64 n,i,j,k,sum;
	memset(a,0,sizeof(a));
	for(i=1;i<MAX;i++)
	{
		a[i][0]=a[i][i]=1;
		if(!(i%2))
			a[i][i/2]=1;
	}
	for(i=2;i<MAX;i++)
	{   
		for(j=1;j<=i/2;j++)
		{
			sum=i-j*2;
			for(k=j;k<=sum;k++)
				a[i][j]+=a[sum][k];
			a[i][0]+=a[i][j];
		 }
	}
	while(scanf("%I64d",&n),n)
		printf("%I64d %I64d\n",n,a[n][0]);
	return 0;
}