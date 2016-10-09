#include <iostream>
#include <math.h>
using namespace std;

#define MAX 100001
#define esp 1e-7

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
		if(i-f+1>=0&&x-c[i-f+1]>=-esp)
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
	double k;
	scanf("%d%d",&n,&f);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	double a,b,mid;
	a=0;
	b=2000;
	while(b-a>=0.001)
	{
		mid=(a+b)/2;
		if(judge(mid))
			a=mid;
		else
			b=mid;
	}
	k=int(a*1000+1)/1000.0;
	if(k<=b&&judge(k)) 
		a+=0.001;
	printf("%d\n",int(a*1000));
	return 0;
}
