#include <iostream>
#include <math.h>
using namespace std;
#define MAX 1121

int a[MAX][15];

bool prime(int x)
{
	int i;
	for(i=2;i<=sqrt(x*1.0);i++)
		if(x%i==0)
			return false;
	return true;
}

int c[MAX];

int main()
{
	int i,j,n,m,k;
	c[0]=c[1]=false;
	for(i=2;i<MAX;i++)
		c[i]=prime(i);
	while(scanf("%d%d",&n,&m),n||m)
	{
		memset(a,0,sizeof(a));
		a[0][0]=1;
		for(i=2;i<=n;i++)
		{
			if(c[i])
			{
				for(j=n-i;j>=0;j--)
					for(k=m-1;k>=0;k--)
						if(a[j][k])
							a[j+i][k+1]+=a[j][k];
			}
		}
		printf("%d\n",a[n][m]);
	}
	return 0;
}