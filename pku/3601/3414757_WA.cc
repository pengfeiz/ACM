#include <iostream>
#include <math.h>
using namespace std;

const __int64 maxn=101;

__int64 a[maxn],c[101];

int main()
{
	__int64 n,m,p,i,j;
	while(scanf("%I64d%I64d",&n,&m)!=EOF)
	{
		c[0]=1%m;
		for(i=1;i<100;i++)
			c[i]=(c[i-1]*2)%m;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		if(a[n-1]>1)
		{
			a[n]=a[n-1]-1;
			a[n-1]=1;
			n++;
		}
		p=j=0;
		for(i=n-1;i>=0;i--)
		{
			p=(p+a[i]*c[j]%m)%m;
			j++;
		}
		printf("%I64d\n",p);
	}
	return 0;
}
