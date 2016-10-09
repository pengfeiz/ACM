#include <iostream>
#include <string.h>
using namespace std;
#define MAX 5000
#define AC 1000000000
__int64 d[18][MAX];

__int64 max(__int64 x,__int64 y)
{
	return x>y?x:y;
}

void add(__int64 a[],__int64 b[],__int64 c[])
{
	__int64 i,l;
	l=max(a[0],b[0]);
	c[0]=l;
	for(i=1;i<=l;i++)
		c[i]=a[i]+b[i];
	for(i=1;i<l;i++)
		if(c[i]>=AC)
		{
			c[i+1]+=c[i]/AC;
			c[i]%=AC;
		}
	if(c[c[0]]>=AC)
	{
		c[c[0]+1]=c[c[0]]/AC;
		c[0]++;
	}
}

void multipy(__int64 a[],__int64 b[],__int64 c[])
{
	int i,j;
	c[0]=a[0]+b[0];
	for(i=1;i<=a[0];i++)
		for(j=1;j<=b[0];j++)
			c[i+j-1]+=b[j]*a[i];
	for(i=1;i<=c[0];i++)
		if(c[i]>=AC)
		{
			c[i+1]+=c[i]/AC;
			c[i]%=AC;
		}
	if(c[c[0]]==0)
		c[0]--;
}

int main()
{
	__int64 i,e[MAX],f[3]={1,1},n,ee[MAX],j;
	memset(d,0,sizeof(d));
	memset(e,0,sizeof(e));
	d[0][0]=1;
	d[0][1]=2;
	d[1][0]=1;
	d[1][1]=3;
	scanf("%I64d",&n);
	ee[0]=1;
	ee[1]=2;
	for(i=2;i<n;i++)
	{
		multipy(ee,d[i-1],e);
		add(e,f,d[i]);
		memcpy(ee,e,sizeof(e));
		memset(e,0,sizeof(e));
	}
	for(j=1;j<=n;j++)
	{
		printf("%I64d",d[j-1][d[j-1][0]]);
		for(i=d[j-1][0]-1;i>0;i--)
			printf("%9I64d",d[j-1][i]);
		printf("\n");
	}
	return 0;
}
