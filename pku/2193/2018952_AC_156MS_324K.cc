#include <iostream>
#include <math.h>
using namespace std;
__int64 m,t,a[2001][11];
int main()
{
	__int64 n,l,i,j,k,p=0;
	scanf("%I64d",&l);
	memset(a,0,sizeof(a));
	for(i=1;i<=2000;i++)
		a[i][1]=1;
	for(i=2;i<=2000;i++)
		for(j=1;j<=10;j++)
		{
			t=0;
			for(k=i/2;k>0;k--)
				a[i][j]+=a[k][j-1];
		}
	while(l-->0)
	{
		t=0;
		p++;
		scanf("%I64d%I64d",&n,&m);
		for(k=1;k<=m;k++)
			t+=a[k][n];
		printf("Case %I64d: n = %I64d, m = %I64d, # lists = %I64d\n",p,n,m,t);
	}
	return 0;
}
		