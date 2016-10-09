#include <iostream>
#include <math.h>
using namespace std;

const int maxn=101;

int a[maxn],c[101];

int main()
{
	int n,m,p,i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
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
		printf("%d\n",p);
	}
	return 0;
}
