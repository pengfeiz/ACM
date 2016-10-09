#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1005
#define MAX2 5000
int a[MAX],m;

struct gao
{
	int a,b;
}c[MAX2];

int main()
{
	int n,i,tt;
	scanf("%d",&n);
	tt=m=0;
	memset(c,0,sizeof(c));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(i=n-1;i>2;i-=2)
	{           
		if(2*a[1]>=a[0]+a[i-1]) 
		{
			tt+=2*a[0]+a[i-1]+a[i];
			c[m].b=a[i];
			c[m++].a=a[0];
			c[m++].a=a[0];
			c[m].b=a[i-1];
			c[m++].a=a[0];
			c[m++].a=a[0];
		}
		else   
		{
			tt+=2*a[1]+a[0]+a[i];
			c[m].b=a[1];
			c[m++].a=a[0];
			c[m++].a=a[1];
			c[m].b=a[i];
			c[m++].a=a[i-1];
			c[m++].a=a[0];
		}
	}
	if(i==2)
	{
		tt+=a[0]+a[1]+a[2];
		c[m].b=a[2];
		c[m++].a=a[1];
		c[m++].a=a[1];
		c[m].b=a[1];
		c[m++].a=a[0];
	}
	else if(i==1)
	{
		tt+=a[1];
		c[m].b=a[1];
		c[m++].a=a[0];
	}
	else if(i==0)
	{
		tt+=a[0];
		c[m++].a=a[0];
	}
	printf("%d\n",tt);
	for(i=0;i<m;i++)
	{
		printf("%d",c[i].a);
		if(c[i].b)
			printf(" %d",c[i].b);
		printf("\n");
	}
	return 0;
}