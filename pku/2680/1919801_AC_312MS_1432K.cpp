#include <stdio.h>

long num[1001][350];
void dosth(long nn)
{
	long i,j,l=1;
	for(i=2;i<nn;i++)
	{
		num[i][0]=l;
		for(j=1;j<=num[i][0];j++)
			num[i][j]=num[i-1][j]*2;
		if(i%2==0)
			num[i][1]++;
		else
			num[i][1]--;
		for(j=1;j<=num[i][0];j++)
		{
			num[i][j+1]+=num[i][j]/10;
			num[i][j]=num[i][j]%10;
		}
		if(num[i][l+1]==1)
		{
			num[i][0]++;
			l++;
		}
	}
}
int main()
{
	long n=350,i,j,nn=1001,q;
	for(i=0;i<nn;i++)
		for(j=0;j<n;j++)
			num[i][j]=0;
	dosth(nn);
	while(scanf("%d",&q)!=EOF)
	{
		if(q==1)
			printf("0");
		else
		{
			for(i=num[q][0];i>0;i--)
				printf("%d",num[q][i]);
		}
		printf("\n");
	}
	return 0;
}
