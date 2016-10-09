#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define esp 1e-7
#define MAX 10001

double ll(double x)
{return x*x;}

struct gao
{
	double x,y;
}a[MAX];

int n;


bool com(gao a,gao b)
{
	if(fabs(a.x-b.x)>esp)
		return a.x<b.x;
	return a.y<b.y;
}
double dis(gao a,gao b)
{return ll(a.x-b.x)+ll(a.y-b.y);}

int main()
{
	int i,tt;
	scanf("%d",&tt);
	while(tt--)
	{
		gao p;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		sort(a,a+n,com);
		if(n&1)
		{
			for(i=0;i<n/2;i++)
				if(fabs(dis(a[i],a[n/2])-dis(a[n-i-1],a[n/2]))>esp)
					break;
			if(i<n/2)
				printf("no\n");
			else
				printf("yes\n");
		}
		else
		{
			p.x=(a[0].x+a[n-1].x)/2;
			p.y=(a[0].y+a[n-1].y)/2;
			for(i=0;i<n/2;i++)
				if(fabs(dis(a[i],p)-dis(a[n-i-1],p))>esp)
					break;
			if(i<n/2)
				printf("no\n");
			else
				printf("yes\n");
		}
	}
//	system("pause");
	return 0;
}
