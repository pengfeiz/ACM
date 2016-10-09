#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10004


struct gao
{
	int x,y;
}a[MAX];
int n,x[MAX],y[MAX];

int main()
{
	int i,t,q,num,minn,x1,x2,y1,y2;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		x[i]=a[i].x;
		y[i]=a[i].y;
	}
	sort(x,x+n);
	sort(y,y+n);
	t=0;
	if(n%2)
	{
		for(i=0;i<n;i++)
		{
			t+=abs(x[i]-x[n/2]);
			t+=abs(y[i]-y[n/2]);
		}
		q=num=0;
		minn=0x4fffffff;
		for(i=0;i<n;i++)
			if(x[i]<x[n/2])
				q++;
		if(t-2*q+n<minn)
		{
			minn=t-2*q+n;
			num=1;
		}
		else if(t-2*q+n==minn)
			num++;
		q=0;
		for(i=0;i<n;i++)
			if(y[i]<y[n/2])
				q++;
		if(t-2*q+n<minn)
		{
			minn=t-2*q+n;
			num=1;
		}
		else if(t-2*q+n==minn)
			num++;
		q=0;
		for(i=0;i<n;i++)
			if(x[i]<=x[n/2])
				q++;
		if(t+2*q-n<minn)
		{
			minn=t+2*q-n;
			num=1;
		}
		else if(t+2*q-n==minn)
			num++;
		q=0;
		for(i=0;i<n;i++)
			if(y[i]<=y[n/2])
				q++;
		if(t+2*q-n<minn)
		{
			minn=t+2*q-n;
			num=1;
		}
		else if(t+2*q-n==minn)
			num++;
		printf("%d %d\n",minn,num);
	}
	else
	{
		for(i=0;i<n;i++)
		{
			t+=abs(x[i]-x[n/2]);
			t+=abs(y[i]-y[n/2]);
		}
		x1=x[n/2-1];
		y1=y[n/2-1];
		x2=x[n/2];
		y2=y[n/2];
		num=x2-x1+1;
		num*=y2-y1+1;
		for(i=0;i<n;i++)
			if(a[i].x<=x2&&a[i].x>=x1&&a[i].y<=y2&&a[i].y>=y1)
				num--;
		printf("%d %d\n",t,num);
	}
	return 0;
}
