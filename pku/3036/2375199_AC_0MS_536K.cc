#include <iostream>
using namespace std;
long long a[21][50][50];

long long dp(long long i,long long j,long long k)
{
	if(a[i][j][k]!=-1)
		return a[i][j][k];
	a[i][j][k]=0;
	a[i][j][k]+=dp(i-1,j+1,k);
	a[i][j][k]+=dp(i-1,j-1,k);
	a[i][j][k]+=dp(i-1,j,k+1);
	a[i][j][k]+=dp(i-1,j,k-1);
	a[i][j][k]+=dp(i-1,j+1,k+1);
	a[i][j][k]+=dp(i-1,j-1,k-1);
	return a[i][j][k];
}

int main()
{
	long long n,t,i,j,k;
	for(i=0;i<50;i++)
		for(j=0;j<50;j++)
			a[0][i][j]=0;
	a[0][20][20]=1;
	for(k=1;k<21;k++)
		for(i=0;i<50;i++)
			for(j=0;j<50;j++)
				a[k][i][j]=-1;
	for(i=1;i<21;i++)
		dp(i,20,20);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",a[n][20][20]);
	}
	return 0;
}
