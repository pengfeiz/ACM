#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX 10
struct gao
{
	double x,y;
}a[MAX];

bool com(gao a,gao b)
{
	if(a.x<b.x)
		return true;
	else if(a.x==b.x&&a.y<b.y)
		return true;
	return false;
}

int main()
{
	double r,b;
	int n,t,i,k=0,q;
	while(scanf("%d%lf",&n,&r)&&(n||r))
	{
		b=-9999999999;
		k++;
		t=q=0;
		printf("Case %d: ",k);
		for(i=0;i<n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		sort(a,a+n,com);
		for(i=0;i<n;i++)
		{
			if(a[i].y>r)
			{
				t=1;
				break;
			}
			if(pow(fabs(a[i].x-b),2)+pow(a[i].y,2)>r*r)
			{	
				q++;
				b=a[i].x+sqrt(r*r-pow(a[i].y,2));
			}
		}
		if(t)
			printf("-1\n");
		else
			printf("%d\n",q);
	}
	return 0;
}

