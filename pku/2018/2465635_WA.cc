#include <iostream>
#include <math.h>
using namespace std;

#define MAX 100001
#define esp 1e-10

int a[MAX],n,f;
double c[MAX];

bool judge(double mid)
{
	int i;
	double x=0;
	c[0]=0;
	for(i=0;i<n;i++)
	{
		x+=a[i]*1.0-mid;
		if(i-f+1>=0&&x-c[i-f+1]>-esp)
			return true;
		if(x>c[i])
			c[i+1]=c[i];
		else
			c[i+1]=x;
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
	b=999999;
	while(b-a>esp)
	{
		mid=(a+b)/2;
		if(judge(mid))
			a=mid;
		else
			b=mid;
	}
	printf("%.0lf\n",a*1000);
	return 0;
}
