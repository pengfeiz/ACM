#include <iostream>
#include <math.h>
using namespace std;
#define MAX 1000002
int a[MAX];
int b[MAX];
int c[MAX];
int main()
{
	int i,n,j;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(i=5;i<=sqrt(MAX*1.0);i+=4)
	{
		for(j=i;i*j<MAX;j+=4)
			a[i*j]=1;
	}
	for(i=5;i<=sqrt(MAX*1.0);i+=4)
	{
		if(a[i])
			continue;
		for(j=i;i*j<MAX;j+=4)
		{
			if(a[j])
				continue;
			b[i*j]=1;
		}
	}
	for(i=5;i<MAX;i+=4)
		c[i]=c[i-4]+b[i];
	while(scanf("%d",&n)&&n)
		printf("%d %d\n",n,c[n]);
	return 0;
}

