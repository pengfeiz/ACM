#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 1048576

int a[MAX],n,b[MAX],c[MAX],t;

int dosth(int x,int m)
{
	int q;
	if(2*x>=a[0])
	{
		c[t]=a[x]-m;
		t++;
		return m;
	}
	q=dosth(2*x,m);
	q=dosth(2*x+1,q+1);
	c[t]=a[x]-q;
	t++;
	return q;
}

bool com(int a,int b)
{
	return a<b;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,*num;
	scanf("%d",&n);
	a[0]=pow(2,n);
	for(j=0,i=1;j<n;j++)
		for(k=0;k<pow(2,j);k++)
			scanf("%d",&a[i++]);
	t=1;
	dosth(1,0);
	c[0]=-999999999;
	for(i=1,k=0;i<a[0];i++)
	{
		if(c[i]>=b[k])
		{
			k++;
			b[k]=c[i];
		}
		else
		{
			num=upper_bound(b,b+k,c[i],com);
			*num=c[i];
		}
	}
	printf("%d\n",a[0]-k-1);
	return 0;
}
	