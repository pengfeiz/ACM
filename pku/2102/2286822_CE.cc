#include <iostream>
using namespace std;


#define MAX 126
const __int64 mol=100000000000000000;


__int64 a[MAX][MAX][MAX],c[3],n,b[MAX],e[MAX];


void init()
{
	__int64 i;
	scanf("%I64d",&n);
	scanf("%I64d%I64d%I64d",&c[0],&c[1],&c[2]);
	e[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%I64d",&b[i]);
		e[i]=e[i-1]+b[i];
	}
	b[0]=0;
}


void solve()
{
	__int64 k,i,j,p,ii,jj,q;
	memset(a,0,sizeof(a));
	a[0][0][0]=1;
	for(k=1;k<=n;k++)
	{
		for(ii=0;ii<=c[0];ii++)
		{
			for(jj=0;jj<=c[1];jj++)
			{
				q=e[k]-ii-jj;
				if(q>c[2])
					break;
				for(i=0;i<=b[k];i++)
				{
					p=b[k]-i;
					for(j=0;j<=p;j++)
					{
						if(b[k]-i-j+q>c[2])
							break;
						a[k][ii+i][jj+j]+=a[k-1][ii][jj];
						if(a[k][ii+i][jj+j]>mol)
							a[k][ii+i][jj+j]%=mol;
					}
				}
			}
		}
	}
	printf("%I64d\n",a[k][c[0]][c[1]]);
}


int main()
{
	init();
	solve();
	return 0;
}