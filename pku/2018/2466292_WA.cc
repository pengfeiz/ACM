#include <iostream>
#include <math.h>
using namespace std;

#define MAX 100001
#define esp 1e-8

int a[MAX],n,f;
double d[MAX];

bool judge(double mid)
{
	int i;
	double x;
	d[0]=0;
	x=0;
	for(i=0;i<n;i++)
	{
		x+=a[i]*1.0-mid;
		if(i+1>=f&&x>d[i+1-f]-esp)
			return true;
		if(a[i]*1.0>mid)
			d[i+1]=d[i];
		else
			d[i+1]=x;
/*		if(x>d[i])
			d[i+1]=d[i];
		else
			d[i+1]=x;*/
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
