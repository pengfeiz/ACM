#include <iostream>
using namespace std;
#define MAX 13

__int64 a[MAX][1<<MAX],n,m;
__int64 b[MAX][MAX];
__int64 t,c[1<<MAX],q,p;

bool judge(__int64 x)
{
	bool y=false;
	while(x)
	{
		if(x&1)
		{
			if(y)
				return false;
			y=true;
		}
		else
			y=false;
		x=x>>1;
	}
	return true;
}

void build()
{
	__int64 i;
	q=0;
	for(i=0;i<p;i++)
		if(judge(i))
			c[q++]=i;
}

int main()
{
	__int64 i,j,k;
	t=0;
	scanf("%I64d%I64d",&n,&m);
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%I64d",&b[i][j]);
	p=1<<n;
	build();
	memset(a,0,sizeof(a));
	a[0][0]=1;
	for(i=1;i<=m;i++)
	{
		for(j=0;j<q;j++)
		{
			for(k=1;k<=n;k++)
				if( c[j]&(1<<(k-1)) && !b[k][i])
					break;
			if(k<=n)
				continue;
			for(k=0;k<q;k++)
			{
				if(c[j]&c[k])
					continue;
				if(j)
					t+=a[i-1][c[k]];
				if(t>100000000)
					t%=100000000;
				a[i][c[j]]+=a[i-1][c[k]];
			}
		}
	}
	printf("%I64d\n",t+1);
	return 0;
}