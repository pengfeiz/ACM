#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


#define MAXX 126


__int64 mol;
__int64 a[MAXX][MAXX][MAXX],c[3],n,b[MAXX],e[MAXX],f[MAXX];


void init()
{
	__int64 i;
	mol=(__int64)pow(10,17);
	scanf("%I64d",&n);
	scanf("%I64d%I64d%I64d",&c[0],&c[1],&c[2]);
	e[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%I64d",&b[i]);
		e[i]=e[i-1]+b[i];
	}
	f[n]=b[0]=0;
	for(i=n-1;i>=0;i--)
		f[i]=f[i+1]+b[i+1];
}


void solve()
{
	__int64 k,i,j,ii,t,i1,i2,i3,i4;
	memset(a,0,sizeof(a));
	a[0][0][0]=1;
	if(f[0]!=c[0]+c[1]+c[2])
		return;
	for(k=1;k<=n;k++)
	{
		i1 = ( c[0]>f[k] ? c[0]-f[k]:0 );
		i2 = ( c[0]>e[k] ? e[k]:c[0] );
		for(ii=i1;ii<=i2;ii++)
		{
			i3 = ( f[k]-(c[0]-ii)>c[1] ? 0:c[1]+c[0]-f[k]-ii );
			i4 = ( e[k]-ii>c[1] ? c[1]:e[k]-ii );
			i = ( ii>b[k] ? ii-b[k]:0 );
			t=0;
			for(;i<=ii;i++)
			{
				j = ( i3>b[k]-ii+i ? i3-b[k]+ii-i:0 );
				for(;j<=i3;j++)
				{
					t+=a[k-1][i][j];
					if(t>mol)
						t-=mol;
				}
			}
			for(j=i3;j<=i4;j++)
			{
				a[k][ii][j]=t;
				i = ( ii>b[k] ? ii-b[k]:0 );
				if(j<i4)
				{
					for(;i<=ii;i++)
					{
						t+=a[k-1][i][j+1];
						if(t>mol)
							t-=mol;
						t = ( j>=b[k]-ii+i ? t-a[k-1][i][j+ii-i-b[k]]:t );
						if(t<mol)
							t+=mol;
						if(t>mol)
							t-=mol;
					}
				}
			}
		}
	}
}


int main()
{
	init();
	solve();
	printf("%I64d\n",a[n][c[0]][c[1]]);
	return 0;
}