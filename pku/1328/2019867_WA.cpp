#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX 1000

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
	int n,t,i,k=0,q,j;
	while(scanf("%d%lf",&n,&r)&&(n||r))
	{
		b=999999999999;
		k++;
		t=q=0;
		printf("Case %d: ",k);
		for(i=0;i<n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		sort(a,a+n,com);
		for(i=0;i<n;i++)
			if(a[i].y>r)
				break;
		if(i<n)
		{
			printf("-1\n");
			continue;
		}
		for(i=0;i<n;i++)
		{
			if(pow(a[i].x-b,2)+pow(a[i].y,2)>r*r)
			{
				b=999999999999;
				q++;
				for(j=i;j<n;j++)				
				{
					if(a[j].x+sqrt(r*r-pow(a[j].y,2))<b)
						b=a[j].x+sqrt(r*r-pow(a[j].y,2));
				}
			}
		}
		printf("%d\n",q);
	}
	return 0;
}

