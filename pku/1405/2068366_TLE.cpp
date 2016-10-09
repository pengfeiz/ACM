#include <iostream>
#include <string.h>
using namespace std;
#define MAX 50000
int d[18][MAX];

int max(int x,int y)
{
	return x>y?x:y;
}

void add(int a[],int b[],int c[])
{
	int i,l;
	l=max(a[0],b[0]);
	c[0]=l;
	for(i=1;i<=l;i++)
		c[i]=a[i]+b[i];
	for(i=1;i<l;i++)
		if(c[i]>=10)
		{
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
	if(c[c[0]]>=10)
	{
		c[c[0]+1]=c[c[0]]/10;
		c[0]++;
	}
}

void multipy(int a[],int b[],int c[])
{
	int i,j;
	c[0]=a[0]+b[0];
	for(i=1;i<=a[0];i++)
		for(j=1;j<=b[0];j++)
			c[i+j-1]+=b[j]*a[i];
	for(i=1;i<=c[0];i++)
		if(c[i]>=10)
		{
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
	if(c[c[0]]==0)
		c[0]--;
}

int main()
{
	int i,e[MAX],f[3]={1,1},n,ee[MAX];
	memset(d,0,sizeof(d));
	memset(e,0,sizeof(e));
	d[0][0]=1;
	d[0][1]=2;
	d[1][0]=1;
	d[1][1]=3;
	scanf("%d",&n);
	ee[0]=1;
	ee[1]=2;
	for(i=2;i<n;i++)
	{
		multipy(ee,d[i-1],e);
		add(e,f,d[i]);
		memcpy(ee,e,sizeof(e));
		memset(e,0,sizeof(e));
	}
	for(i=d[n-1][0];i>0;i--)
		printf("%d",d[n-1][i]);
	printf("\n");
	return 0;
}
