#include <iostream>
#include <math.h>
using namespace std;

#define MAX 100001
#define esp 1e-8

int a[MAX],n,f;

bool judge(double mid)
{
	int i,q;
	double x;
	q=-1;
	x=0;
	for(i=0;i<n;i++)
	{
		if(x<-esp)
		{
			q=i-1;
			x=0;
		}
		x+=a[i]*1.0-mid;
		if(i-q>=f&&x>-esp)
			return true;
	}
	q=n;
	x=0;
	for(i=n-1;i>=0;i--)
	{
		if(x<-esp)
		{
			q=i+1;
			x=0;
		}
		x+=a[i]*1.0-mid;
		if(q-i>=f&&x>-esp)
			return true;
	}
	return false;
}

int main()
{
	int i;
	scanf("%d%d",&n,&f);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	double a,b,mid;
	a=0;
	b=2000;
	while(b-a>esp)
	{
		mid=(a+b)/2;
		if(judge(mid))
			a=mid;
		else
			b=mid;
	}
	b+=10*esp;
	printf("%d\n",int(b*1000));
	return 0;
}
